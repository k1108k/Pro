package com.example.k.Honeymoon;

import android.util.Log;

import java.util.ArrayList;

/**
 * Created by K on 2018/03/01.
 */

//アクションバリエーションクラス
public class ActionVariation{
    private BitmapCreate bc;
    private double v_char;//キャラクターの移動速度
    private double vx_char;//キャラクターの移動速度x
    private double vy_char;//                   y
    private ArrayList<Double> bulletX = new ArrayList<Double>();
    private ArrayList<Double> bulletY = new ArrayList<Double>();
    private double vx_bullet;//弾速
    private double vy_bullet;
    private final double radius = 20.0;
    private double circleX;
    private double circleY;
    private final int RAND_MAX=30;
    private double moveRadiusX=300.0;
    private double moveRadiusY=150.0;
    private double counter=90.0;
    private double DEGREE_MAX = BitmapCreate.height;
    public static String goeiVecter = "";
    public static String himesamaVecter = "";
    public boolean isCrossOfChar = false;

    public ActionVariation(BitmapCreate bc) {
        bulletX.add(-10.0);//配列と違ってlistは初期化しなければnullのため
        bulletY.add(-10.0);
        this.bc = bc;   //座標関係のメソッド使用のため
    }


    //--------------------------------------------------------------------//

    //移動バリエーション
    public class MoveVariation {
        private FrameControl fc = new FrameControl();

        public FrameControl control() {
            return fc;
        }

        public void touchMove(FrameControl mcf) {    //タッチ移動
            if (mcf.getJudgeResumption()) {
                double ty_y = BattleView.touch_y - bc.getCenterPositionY();//タッチした座標までの距離ｙ
                double tx_x = BattleView.touch_x - bc.getCenterPositionX();//タッチした座標までの距離x
                double y_ty = bc.getCenterPositionY() - BattleView.touch_y;//
                double x_tx = bc.getCenterPositionX() - BattleView.touch_x;//
                double len_migisita = Math.sqrt(ty_y * ty_y + tx_x * tx_x);     //斜辺の距離
                double len_hidarisita = Math.sqrt(ty_y * ty_y + x_tx * x_tx);   //
                double len_migiue = Math.sqrt(y_ty * y_ty + tx_x * tx_x);       //
                double len_hidariue = Math.sqrt(y_ty * y_ty + x_tx * x_tx);     //
                double dvPerFrame_migisita = len_migisita / v_char;        //斜辺を移動量進むのに
                double dvPerFrame_hidarisita = len_hidarisita / v_char;    //かかるフレーム秒
                double dvPerFrame_migiue = len_migiue / v_char;            //
                double dvPerFrame_hidariue = len_hidariue / v_char;        //
                double dxPerFrame_migisita = tx_x / dvPerFrame_migisita;        //タッチした座標までの
                double dxPerFrame_hidarisita = x_tx / dvPerFrame_hidarisita;    //距離xを斜辺移動の
                double dxPerFrame_migiue = tx_x / dvPerFrame_migiue;            //フレーム秒あたりに
                double dxPerFrame_hidariue = x_tx / dvPerFrame_hidariue;        //進む距離
                double slo_migisita = ty_y / tx_x;      //斜辺の傾き
                double slo_hidarisita = ty_y / x_tx;    //
                double slo_migiue = y_ty / tx_x;        //
                double slo_hidariue = y_ty / x_tx;      //
                if(BattleView.sc.checkIsLive() == true) {
                    if (BattleView.touch_y > bc.getCenterPositionY()) {   //プレイヤーより下をタッチ
                        if (BattleView.touch_y + 5 > bc.getCenterPositionY()
                                && BattleView.touch_y - 5 < bc.getCenterPositionY()) {
                            //タッチした場所からの閾値で止まればその場に止まる
                            //以下同じ
                        } else {
                            if (BattleView.touch_x + 5 > bc.getCenterPositionX()
                                    && BattleView.touch_x - 5 < bc.getCenterPositionX()) {

                            } else {
                                if (BattleView.touch_x > bc.getCenterPositionX()) { //プレイヤーより右下をタッチ
                                    if (BattleView.touch_x - bc.getCenterPositionX() > BattleView.touch_y - bc.getCenterPositionY()) {//右向き
                                        Log.w("BattleView", "右を向く");
                                        //移動　以下同じ
                                        moveV_char((int) dxPerFrame_migisita, (int) (slo_migisita * dxPerFrame_migisita));
                                        if (isCrossOfChar) {  //キャラクター同士が重なっている状態
                                            //同じ向きのまま姫から遠ざかっていく
                                            switch (goeiVecter) {
                                                case "migi":
                                                    if (bc.getId() == R.drawable.goei_migi1)
                                                        bc.changeId(R.drawable.goei_migi3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_migi1, 6, 10);
                                                    break;
                                                case "syoumen":
                                                    if (bc.getId() == R.drawable.goei_syoumen1)
                                                        bc.changeId(R.drawable.goei_syoumen3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_syoumen1, 6, 10);
                                                    break;
                                                case "usiro":
                                                    if (bc.getId() == R.drawable.goei_usiro1)
                                                        bc.changeId(R.drawable.goei_usiro3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_usiro1, 6, 10);
                                                    break;
                                                case "hidari":
                                                    if (bc.getId() == R.drawable.goei_hidari1)
                                                        bc.changeId(R.drawable.goei_hidari3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_hidari1, 6, 10);
                                                    break;
                                                default:
                                                    break;
                                            }
                                        } else { //キャラクターが重なっていない状態　タッチした方向に向きを変える
                                            if (bc.getId() == R.drawable.goei_migi1)
                                                bc.changeId(R.drawable.goei_migi3, 6, 10);
                                            else
                                                bc.changeId(R.drawable.goei_migi1, 6, 10);
                                            goeiVecter = "migi";
                                        }

                                    } else {//下向き
                                        Log.w("BattleView", "下を向く");
                                        moveV_char((int) dxPerFrame_migisita, (int) (slo_migisita * dxPerFrame_migisita));
                                        if (isCrossOfChar) {  //キャラクター同士が重なっている状態
                                            //同じ向きのまま姫から遠ざかっていく
                                            Log.w("ActionVariation", "重なっている状態");
                                            switch (goeiVecter) {
                                                case "migi":
                                                    if (bc.getId() == R.drawable.goei_migi1)
                                                        bc.changeId(R.drawable.goei_migi3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_migi1, 6, 10);
                                                    break;
                                                case "syoumen":
                                                    if (bc.getId() == R.drawable.goei_syoumen1)
                                                        bc.changeId(R.drawable.goei_syoumen3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_syoumen1, 6, 10);
                                                    break;
                                                case "usiro":
                                                    if (bc.getId() == R.drawable.goei_usiro1)
                                                        bc.changeId(R.drawable.goei_usiro3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_usiro1, 6, 10);
                                                    break;
                                                case "hidari":
                                                    if (bc.getId() == R.drawable.goei_hidari1)
                                                        bc.changeId(R.drawable.goei_hidari3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_hidari1, 6, 10);
                                                    break;
                                                default:
                                                    break;
                                            }
                                        } else { //キャラクターが重なっていない状態　タッチした方向に向きを変える
                                            Log.w("ActionVariation", "重なっていない状態");
                                            if (bc.getId() == R.drawable.goei_syoumen1)
                                                bc.changeId(R.drawable.goei_syoumen3, 6, 10);
                                            else
                                                bc.changeId(R.drawable.goei_syoumen1, 6, 10);
                                            goeiVecter = "syoumen";
                                        }

                                    }
                                } else {  //プレイヤーより左下をタッチ
                                    if (bc.getCenterPositionX() - BattleView.touch_x > BattleView.touch_y - bc.getCenterPositionY()) {//左向き
                                        Log.w("BattleView", "左を向く");
                                        moveV_char((int) -dxPerFrame_hidarisita, (int) (slo_hidarisita * dxPerFrame_hidarisita));
                                        if (isCrossOfChar) {  //キャラクター同士が重なっている状態
                                            //同じ向きのまま姫から遠ざかっていく
                                            switch (goeiVecter) {
                                                case "migi":
                                                    if (bc.getId() == R.drawable.goei_migi1)
                                                        bc.changeId(R.drawable.goei_migi3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_migi1, 6, 10);
                                                    break;
                                                case "syoumen":
                                                    if (bc.getId() == R.drawable.goei_syoumen1)
                                                        bc.changeId(R.drawable.goei_syoumen3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_syoumen1, 6, 10);
                                                    break;
                                                case "usiro":
                                                    if (bc.getId() == R.drawable.goei_usiro1)
                                                        bc.changeId(R.drawable.goei_usiro3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_usiro1, 6, 10);
                                                    break;
                                                case "hidari":
                                                    if (bc.getId() == R.drawable.goei_hidari1)
                                                        bc.changeId(R.drawable.goei_hidari3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_hidari1, 6, 10);
                                                    break;
                                                default:
                                                    break;
                                            }
                                        } else { //キャラクターが重なっていない状態　タッチした方向に向きを変える
                                            if (bc.getId() == R.drawable.goei_hidari1)
                                                bc.changeId(R.drawable.goei_hidari3, 6, 10);
                                            else
                                                bc.changeId(R.drawable.goei_hidari1, 6, 10);
                                            goeiVecter = "hidari";
                                        }

                                    } else {//下向き
                                        Log.w("BattleView", "下を向く");
                                        moveV_char((int) -dxPerFrame_hidarisita, (int) (slo_hidarisita * dxPerFrame_hidarisita));
                                        if (isCrossOfChar) {  //キャラクター同士が重なっている状態
                                            //同じ向きのまま姫から遠ざかっていく
                                            switch (goeiVecter) {
                                                case "migi":
                                                    if (bc.getId() == R.drawable.goei_migi1)
                                                        bc.changeId(R.drawable.goei_migi3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_migi1, 6, 10);
                                                    break;
                                                case "syoumen":
                                                    if (bc.getId() == R.drawable.goei_syoumen1)
                                                        bc.changeId(R.drawable.goei_syoumen3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_syoumen1, 6, 10);
                                                    break;
                                                case "usiro":
                                                    if (bc.getId() == R.drawable.goei_usiro1)
                                                        bc.changeId(R.drawable.goei_usiro3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_usiro1, 6, 10);
                                                    break;
                                                case "hidari":
                                                    if (bc.getId() == R.drawable.goei_hidari1)
                                                        bc.changeId(R.drawable.goei_hidari3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_hidari1, 6, 10);
                                                    break;
                                                default:
                                                    break;
                                            }
                                        } else { //キャラクターが重なっていない状態　タッチした方向に向きを変える
                                            if (bc.getId() == R.drawable.goei_syoumen1)
                                                bc.changeId(R.drawable.goei_syoumen3, 6, 10);
                                            else
                                                bc.changeId(R.drawable.goei_syoumen1, 6, 10);
                                            goeiVecter = "syoumen";
                                        }

                                    }
                                }
                            }
                        }
                    } else {  //プレイヤーより上をタッチ
                        if (BattleView.touch_y - 5 < bc.getCenterPositionY()
                                && BattleView.touch_y + 5 > bc.getCenterPositionY()) {

                        } else {
                            if (BattleView.touch_x + 5 > bc.getCenterPositionX()
                                    && BattleView.touch_x - 5 < bc.getCenterPositionX()) {

                            } else {
                                if (BattleView.touch_x > bc.getCenterPositionX()) { //プレイヤーより右上をタッチ
                                    if (BattleView.touch_x - bc.getCenterPositionX() > bc.getCenterPositionY() - BattleView.touch_y) {//右向き
                                        Log.w("BattleView", "右を向く");
                                        moveV_char((int) dxPerFrame_migiue, (int) (slo_migiue * -dxPerFrame_migiue));
                                        if (isCrossOfChar) {  //キャラクター同士が重なっている状態
                                            //同じ向きのまま姫から遠ざかっていく
                                            switch (goeiVecter) {
                                                case "migi":
                                                    if (bc.getId() == R.drawable.goei_migi1)
                                                        bc.changeId(R.drawable.goei_migi3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_migi1, 6, 10);
                                                    break;
                                                case "syoumen":
                                                    if (bc.getId() == R.drawable.goei_syoumen1)
                                                        bc.changeId(R.drawable.goei_syoumen3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_syoumen1, 6, 10);
                                                    break;
                                                case "usiro":
                                                    if (bc.getId() == R.drawable.goei_usiro1)
                                                        bc.changeId(R.drawable.goei_usiro3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_usiro1, 6, 10);
                                                    break;
                                                case "hidari":
                                                    if (bc.getId() == R.drawable.goei_hidari1)
                                                        bc.changeId(R.drawable.goei_hidari3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_hidari1, 6, 10);
                                                    break;
                                                default:
                                                    break;
                                            }
                                        } else { //キャラクターが重なっていない状態　タッチした方向に向きを変える
                                            if (bc.getId() == R.drawable.goei_migi1)
                                                bc.changeId(R.drawable.goei_migi3, 6, 10);
                                            else
                                                bc.changeId(R.drawable.goei_migi1, 6, 10);
                                            goeiVecter = "migi";
                                        }

                                    } else {//上向き
                                        Log.w("BattleView", "上を向く");
                                        moveV_char((int) dxPerFrame_migiue, (int) (slo_migiue * -dxPerFrame_migiue));
                                        if (isCrossOfChar) {  //キャラクター同士が重なっている状態
                                            //同じ向きのまま姫から遠ざかっていく
                                            switch (goeiVecter) {
                                                case "migi":
                                                    if (bc.getId() == R.drawable.goei_migi1)
                                                        bc.changeId(R.drawable.goei_migi3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_migi1, 6, 10);
                                                    break;
                                                case "syoumen":
                                                    if (bc.getId() == R.drawable.goei_syoumen1)
                                                        bc.changeId(R.drawable.goei_syoumen3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_syoumen1, 6, 10);
                                                    break;
                                                case "usiro":
                                                    if (bc.getId() == R.drawable.goei_usiro1)
                                                        bc.changeId(R.drawable.goei_usiro3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_usiro1, 6, 10);
                                                    break;
                                                case "hidari":
                                                    if (bc.getId() == R.drawable.goei_hidari1)
                                                        bc.changeId(R.drawable.goei_hidari3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_hidari1, 6, 10);
                                                    break;
                                                default:
                                                    break;
                                            }
                                        } else { //キャラクターが重なっていない状態　タッチした方向に向きを変える
                                            if (bc.getId() == R.drawable.goei_usiro1)
                                                bc.changeId(R.drawable.goei_usiro3, 6, 10);
                                            else
                                                bc.changeId(R.drawable.goei_usiro1, 6, 10);
                                            goeiVecter = "usiro";
                                        }

                                    }
                                } else {  //プレイヤーより左上をタッチ
                                    if (bc.getCenterPositionX() - BattleView.touch_x > bc.getCenterPositionY() - BattleView.touch_y) {//左向き
                                        Log.w("BattleView", "左を向く");
                                        moveV_char((int) -dxPerFrame_hidariue, (int) (slo_hidariue * -dxPerFrame_hidariue));
                                        if (isCrossOfChar) {  //キャラクター同士が重なっている状態
                                            //同じ向きのまま姫から遠ざかっていく
                                            switch (goeiVecter) {
                                                case "migi":
                                                    if (bc.getId() == R.drawable.goei_migi1)
                                                        bc.changeId(R.drawable.goei_migi3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_migi1, 6, 10);
                                                    break;
                                                case "syoumen":
                                                    if (bc.getId() == R.drawable.goei_syoumen1)
                                                        bc.changeId(R.drawable.goei_syoumen3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_syoumen1, 6, 10);
                                                    break;
                                                case "usiro":
                                                    if (bc.getId() == R.drawable.goei_usiro1)
                                                        bc.changeId(R.drawable.goei_usiro3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_usiro1, 6, 10);
                                                    break;
                                                case "hidari":
                                                    if (bc.getId() == R.drawable.goei_hidari1)
                                                        bc.changeId(R.drawable.goei_hidari3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_hidari1, 6, 10);
                                                    break;
                                                default:
                                                    break;
                                            }
                                        } else { //キャラクターが重なっていない状態　タッチした方向に向きを変える
                                            if (bc.getId() == R.drawable.goei_hidari1)
                                                bc.changeId(R.drawable.goei_hidari3, 6, 10);
                                            else
                                                bc.changeId(R.drawable.goei_hidari1, 6, 10);
                                            goeiVecter = "hidari";
                                        }

                                    } else {//上向き
                                        Log.w("BattleView", "上を向く");
                                        moveV_char((int) -dxPerFrame_hidariue, (int) (slo_hidariue * -dxPerFrame_hidariue));
                                        if (isCrossOfChar) {  //キャラクター同士が重なっている状態
                                            //同じ向きのまま姫から遠ざかっていく
                                            switch (goeiVecter) {
                                                case "migi":
                                                    if (bc.getId() == R.drawable.goei_migi1)
                                                        bc.changeId(R.drawable.goei_migi3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_migi1, 6, 10);
                                                    break;
                                                case "syoumen":
                                                    if (bc.getId() == R.drawable.goei_syoumen1)
                                                        bc.changeId(R.drawable.goei_syoumen3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_syoumen1, 6, 10);
                                                    break;
                                                case "usiro":
                                                    if (bc.getId() == R.drawable.goei_usiro1)
                                                        bc.changeId(R.drawable.goei_usiro3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_usiro1, 6, 10);
                                                    break;
                                                case "hidari":
                                                    if (bc.getId() == R.drawable.goei_hidari1)
                                                        bc.changeId(R.drawable.goei_hidari3, 6, 10);
                                                    else
                                                        bc.changeId(R.drawable.goei_hidari1, 6, 10);
                                                    break;
                                                default:
                                                    break;
                                            }
                                        } else { //キャラクターが重なっていない状態　タッチした方向に向きを変える
                                            if (bc.getId() == R.drawable.goei_usiro1)
                                                bc.changeId(R.drawable.goei_usiro3, 6, 10);
                                            else
                                                bc.changeId(R.drawable.goei_usiro1, 6, 10);
                                            goeiVecter = "usiro";
                                        }

                                    }
                                }
                            }
                        }
                    }
                }

                if (BattleView.isTouched == false) {    //画面から指を離した時
                    switch (bc.getId()) {               //護衛の向きによって、止まった時の画像を選択
                        case R.drawable.goei_hidari1:
                        case R.drawable.goei_hidari3:
                            bc.changeId(R.drawable.goei_hidari2, 6, 10);
                            break;
                        case R.drawable.goei_syoumen1:
                        case R.drawable.goei_syoumen3:
                            bc.changeId(R.drawable.goei_syoumen2, 6, 10);
                            break;
                        case R.drawable.goei_migi1:
                        case R.drawable.goei_migi3:
                            bc.changeId(R.drawable.goei_migi2, 6, 10);
                            break;
                        case R.drawable.goei_usiro1:
                        case R.drawable.goei_usiro3:
                            bc.changeId(R.drawable.goei_usiro2, 6, 10);
                            break;
                        default:
                            break;
                    }
                }
            }
        }


        //左右直線移動
        public void leftAndRightMove(FrameControl mcf) {
            if (mcf.getJudgeResumption()) {
                if(vx_char >= 0){
                    switch (bc.getId()){
                        case R.drawable.tori_migi1:
                            bc.changeId(R.drawable.tori_migi2, 6, 10);
                            break;
                        case R.drawable.tori_migi2:
                            bc.changeId(R.drawable.tori_migi3,6,10);
                            break;
                        case R.drawable.tori_migi3:
                            bc.changeId(R.drawable.tori_migi1,6,10);
                            break;
                        default:
                            bc.changeId(R.drawable.tori_migi3,6,10);
                            break;
                    }
                }else{
                    switch (bc.getId()){
                        case R.drawable.tori_hidari1:
                            bc.changeId(R.drawable.tori_hidari2, 6, 10);
                            break;
                        case R.drawable.tori_hidari2:
                            bc.changeId(R.drawable.tori_hidari3, 6, 10);
                            break;
                        case R.drawable.tori_hidari3:
                            bc.changeId(R.drawable.tori_hidari1,6,10);
                            break;
                        default:
                            bc.changeId(R.drawable.tori_hidari3, 6, 10);
                            break;
                    }
                }
                moveVx_char((int) v_char);
                if ((bc.getPositionX() + bc.getBitmapWidth()) > BitmapCreate.width) {
                    v_char = -v_char;
                    bc.setPositionX(BitmapCreate.width - bc.getBitmapWidth());
                }
                if (bc.getPositionX() < 0) {
                    v_char = -v_char;
                    bc.setPositionX(0);
                }
            }
        }

        //左方直線移動
        public void leftMove(FrameControl mcf){
            if(mcf.getJudgeResumption()){
                if(bc.getId() == R.drawable.horse2
                        || bc.getId() == R.drawable.horse1 || bc.getId() == R.drawable.horse3){
                    switch (bc.getId()) {
                        case R.drawable.horse1:
                            bc.changeId(R.drawable.horse3, 4, 9);
                            break;
                        case R.drawable.horse3:
                            bc.changeId(R.drawable.horse1, 4, 9);
                            break;
                        default:
                            bc.changeId(R.drawable.horse1, 4,9);
                            break;
                    }
                }else {
                    switch (bc.getId()) {
                        case R.drawable.tori_hidari1:
                            bc.changeId(R.drawable.tori_hidari2, 6, 10);
                            break;
                        case R.drawable.tori_hidari2:
                            bc.changeId(R.drawable.tori_hidari3, 6, 10);
                            break;
                        case R.drawable.tori_hidari3:
                            bc.changeId(R.drawable.tori_hidari1, 6, 10);
                            break;
                        default:
                            bc.changeId(R.drawable.tori_hidari3, 6, 10);
                            break;
                    }
                }
                moveVx_char((int)-v_char);
            }
        }

        //右方直線移動
        public void rightMove(FrameControl mcf){
            if(mcf.getJudgeResumption()){
                switch (bc.getId()){
                    case R.drawable.tori_migi1:
                        bc.changeId(R.drawable.tori_migi2, 6, 10);
                        break;
                    case R.drawable.tori_migi2:
                        bc.changeId(R.drawable.tori_migi3, 6, 10);
                        break;
                    case R.drawable.tori_migi3:
                        bc.changeId(R.drawable.tori_migi1,6,10);
                        break;
                    default:
                        bc.changeId(R.drawable.tori_migi3, 6, 10);
                        break;
                }
                moveVx_char((int)v_char);
            }
        }

        //下方直線移動
        public void downMove(FrameControl mcf){
            if(mcf.getJudgeResumption()){
                switch (bc.getId()){
                    case R.drawable.tori_syoumen1:
                        bc.changeId(R.drawable.tori_syoumen2, 6, 10);
                        break;
                    case R.drawable.tori_syoumen2:
                        bc.changeId(R.drawable.tori_syoumen3, 6, 10);
                        break;
                    case R.drawable.tori_syoumen3:
                        bc.changeId(R.drawable.tori_syoumen1,6,10);
                        break;
                    default:
                        bc.changeId(R.drawable.tori_syoumen3, 6, 10);
                        break;
                }
                moveVy_char((int)v_char);
            }
        }

        //上方直線移動
        public void upwardMove(FrameControl mcf){
            if(mcf.getJudgeResumption()){
                switch (bc.getId()){
                    case R.drawable.tori_usiro1:
                        bc.changeId(R.drawable.tori_usiro2, 6, 10);
                        break;
                    case R.drawable.tori_usiro2:
                        bc.changeId(R.drawable.tori_usiro3, 6, 10);
                        break;
                    case R.drawable.tori_usiro3:
                        bc.changeId(R.drawable.tori_usiro1,6,10);
                        break;
                    default:
                        bc.changeId(R.drawable.tori_usiro3, 6, 10);
                        break;
                }
                moveVy_char((int)-v_char);
            }
        }

        //乱数移動
        public void RandomMove(FrameControl mcf) {
            bc.setRandomPosition();
        }

        //下にサインカーブ移動
        public void sineCurveMove_down(FrameControl mcf) {
            if (mcf.getJudgeResumption()) {
                double radian = Math.toRadians(counter);
                double cos = Math.cos(radian);
                double sin = Math.sin(radian);
                if(cos >= 0 && sin >= 0){
                    Log.w("ActionVariation", "Cosプラス");
                    switch (bc.getId()){
                        case R.drawable.tori_hidari1:
                            bc.changeId(R.drawable.tori_hidari2, 6, 10);
                            break;
                        case R.drawable.tori_hidari2:
                            bc.changeId(R.drawable.tori_hidari3, 6, 10);
                            break;
                        case R.drawable.tori_hidari3:
                            bc.changeId(R.drawable.tori_hidari1,6,10);
                            break;
                        default:
                            bc.changeId(R.drawable.tori_hidari3, 6, 10);
                            break;
                    }
                }else if(cos <= 0 && sin >= 0){
                    Log.w("ActionVariation", "Cosマイナス");
                    switch (bc.getId()){
                        case R.drawable.tori_hidari1:
                            bc.changeId(R.drawable.tori_hidari2, 6, 10);
                            break;
                        case R.drawable.tori_hidari2:
                            bc.changeId(R.drawable.tori_hidari3,6,10);
                            break;
                        case R.drawable.tori_hidari3:
                            bc.changeId(R.drawable.tori_hidari1,6,10);
                            break;
                        default:
                            bc.changeId(R.drawable.tori_hidari3,6,10);
                            break;
                    }
                }else if(cos <= 0 && sin <= 0){
                    Log.w("ActionVariation", "Cosマイナス");
                    switch (bc.getId()){
                        case R.drawable.tori_migi1:
                            bc.changeId(R.drawable.tori_migi2, 6, 10);
                            break;
                        case R.drawable.tori_migi2:
                            bc.changeId(R.drawable.tori_migi3,6,10);
                            break;
                        case R.drawable.tori_migi3:
                            bc.changeId(R.drawable.tori_migi1,6,10);
                            break;
                        default:
                            bc.changeId(R.drawable.tori_migi3,6,10);
                            break;
                    }
                }else if(cos >= 0 && sin <= 0){
                    Log.w("ActionVariation", "Cosマイナス");
                    switch (bc.getId()){
                        case R.drawable.tori_migi1:
                            bc.changeId(R.drawable.tori_migi2, 6, 10);
                            break;
                        case R.drawable.tori_migi2:
                            bc.changeId(R.drawable.tori_migi3,6,10);
                            break;
                        case R.drawable.tori_migi3:
                            bc.changeId(R.drawable.tori_migi1,6,10);
                            break;
                        default:
                            bc.changeId(R.drawable.tori_migi3,6,10);
                            break;
                    }
                }
                bc.setPositionX((int) (circleX + moveRadiusX * cos));
                bc.setPositionY((int) (circleY + counter));
                counter += bc.random.nextInt(RAND_MAX);
//                if (counter >= DEGREE_MAX) {
//                    counter = 0.0;
//                }
            }
        }

        //上にサインカーブ移動
        public void sineCurveMove_upward(FrameControl mcf) {
            if (mcf.getJudgeResumption()) {
                double radian = Math.toRadians(counter);
                double cos = Math.cos(radian);
                double sin = Math.sin(radian);
                if(cos >= 0 && sin >= 0){
                    Log.w("ActionVariation", "Cosプラス");
                    switch (bc.getId()){
                        case R.drawable.tori_hidari1:
                            bc.changeId(R.drawable.tori_hidari2, 6, 10);
                            break;
                        case R.drawable.tori_hidari2:
                            bc.changeId(R.drawable.tori_hidari3, 6, 10);
                            break;
                        case R.drawable.tori_hidari3:
                            bc.changeId(R.drawable.tori_hidari1,6,10);
                            break;
                        default:
                            bc.changeId(R.drawable.tori_hidari3, 6, 10);
                            break;
                    }
                }else if(cos <= 0 && sin >= 0){
                    Log.w("ActionVariation", "Cosマイナス");
                    switch (bc.getId()){
                        case R.drawable.tori_hidari1:
                            bc.changeId(R.drawable.tori_hidari2, 6, 10);
                            break;
                        case R.drawable.tori_hidari2:
                            bc.changeId(R.drawable.tori_hidari3,6,10);
                            break;
                        case R.drawable.tori_hidari3:
                            bc.changeId(R.drawable.tori_hidari1,6,10);
                            break;
                        default:
                            bc.changeId(R.drawable.tori_hidari3,6,10);
                            break;
                    }
                }else if(cos <= 0 && sin <= 0){
                    Log.w("ActionVariation", "Cosマイナス");
                    switch (bc.getId()){
                        case R.drawable.tori_migi1:
                            bc.changeId(R.drawable.tori_migi2, 6, 10);
                            break;
                        case R.drawable.tori_migi2:
                            bc.changeId(R.drawable.tori_migi3,6,10);
                            break;
                        case R.drawable.tori_migi3:
                            bc.changeId(R.drawable.tori_migi1,6,10);
                            break;
                        default:
                            bc.changeId(R.drawable.tori_migi3,6,10);
                            break;
                    }
                }else if(cos >= 0 && sin <= 0){
                    Log.w("ActionVariation", "Cosマイナス");
                    switch (bc.getId()){
                        case R.drawable.tori_migi1:
                            bc.changeId(R.drawable.tori_migi2, 6, 10);
                            break;
                        case R.drawable.tori_migi2:
                            bc.changeId(R.drawable.tori_migi3,6,10);
                            break;
                        case R.drawable.tori_migi3:
                            bc.changeId(R.drawable.tori_migi1,6,10);
                            break;
                        default:
                            bc.changeId(R.drawable.tori_migi3,6,10);
                            break;
                    }
                }
                bc.setPositionX((int) (circleX + moveRadiusX * cos));
                bc.setPositionY((int) (circleY - counter));
                counter += bc.random.nextInt(RAND_MAX);
            }
        }




        //追跡
        public void chaseGoeiMove(FrameControl mcf) {
            if (mcf.getJudgeResumption()) {
                double hy_gy = bc.getCenterPositionY() - BattleView.sc.getCenterPositionY();//護衛と姫の距離ｙ
                double hx_gx = bc.getCenterPositionX() - BattleView.sc.getCenterPositionX();//護衛と姫の距離x
                double gy_hy = BattleView.sc.getCenterPositionY() - bc.getCenterPositionX();//
                double gx_hx = BattleView.sc.getCenterPositionX() - bc.getCenterPositionX();//
                double len_migisita = Math.sqrt(gy_hy * gy_hy + gx_hx * gx_hx);     //斜辺の距離
                double len_hidarisita = Math.sqrt(gy_hy * gy_hy + hx_gx * hx_gx);   //姫を基点
                double len_migiue = Math.sqrt(hy_gy * hy_gy + gx_hx * gx_hx);       //
                double len_hidariue = Math.sqrt(hy_gy * hy_gy + hx_gx * hx_gx);     //
                double dvPerFrame_migisita = len_migisita / v_char;        //斜辺を移動量進むのに
                double dvPerFrame_hidarisita = len_hidarisita / v_char;    //かかるフレーム秒
                double dvPerFrame_migiue = len_migiue / v_char;            //
                double dvPerFrame_hidariue = len_hidariue / v_char;        //
                double dxPerFrame_migisita = gx_hx / dvPerFrame_migisita;        //タッチした座標までの
                double dxPerFrame_hidarisita = hx_gx / dvPerFrame_hidarisita;    //距離xを斜辺移動の
                double dxPerFrame_migiue = gx_hx / dvPerFrame_migiue;            //フレーム秒あたりに
                double dxPerFrame_hidariue = hx_gx / dvPerFrame_hidariue;        //進む距離
                double slo_migisita = gy_hy / gx_hx;      //斜辺の傾き
                double slo_hidarisita = gy_hy / hx_gx;    //
                double slo_migiue = hy_gy / gx_hx;        //
                double slo_hidariue = hy_gy / hx_gx;      //

                //護衛の座標から一定の範囲内に入ると止まる
                if (BattleView.sc.getCenterPositionY() + 110 > bc.getCenterPositionY()
                        && BattleView.sc.getCenterPositionY() - 110 < bc.getCenterPositionY()
                        && BattleView.sc.getCenterPositionX() + 110 > bc.getCenterPositionX()
                        && BattleView.sc.getCenterPositionX() - 110 < bc.getCenterPositionX()) {
                    switch (himesamaVecter) {
                        case "migi":
                            bc.changeId(R.drawable.himesama_migi2, 6, 10);
                            break;
                        case "syoumen":
                            bc.changeId(R.drawable.himesama_syoumen2, 6, 10);
                            break;
                        case "hidari":
                            bc.changeId(R.drawable.himesama_hidari2, 6, 10);
                            break;
                        case "usiro":
                            bc.changeId(R.drawable.himesama_usiro2, 6, 10);
                            break;
                        default:
                            break;
                    }
                } else {    //護衛を追いかける
                    if (BattleView.sc.getCenterPositionY() > bc.getCenterPositionY()) {   //姫より下に護衛
                        if (BattleView.sc.getCenterPositionX() > bc.getCenterPositionX()) { //プレイヤーより右下をタッチ
                            if (BattleView.sc.getCenterPositionX() - bc.getCenterPositionX() > BattleView.sc.getCenterPositionY() - bc.getCenterPositionY()) {
                                Log.w("BattleView", "右を向く");
                                moveV_char((int) dxPerFrame_migisita, (int) (slo_migisita * dxPerFrame_migisita));
                                if (bc.getId() == R.drawable.himesama_migi1)
                                    bc.changeId(R.drawable.himesama_migi3, 6, 10);
                                else
                                    bc.changeId(R.drawable.himesama_migi1, 6, 10);
                                himesamaVecter = "migi";
                            } else {
                                Log.w("BattleView", "下を向く");
                                moveV_char((int) dxPerFrame_migisita, (int) (slo_migisita * dxPerFrame_migisita));
                                if (bc.getId() == R.drawable.himesama_syoumen1)
                                    bc.changeId(R.drawable.himesama_syoumen3, 6, 10);
                                else
                                    bc.changeId(R.drawable.himesama_syoumen1, 6, 10);
                                himesamaVecter = "syoumen";
                            }
                        } else {  //プレイヤーより左下をタッチ
                            if (bc.getCenterPositionX() - BattleView.sc.getCenterPositionX() > BattleView.sc.getCenterPositionY() - bc.getCenterPositionY()) {
                                Log.w("BattleView", "左を向く");
                                moveV_char((int) -dxPerFrame_hidarisita, (int) (slo_hidarisita * dxPerFrame_hidarisita));
                                if (bc.getId() == R.drawable.himesama_hidari1)
                                    bc.changeId(R.drawable.himesama_hidari3, 6, 10);
                                else
                                    bc.changeId(R.drawable.himesama_hidari1, 6, 10);
                                himesamaVecter = "hidari";
                            } else {
                                Log.w("BattleView", "下を向く");
                                moveV_char((int) -dxPerFrame_hidarisita, (int) (slo_hidarisita * dxPerFrame_hidarisita));
                                if (bc.getId() == R.drawable.himesama_syoumen1)
                                    bc.changeId(R.drawable.himesama_syoumen3, 6, 10);
                                else
                                    bc.changeId(R.drawable.himesama_syoumen1, 6, 10);
                                himesamaVecter = "syoumen";
                            }
                        }
                    } else {    //プレイヤーより上をタッチ
                        if (BattleView.sc.getCenterPositionX() > bc.getCenterPositionX()) { //プレイヤーより右上をタッチ
                            if (BattleView.sc.getCenterPositionX() - bc.getCenterPositionX() > bc.getCenterPositionY() - BattleView.sc.getCenterPositionY()) {
                                Log.w("BattleView", "右を向く");
                                moveV_char((int) dxPerFrame_migiue, (int) (slo_migiue * -dxPerFrame_migiue));
                                if (bc.getId() == R.drawable.himesama_migi1)
                                    bc.changeId(R.drawable.himesama_migi3, 6, 10);
                                else
                                    bc.changeId(R.drawable.himesama_migi1, 6, 10);
                                himesamaVecter = "migi";
                            } else {
                                Log.w("BattleView", "上を向く");
                                moveV_char((int) dxPerFrame_migiue, (int) (slo_migiue * -dxPerFrame_migiue));
                                if (bc.getId() == R.drawable.himesama_usiro1)
                                    bc.changeId(R.drawable.himesama_usiro3, 6, 10);
                                else
                                    bc.changeId(R.drawable.himesama_usiro1, 6, 10);
                                himesamaVecter = "usiro";
                            }
                        } else {  //プレイヤーより左上をタッチ
                            if (bc.getCenterPositionX() - BattleView.sc.getCenterPositionX() > bc.getCenterPositionY() - BattleView.sc.getCenterPositionY()) {
                                Log.w("BattleView", "左を向く");
                                moveV_char((int) -dxPerFrame_hidariue, (int) (slo_hidariue * -dxPerFrame_hidariue));
                                if (bc.getId() == R.drawable.himesama_hidari1)
                                    bc.changeId(R.drawable.himesama_hidari3, 6, 10);
                                else
                                    bc.changeId(R.drawable.himesama_hidari1, 6, 10);
                                himesamaVecter = "hidari";
                            } else {
                                Log.w("BattleView", "上を向く");
                                moveV_char((int) -dxPerFrame_hidariue, (int) (slo_hidariue * -dxPerFrame_hidariue));
                                if (bc.getId() == R.drawable.himesama_usiro1)
                                    bc.changeId(R.drawable.himesama_usiro3, 6, 10);
                                else
                                    bc.changeId(R.drawable.himesama_usiro1, 6, 10);
                                himesamaVecter = "usiro";
                            }
                        }
                    }
                }
            }
        }

        //姫追跡
        public void chaseHimesamaMove(FrameControl mcf) {
            if (mcf.getJudgeResumption()) {
                double hy_ty = bc.getCenterPositionY() - BattleView.mc.getCenterPositionY();//鳥と姫の距離ｙ
                double hx_tx = bc.getCenterPositionX() - BattleView.mc.getCenterPositionX();//鳥と姫の距離x
                double ty_hy = BattleView.mc.getCenterPositionY() - bc.getCenterPositionX();//
                double tx_hx = BattleView.mc.getCenterPositionX() - bc.getCenterPositionX();//
                double len_migisita = Math.sqrt(ty_hy * ty_hy + tx_hx * tx_hx);     //斜辺の距離
                double len_hidarisita = Math.sqrt(ty_hy * ty_hy + hx_tx * hx_tx);   //鳥を基点
                double len_migiue = Math.sqrt(hy_ty * hy_ty + tx_hx * tx_hx);       //
                double len_hidariue = Math.sqrt(hy_ty * hy_ty + hx_tx * hx_tx);     //
                double dvPerFrame_migisita = len_migisita / v_char;        //斜辺を移動量進むのに
                double dvPerFrame_hidarisita = len_hidarisita / v_char;    //かかるフレーム秒
                double dvPerFrame_migiue = len_migiue / v_char;            //
                double dvPerFrame_hidariue = len_hidariue / v_char;        //
                double dxPerFrame_migisita = tx_hx / dvPerFrame_migisita;        //タッチした座標までの
                double dxPerFrame_hidarisita = hx_tx / dvPerFrame_hidarisita;    //距離xを斜辺移動の
                double dxPerFrame_migiue = tx_hx / dvPerFrame_migiue;            //フレーム秒あたりに
                double dxPerFrame_hidariue = hx_tx / dvPerFrame_hidariue;        //進む距離
                double slo_migisita = ty_hy / tx_hx;      //斜辺の傾き
                double slo_hidarisita = ty_hy / hx_tx;    //
                double slo_migiue = hy_ty / tx_hx;        //
                double slo_hidariue = hy_ty / hx_tx;      //

                if (BattleView.mc.getCenterPositionY() > bc.getCenterPositionY()) {   //鳥より下に姫
                    if (BattleView.mc.getCenterPositionX() > bc.getCenterPositionX()) { //鳥より右下に姫
                        if (BattleView.mc.getCenterPositionX() - bc.getCenterPositionX() > BattleView.mc.getCenterPositionY() - bc.getCenterPositionY()) {
                            Log.w("BattleView", "右を向く");
                            moveV_char((int) dxPerFrame_migisita, (int) (slo_migisita * dxPerFrame_migisita));
                            if (bc.getId() == R.drawable.tori_migi1)
                                bc.changeId(R.drawable.tori_migi3, 6, 10);
                            else
                                bc.changeId(R.drawable.tori_migi1, 6, 10);
                        } else {
                            Log.w("BattleView", "下を向く");
                            moveV_char((int) dxPerFrame_migisita, (int) (slo_migisita * dxPerFrame_migisita));
                            if (bc.getId() == R.drawable.tori_syoumen1)
                                bc.changeId(R.drawable.tori_syoumen3, 6, 10);
                            else
                                bc.changeId(R.drawable.tori_syoumen1, 6, 10);
                        }
                    } else {  //鳥より左下に姫
                        if (bc.getCenterPositionX() - BattleView.mc.getCenterPositionX() > BattleView.mc.getCenterPositionY() - bc.getCenterPositionY()) {
                            Log.w("BattleView", "左を向く");
                            moveV_char((int) -dxPerFrame_hidarisita, (int) (slo_hidarisita * dxPerFrame_hidarisita));
                            if (bc.getId() == R.drawable.tori_hidari1)
                                bc.changeId(R.drawable.tori_hidari3, 6, 10);
                            else
                                bc.changeId(R.drawable.tori_hidari1, 6, 10);
                        } else {
                            Log.w("BattleView", "下を向く");
                            moveV_char((int) -dxPerFrame_hidarisita, (int) (slo_hidarisita * dxPerFrame_hidarisita));
                            if (bc.getId() == R.drawable.tori_syoumen1)
                                bc.changeId(R.drawable.tori_syoumen3, 6, 10);
                            else
                                bc.changeId(R.drawable.tori_syoumen1, 6, 10);
                        }
                    }
                } else {    //鳥より上に姫
                    if (BattleView.mc.getCenterPositionX() > bc.getCenterPositionX()) { //プレイヤーより右上をタッチ
                        if (BattleView.mc.getCenterPositionX() - bc.getCenterPositionX() > bc.getCenterPositionY() - BattleView.mc.getCenterPositionY()) {
                            Log.w("BattleView", "右を向く");
                            moveV_char((int) dxPerFrame_migiue, (int) (slo_migiue * -dxPerFrame_migiue));
                            if (bc.getId() == R.drawable.tori_migi1)
                                bc.changeId(R.drawable.tori_migi3, 6, 10);
                            else
                                bc.changeId(R.drawable.tori_migi1, 6, 10);
                        } else {
                            Log.w("BattleView", "上を向く");
                            moveV_char((int) dxPerFrame_migiue, (int) (slo_migiue * -dxPerFrame_migiue));
                            if (bc.getId() == R.drawable.tori_usiro1)
                                bc.changeId(R.drawable.tori_usiro3, 6, 10);
                            else
                                bc.changeId(R.drawable.tori_usiro1, 6, 10);
                        }
                    } else {  //プレイヤーより左上をタッチ
                        if (bc.getCenterPositionX() - BattleView.mc.getCenterPositionX() > bc.getCenterPositionY() - BattleView.mc.getCenterPositionY()) {
                            Log.w("BattleView", "左を向く");
                            moveV_char((int) -dxPerFrame_hidariue, (int) (slo_hidariue * -dxPerFrame_hidariue));
                            if (bc.getId() == R.drawable.tori_hidari1)
                                bc.changeId(R.drawable.tori_hidari3, 6, 10);
                            else
                                bc.changeId(R.drawable.tori_hidari1, 6, 10);
                        } else {
                            Log.w("BattleView", "上を向く");
                            moveV_char((int) -dxPerFrame_hidariue, (int) (slo_hidariue * -dxPerFrame_hidariue));
                            if (bc.getId() == R.drawable.tori_usiro1)
                                bc.changeId(R.drawable.tori_usiro3, 6, 10);
                            else
                                bc.changeId(R.drawable.tori_usiro1, 6, 10);
                        }
                    }
                }
            }
        }

        //乗馬移動
        public void ridingMove(FrameControl mcf){
            if(bc.getId() == R.drawable.goei_jouba){
                bc.setPosition((int)BattleView.horse.getPositionX() + 40,
                        (int)BattleView.horse.getPositionY() - 50);
            }else if(bc.getId() == R.drawable.himesama_jouba){
                bc.setPosition((int)BattleView.horse.getCenterPositionX() -50,
                        (int)BattleView.horse.getPositionY() - 50);
            }
        }
    }


    //--------------------------------------------------------------//

    //攻撃バリエーション
    public class AttackVariation {
        private FrameControl fc = new FrameControl();

        public FrameControl control(){
            return fc;
        }
        //下にストレートショット
        public void straightShot_under(FrameControl acf){
            if(acf.getJudgeResumption()) {
                setPositionBulletX(0, (int) (bc.getPositionX() + (bc.getBitmapWidth() / 2)));

                if ((getPositionBulletY(0) > BitmapCreate.height)
                        || getPositionBulletY(0) == 0.0) {
                    setPositionBulletY(0, (int) (bc.getPositionY() + bc.getBitmapHeight()));
                }
                movePositionBulletY(0, (int) vy_bullet);
            }
        }
        //下に連続ショット
        public void continuityStraightShot_under(FrameControl acf){
            bulletX.set(0,bc.getPositionX());
            for(int i=0;i<bulletY.size();i++) {
                movePositionBulletY(i,10);
            }
            if(acf.getJudgeResumption()){
                bulletX.add(bc.getPositionX());
                bulletY.add(bc.getPositionY());
            }
        }

        public void circleShot(FrameControl acf){
            if(acf.getJudgeResumption()) {
                double radian = Math.toRadians(counter % 360);
                double sin = Math.sin(radian);
                double cos = Math.cos(radian);
                bulletX.set(0, (circleX + moveRadiusX * cos));
                bulletY.set(0, (circleY + moveRadiusY * sin));
                counter += 5;
                moveRadiusY++;
                circleY++;
            }
        }
    }

    //-----------------------------------------------------------//

    //防御バリエーション
    public class DefenseVariation{
        private FrameControl fc = new FrameControl();

        public FrameControl control(){
            return fc;
        }
    }

    //------------------------------------------------------------//

    //移動速度設定
    public void setV_char(int v_char){
        this.v_char = (double)v_char;
    }
    //移動速度xy設定
    public void setV_char(int vx_char, int vy_char){
        setVx_char(vx_char);
        setVy_char(vy_char);
    }
    public void setVx_char(int vx_char){
        this.vx_char = (double)vx_char;
    }
    public void setVy_char(int vy_char){
        this.vy_char = (double)vy_char;
    }

    //円移動中心座標設定
    public void setCircle(int x, int y){
        this.circleX = (double)x;
        this.circleY = (double)y;
    }


    //移動範囲取得
    public double getVx_char(){
        return vx_char;
    }
    public double getVy_char(){
        return vy_char;
    }

    //座標移動
    public void moveV_char(){
        moveVx_char((int)vx_char);
        moveVy_char((int)vy_char);
    }
    public void moveV_char(int vx_char, int vy_char){
        moveVx_char(vx_char);
        moveVy_char(vy_char);
    }
    public void moveVx_char(int x){
        bc.setPositionX( (int) (bc.getPositionX() + x) );
    }
    public void moveVy_char(int y){
        bc.setPositionY( (int) (bc.getPositionY() + y) );
    }



    //--------------------------------------------------------------------//


    //弾発射座標設定
    public void setPositionBullet(int number, int bulletX, int bulletY){
        setPositionBulletX(number,bulletX);
        setPositionBulletY(number,bulletY);
    }
    public void setPositionBulletX(int number, int bulletX){
        this.bulletX.add(number,(double)bulletX);
    }
    public void setPositionBulletY(int number,int bulletY){
        this.bulletY.add(number,(double)bulletY);
    }

    //弾座標取得
    public double getPositionBulletX(int number){
        return bulletX.get(number);
    }
    public double getPositionBulletY(int number){
        return bulletY.get(number);
    }

    public ArrayList<Double> getPositionBulletX(){
        return bulletX;
    }
    public ArrayList<Double> getPositionBulletY(){
        return bulletY;
    }

    //弾座標移動
    public void movePositionBulletX(int number,int vx_bullet){
        bulletX.set(number, bulletX.get(number) + (double) vx_bullet);
    }
    public void movePositionBulletY(int number,int vy_bullet){
        bulletY.set(number, bulletY.get(number) + (double) vy_bullet);
    }


    //弾速設定
    public void setV_bullet(int vx_bullet, int vy_bullet){
        setVx_bullet(vx_bullet);
        setVy_bullet(vy_bullet);
    }
    public void setVx_bullet(int vx_bullet){
        this.vx_bullet = (double)vx_bullet;
    }
    public void setVy_bullet(int vy_bullet){
        this.vy_bullet = (double)vy_bullet;
    }

    //弾速取得
    public double getVx_bullet(){
        return vx_bullet;
    }
    public double getVy_bullet(){
        return vy_bullet;
    }


}
