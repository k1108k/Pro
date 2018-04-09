package com.example.k.Honeymoon;

import android.content.Context;
import android.content.Intent;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.util.ArrayList;
import java.util.Iterator;

/**
 * Created by K on 2018/02/28.
 */

public class BattleView extends SurfaceView implements SurfaceHolder.Callback{
    public static Context context;//getResourcesなど他でクラスで必要になった時用
    private Thread thread=null;
    private Canvas canvas;
    private long t1,t2; //１フレームの開始と終了の時間
    public static final char ONE_FRAME_TIME = 16;//バトルスレッドの１フレームミリ秒
    public static long grossTime;//アプリを起動してからの総時間
    public static boolean isTouched = false;//画面をタッチしているかの判定フラグ
    public static double touch_x;//タッチされているX座標
    public static double touch_y;//タッチされているY座標
    public static MainCharacter mc;//姫のインスタンスを入れるフィールド
    public static SubCharacter sc;//護衛のインスタンスを入れるフィールド
    public static BackGround horse;//馬のインスタンスを入れるフィールド
    public static boolean checkGameEnd = false;//ゲームが終了したかを判定するフラグ
    FrameControl scoutCreateFc = new FrameControl();//鳥の生成間隔をコントロールするフィールド
    FrameControl goeiTentouFc = new FrameControl();//護衛が転倒してから立ち上がるまでの時間を
                                                    //コントロールするフィールド
    ArrayList<Scout> scout = new ArrayList<Scout>();//鳥のインスタンスを入れるコレクション
    ArrayList<BackGround> backg = new ArrayList<BackGround>();
    ArrayList<BackGround> mobCharacter = new ArrayList<>();

    public BattleView(Context context){
        super(context);
        this.context = context;
        getHolder().addCallback(this);
    }

    //画面が生成された時に呼び出される
    public void surfaceCreated(SurfaceHolder holder){
        thread = new DrawThread();
        thread.start();
    }

    //画面のサイズが変化した時に呼び出される
    public void surfaceChanged(SurfaceHolder holder,
                               int format, int width, int height){
        BitmapCreate.setDisplaySize(width, height);//ディスプレイサイズを保存
    }

    //画面が削除された時に呼び出される
    public void surfaceDestroyed(SurfaceHolder holder){
        thread = null;
    }

    //タッチされている座標を格納
    public void getTouchPoint(double x, double y) {
        Log.w("BattleView", "タッチしたよ");
        if(checkGameEnd == false) {//乗馬していなければタッチを受け付ける
            touch_x = x;
            touch_y = y;
        }
    }

    //画像を表示するスレッド
    private class DrawThread extends Thread{
        public void run(){
            SurfaceHolder holder = getHolder();
            mc = new MainCharacter(R.drawable.himesama_usiro2);//姫のインスタンス生成
            sc = new SubCharacter(R.drawable.goei_usiro2);//護衛のインスタンス生成
            scout.add(new Scout(R.drawable.tori_hidari2));//鳥のインすんタス生成
            horse = new BackGround(R.drawable.horse2, 4, 9,
                                    BitmapCreate.width / 2 - 400, 50, 10);//馬のインスタンス生成
            //背景のインスタンス生成
            backg.add(new BackGround(R.drawable.floor, 1, 1, 0 , 0));
            backg.add(new BackGround(R.drawable.virgin_road, 5, 2,BitmapCreate.width/2-150,700));
            mobCharacter.add(new BackGround(R.drawable.guest1, 6, 10,
                    BitmapCreate.width/2 - 400, BitmapCreate.height/2));
            mobCharacter.add(new BackGround(R.drawable.guest2, 6, 10,
                    BitmapCreate.width/2 - 450, BitmapCreate.height/2 + 300));
            mobCharacter.add(new BackGround(R.drawable.guest3, 6, 10,
                    BitmapCreate.width/2 + 200, BitmapCreate.height/2 + 100));
            mobCharacter.add(new BackGround(R.drawable.guest4, 6, 10,
                    BitmapCreate.width/2 + 150, BitmapCreate.height/2 + 200));
            mobCharacter.add(new BackGround(R.drawable.sinkan, 6, 10,
                    BitmapCreate.width/2 - 150, BitmapCreate.height - 300));
            scoutCreateFc.setStoppingTime((char)4000);//鳥の生成間隔を４秒に設定
            goeiTentouFc.setStoppingTime((char)2000);//護衛が転倒してから立ち上がるまでの時間を２秒に設定
            touch_x = sc.getCenterPositionX();//護衛の初期座標設定
            touch_y = sc.getCenterPositionY();//

            while(true){
                t1 = System.currentTimeMillis();//１フレームの開始時間を保存
                canvas = holder.lockCanvas();
                Log.d("BattleView", "touchX : "+touch_x+" , "+"touchY"+touch_y);
                if(canvas != null){
                    //鳥の生成
                    if(scoutCreateFc.getJudgeResumption()) {
                        scout.add(new Scout(R.drawable.tori_hidari1));
                    }
                    //鳥の移動
                    for(int i=0; i<scout.size();i++) {
                        scout.get(i).move();
                    }
                    //鳥が画面外に出るか、キャラクターと衝突するとインスタンスを削除する
                    Iterator<Scout> it = scout.iterator();
                    while(it.hasNext()){
                        Scout i = it.next();
                        //鳥が画面外に出た時
                        if(i.getPositionX() < -110
                                ||
                                i.getPositionX() > BitmapCreate.width + 110
                                ||
                                i.getPositionY() < -110
                                ||
                                i.getPositionY() > BitmapCreate.height + 110){
                            it.remove();
                            Log.e("BattleView", "鳥の除去！！！");
                        }
                        //鳥が護衛と衝突した時
                        if (sc.getPositionX() < i.getCenterPositionX() &&
                                sc.getPositionX() + sc.getBitmapWidth() > i.getCenterPositionX()
                                    &&
                                sc.getPositionY() < i.getCenterPositionY() &&
                                    sc.getPositionY() + sc.getBitmapHeight() > i.getCenterPositionY()) {
                                sc.changeIsLiveToFalse();//護衛に鳥が衝突した判定を真にする
                                it.remove();
                        }
                        //鳥が姫と衝突した時
                        if (mc.getPositionX() < i.getCenterPositionX() &&
                                mc.getPositionX() + mc.getBitmapWidth() > i.getCenterPositionX()
                                &&
                                mc.getPositionY() < i.getCenterPositionY() &&
                                mc.getPositionY() + mc.getBitmapHeight() > i.getCenterPositionY()) {
                            mc.changeIsLiveToFalse();//姫に鳥が衝突した判定を真にする
                            context.startActivity(new Intent(context, MainActivity.class));
                        }
                    }


                    //姫と護衛が重なった時にすり抜けないようにする処理
                    //護衛と姫が重なっている状態
                    if (mc.getPositionY() > sc.getPositionY()//護衛より左上に姫
                            && mc.getPositionY() < sc.getPositionY() + sc.getBitmapHeight() / 6
                            &&
                            mc.getPositionX() + mc.getBitmapWidth() < sc.getPositionX() + sc.getBitmapWidth()
                            && mc.getPositionX() + mc.getBitmapWidth() > sc.getPositionX() +
                            sc.getBitmapWidth() - sc.getBitmapWidth() / 6) {
                            sc.av.isCrossOfChar = true;//護衛と姫が重なっているかを判定するフラグを真にする
                            touch_x = mc.getCenterPositionX() + mc.getBitmapWidth() / 5;//この座標まで遠ざける
                            touch_y = mc.getCenterPositionY() - mc.getBitmapHeight() / 5;//
                        Log.w("BattleView", "重なっている1");
                            sc.move();
                            mc.move();
                    }else if (mc.getPositionY() > sc.getPositionY()//護衛より右下に姫
                            && mc.getPositionY() < sc.getPositionY() + sc.getBitmapHeight() / 6
                            &&
                            mc.getPositionX() < sc.getPositionX() + sc.getBitmapWidth() / 6
                            && mc.getPositionX() > sc.getPositionX()) {
                            sc.av.isCrossOfChar = true;
                            touch_x = mc.getCenterPositionX() - mc.getBitmapWidth() / 5;
                            touch_y = mc.getCenterPositionY() - mc.getBitmapHeight() / 5;
                        Log.w("BattleView", "重なっている2");
                            sc.move();
                            mc.move();
                    }else if (sc.getPositionY() > mc.getPositionY()//護衛より左下に姫
                            && sc.getPositionY() < mc.getPositionY() + mc.getBitmapHeight() / 6
                            &&
                            sc.getPositionX() + sc.getBitmapWidth() < mc.getPositionX() + mc.getBitmapWidth()
                            && sc.getPositionX() + sc.getBitmapWidth() > mc.getPositionX                  () +
                            mc.getBitmapWidth() - mc.getBitmapWidth() / 6) {
                            sc.av.isCrossOfChar = true;
                            touch_x = mc.getCenterPositionX() - mc.getBitmapWidth() / 5;
                            touch_y = mc.getCenterPositionY() + mc.getBitmapHeight() / 5;
                        Log.w("BattleView", "重なっている3");
                            sc.move();
                            mc.move();
                    }else if (sc.getPositionY() > mc.getPositionY()//護衛より右上に姫
                            && sc.getPositionY() < mc.getPositionY() + mc.getBitmapHeight() / 6
                            && sc.getPositionX() < mc.getPositionX() + mc.getBitmapWidth() / 6
                            && sc.getPositionX() > mc.getPositionX()) {
                            sc.av.isCrossOfChar = true;
                            touch_x = mc.getCenterPositionX() + mc.getBitmapWidth() / 5;
                            touch_y = mc.getCenterPositionY() + mc.getBitmapHeight() / 5;
                        Log.w("BattleView", "重なっている4");
                            sc.move();
                            mc.move();
                    }else{//護衛と姫が重なっていない状態
                        Log.w("BattleView", "重なっていない");
                        sc.av.isCrossOfChar = false;//一定範囲内にいるかを判定するフラグを偽にする
                        sc.move();
                        mc.move();
                    }

                    //モブと護衛が重ならないようにする処理
                    for(int i=0;i<mobCharacter.size();i++) {
                        if (mobCharacter.get(i).getPositionY() > sc.getPositionY()//護衛より左上に姫
                                && mobCharacter.get(i).getPositionY() < sc.getPositionY() + sc.getBitmapHeight() / 6
                                &&
                                mobCharacter.get(i).getPositionX() + mobCharacter.get(i).getBitmapWidth() < sc.getPositionX() + sc.getBitmapWidth()
                                && mobCharacter.get(i).getPositionX() + mobCharacter.get(i).getBitmapWidth() > sc.getPositionX() +
                                sc.getBitmapWidth() - sc.getBitmapWidth() / 6) {
                            sc.av.isCrossOfChar = true;//護衛と姫が重なっているかを判定するフラグを真にする
                            touch_x = mobCharacter.get(i).getCenterPositionX() + mobCharacter.get(i).getBitmapWidth() / 5;//この座標まで遠ざける
                            touch_y = mobCharacter.get(i).getCenterPositionY() - mobCharacter.get(i).getBitmapHeight() / 5;//
                            Log.w("BattleView", "重なっている1");
                        } else if (mobCharacter.get(i).getPositionY() > sc.getPositionY()//護衛より右下に姫
                                && mobCharacter.get(i).getPositionY() < sc.getPositionY() + sc.getBitmapHeight() / 6
                                &&
                                mobCharacter.get(i).getPositionX() < sc.getPositionX() + sc.getBitmapWidth() / 6
                                && mobCharacter.get(i).getPositionX() > sc.getPositionX()) {
                            sc.av.isCrossOfChar = true;
                            touch_x = mobCharacter.get(i).getCenterPositionX() - mobCharacter.get(i).getBitmapWidth() / 5;
                            touch_y = mobCharacter.get(i).getCenterPositionY() - mobCharacter.get(i).getBitmapHeight() / 5;
                            Log.w("BattleView", "重なっている2");
                        } else if (sc.getPositionY() > mobCharacter.get(i).getPositionY()//護衛より左下に姫
                                && sc.getPositionY() < mobCharacter.get(i).getPositionY() + mobCharacter.get(i).getBitmapHeight() / 6
                                &&
                                sc.getPositionX() + sc.getBitmapWidth() < mobCharacter.get(i).getPositionX() + mobCharacter.get(i).getBitmapWidth()
                                && sc.getPositionX() + sc.getBitmapWidth() > mobCharacter.get(i).getPositionX() +
                                mobCharacter.get(i).getBitmapWidth() - mobCharacter.get(i).getBitmapWidth() / 6) {
                            sc.av.isCrossOfChar = true;
                            touch_x = mobCharacter.get(i).getCenterPositionX() - mobCharacter.get(i).getBitmapWidth() / 5;
                            touch_y = mobCharacter.get(i).getCenterPositionY() + mobCharacter.get(i).getBitmapHeight() / 5;
                            Log.w("BattleView", "重なっている3");
                        } else if (sc.getPositionY() > mobCharacter.get(i).getPositionY()//護衛より右上に姫
                                && sc.getPositionY() < mobCharacter.get(i).getPositionY() + mobCharacter.get(i).getBitmapHeight() / 6
                                && sc.getPositionX() < mobCharacter.get(i).getPositionX() + mobCharacter.get(i).getBitmapWidth() / 6
                                && sc.getPositionX() > mobCharacter.get(i).getPositionX()) {
                            sc.av.isCrossOfChar = true;
                            touch_x = mobCharacter.get(i).getCenterPositionX() + mobCharacter.get(i).getBitmapWidth() / 5;
                            touch_y = mobCharacter.get(i).getCenterPositionY() + mobCharacter.get(i).getBitmapHeight() / 5;
                            Log.w("BattleView", "重なっている4");
                        }
                    }

                    //壁判定
                    if(sc.getCenterPositionX() < 100){
                        sc.av.isCrossOfChar = true;
                        touch_x = sc.getCenterPositionX() + sc.getBitmapWidth();
                    }
                    if(sc.getCenterPositionX() > BitmapCreate.width - 100){
                        sc.av.isCrossOfChar = true;
                        touch_x = sc.getCenterPositionX() - sc.getBitmapWidth();
                    }
                    if(sc.getCenterPositionY() > BitmapCreate.height - 200){
                        sc.av.isCrossOfChar = true;
                        touch_y = sc.getCenterPositionY() - sc.getBitmapHeight();
                    }
                    if(sc.getCenterPositionY() < 500){
                        if(sc.getCenterPositionX() < BitmapCreate.width/2 -40
                                || sc.getCenterPositionX() > BitmapCreate.width/2 + 30){
                            sc.av.isCrossOfChar = true;
                            touch_y = sc.getCenterPositionY() + sc.getBitmapHeight();
                        }else {

                        }
                    }

                    //テーブルとイスに当たった時の処理
                    if( (sc.getCenterPositionX() > 200
                            && sc.getCenterPositionX() < 400
                            && sc.getCenterPositionY() > 500
                            && sc.getCenterPositionY() < 900)
                            ||
                            (sc.getCenterPositionX() > 700
                            && sc.getCenterPositionX() < 900
                            && sc.getCenterPositionY() > 500
                            && sc.getCenterPositionY() < 900)){
                        switch (sc.av.goeiVecter){
                            case "migi":
                                sc.av.isCrossOfChar = true;
                                touch_x = sc.getCenterPositionX() - sc.getBitmapWidth();
                                break;
                            case "hidari":
                                sc.av.isCrossOfChar = true;
                                touch_x = sc.getCenterPositionX() + sc.getBitmapWidth();
                                break;
                            case "syoume":
                                sc.av.isCrossOfChar = true;
                                touch_y = sc.getCenterPositionY() - sc.getBitmapHeight();
                                break;
                            case "usiro":
                                sc.av.isCrossOfChar = true;
                                touch_y = sc.getCenterPositionY() + sc.getBitmapHeight();
                                break;
                            default:
                                sc.av.isCrossOfChar = true;
                                touch_y = sc.getCenterPositionY() - sc.getBitmapHeight();
                                break;
                        }
                    }





                    //護衛がゴールにたどり着いたかを判定
                    if(sc.getCenterPositionX() > BitmapCreate.width/2 - 30
                            && sc.getCenterPositionX() < BitmapCreate.width/2 + 30
                                && sc.getCenterPositionY() > 250 && sc.getCenterPositionY() < 310) {
                        checkGameEnd = true;
                    }
                    //ゴールにたどり着いていれば、馬に乗ってゲーム終了
                    if(checkGameEnd){
                        sc.changeIsLiveToTrue();
                        mc.changeIsLiveToTrue();
                        checkGameEnd = true;
                        sc.changeId(R.drawable.goei_jouba, 6, 10);
                        mc.changeId(R.drawable.himesama_jouba, 6, 10);
                        horse.move();
                        if(horse.getPositionX() + horse.getBitmapWidth() < 0){
                            checkGameEnd = false;
                            context.startActivity(new Intent(context, MainActivity.class));
                        }
                    }






                    mydraw();
                    holder.unlockCanvasAndPost(canvas);
                    t2 = System.currentTimeMillis();
                    if(t2- t1 < ONE_FRAME_TIME){
                        try{
                            sleep(ONE_FRAME_TIME - (t2 - t1));
                        }catch(InterruptedException e) {
                        }
                    }
                }
            }
        }
    }

    //画像を表示する
    private void mydraw(){
        canvas.drawColor(0, PorterDuff.Mode.CLEAR);
        for(int i=0;i<backg.size();i++){
            canvas.drawBitmap(backg.get(i).getBitmap(), (float)backg.get(i).getPositionX(),
                    (float)backg.get(i).getPositionY(), new Paint());
        }
        for(int i=0;i<mobCharacter.size();i++){
            canvas.drawBitmap(mobCharacter.get(i).getBitmap(), (float)mobCharacter.get(i).getPositionX(),
                    (float)mobCharacter.get(i).getPositionY(), new Paint());
        }
        canvas.drawBitmap(horse.getBitmap(), (float)horse.getPositionX(),
                (float)horse.getPositionY(), new Paint());


        ////----終了条件を入れなければ、どちらかがnullになったらエラーになる////
        //キャラクター同士が重なった時の描写の順番と鳥と衝突した時の描写
        if(mc.getPositionY() < sc.getPositionY()
                && mc.getPositionY()+mc.getBitmapHeight() > sc.getPositionY()){
            //護衛が手前の場合

                if (mc.checkIsLive() == false) {
                    //mc.changeId(R.drawable.bakuha, 6, 10);
                    canvas.drawBitmap(mc.getBitmap(), (float) mc.getPositionX(),
                            (float) mc.getPositionY(), new Paint());
                } else {
                    canvas.drawBitmap(mc.getBitmap(), (float) mc.getPositionX(),
                            (float) mc.getPositionY(), new Paint());
                }


                if (sc.checkIsLive() == false) {
                    switch (sc.av.goeiVecter){
                        case "hidari":
                            sc.changeId(R.drawable.goei_tentou_hidari, 6, 10);
                            break;
                        case "migi":
                            sc.changeId(R.drawable.goei_tentou_migi, 6, 10);
                            break;
                        case "usiro":
                            sc.changeId(R.drawable.goei_tentou_ue, 6, 10);
                            break;
                        case "syoumen":
                            sc.changeId(R.drawable.goei_tentou_sita, 6, 10);
                            break;
                        default:
                            break;
                    }

                    canvas.drawBitmap(sc.getBitmap(), (float) sc.getPositionX(),
                            (float) sc.getPositionY(), new Paint());
                    if (goeiTentouFc.getJudgeResumption()) {
                        Log.w("BattleView", "除去");
                        sc.changeIsLiveToTrue();
                    }
                } else {
                    canvas.drawBitmap(sc.getBitmap(), (float) sc.getPositionX(),
                            (float) sc.getPositionY(), new Paint());
                }

        }else if(sc.getPositionY() < mc.getPositionY()
                && sc.getPositionY()+sc.getBitmapHeight() > mc.getPositionY()) {
            //姫が手前の場合

                if (sc.checkIsLive() == false) {
                    switch (sc.av.goeiVecter){
                        case "hidari":
                            sc.changeId(R.drawable.goei_tentou_hidari, 6, 10);
                            break;
                        case "migi":
                            sc.changeId(R.drawable.goei_tentou_migi, 6, 10);
                            break;
                        case "usiro":
                            sc.changeId(R.drawable.goei_tentou_ue, 6, 10);
                            break;
                        case "syoumen":
                            sc.changeId(R.drawable.goei_tentou_sita, 6, 10);
                            break;
                        default:
                            break;
                    }

                    canvas.drawBitmap(sc.getBitmap(), (float) sc.getPositionX(),
                            (float) sc.getPositionY(), new Paint());
                    if (goeiTentouFc.getJudgeResumption()) {
                        Log.w("BattleView", "除去");
                        sc.changeIsLiveToTrue();
                    }
                } else {
                    canvas.drawBitmap(sc.getBitmap(), (float) sc.getPositionX(),
                            (float) sc.getPositionY(), new Paint());
                }


                if (mc.checkIsLive() == false) {
                    //mc.changeId(R.drawable.bakuha, 6, 10);
                    canvas.drawBitmap(mc.getBitmap(), (float) mc.getPositionX(),
                            (float) mc.getPositionY(), new Paint());
                    //if (mc.ecf.getJudgeResumption()) {
                        Log.w("BattleView", "除去");
                        //mc = null;
                    //}
                } else {
                    canvas.drawBitmap(mc.getBitmap(), (float) mc.getPositionX(),
                            (float) mc.getPositionY(), new Paint());
                }

        }else{

                if (sc.checkIsLive() == false) {
                    switch (sc.av.goeiVecter){
                        case "hidari":
                            sc.changeId(R.drawable.goei_tentou_hidari, 6, 10);
                            break;
                        case "migi":
                            sc.changeId(R.drawable.goei_tentou_migi, 6, 10);
                            break;
                        case "usiro":
                            sc.changeId(R.drawable.goei_tentou_ue, 6, 10);
                            break;
                        case "syoumen":
                            sc.changeId(R.drawable.goei_tentou_sita, 6, 10);
                            break;
                        default:
                            break;
                    }

                    canvas.drawBitmap(sc.getBitmap(), (float) sc.getPositionX(),
                            (float) sc.getPositionY(), new Paint());
                    if (goeiTentouFc.getJudgeResumption()) {
                        Log.w("BattleView", "除去");
                        sc.changeIsLiveToTrue();
                    }
                } else {
                    canvas.drawBitmap(sc.getBitmap(), (float) sc.getPositionX(),
                            (float) sc.getPositionY(), new Paint());
                }


                if (mc.checkIsLive() == false) {
                    //mc.changeId(R.drawable.bakuha, 6, 10);
                    canvas.drawBitmap(mc.getBitmap(), (float) mc.getPositionX(),
                            (float) mc.getPositionY(), new Paint());
                    //if (mc.ecf.getJudgeResumption()) {
                        Log.w("BattleView", "除去");
                        //mc = null;
                    //}
                } else {
                    canvas.drawBitmap(mc.getBitmap(), (float) mc.getPositionX(),
                            (float) mc.getPositionY(), new Paint());
                }

        }

        for(int i=0;i<scout.size();i++) {
            canvas.drawBitmap(scout.get(i).getBitmap(), (float) scout.get(i).getPositionX(),
                    (float) scout.get(i).getPositionY(), new Paint());
        }

    }
}
