package com.example.k.Honeymoon;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import java.util.Random;


/**
 * Created by K on 2018/02/28.
 */

//  ビットマップを生成するクラス
public class BitmapCreate {
    Random random = new Random();
    //---キャンバスサイズは全てのビットマップ共通---
    protected static int width;    //キャンバスサイズ　幅
    protected static int height;   //キャンバスサイズ　高さ
    //----------------------------------------------
    private Bitmap bitmapMoto;  //加工前ビットマップ
    private Bitmap bitmap;      //完成ビットマップ
    private int bitmapWidth;    //ビットマップサイズ　幅
    private int bitmapHeight;   //ビットマップサイズ 高さ
    private int id;             //画像
    private double x;            //座標
    private double y;            //座標



    //共通の画面サイズを最初にセット
    public static void setDisplaySize(int width, int height){
        BitmapCreate.width = width;
        BitmapCreate.height = height;
    }

    //画像の設定
    public void setId(int id){
        this.id = id;
    }

    //ビットマップの生成
    public void setBitmap(int ratioW, int ratioH){   //引数は画面サイズに対する比率
        bitmapMoto = BitmapFactory.decodeResource
                (BattleView.context.getResources(),id);
        bitmap = Bitmap.createScaledBitmap(bitmapMoto,
                width / ratioW, height / ratioH, false);
        bitmapWidth = bitmap.getWidth();
        bitmapHeight = bitmap.getHeight();
    }

    public void changeId(int id , int ratioW, int ratioH){
        this.id = id;
        setBitmap(ratioW, ratioH);
    }


    //座標設定
    public void setPosition(int x, int y){
        setPositionX(x);
        setPositionY(y);
    }
    public void setPositionX(int x){
        this.x = (double)x;
    }
    public void setPositionY(int y){
        this.y = (double)y;
    }

//    public void setCenterPosition(int x, int y){
//        setCenterPositionX(x);
//        setCenterPositionY(y);
//    }
//    public void setCenterPositionX(int x){
//        this.x = (double)x - bitmapWidth / 3;
//    }
//    public void setCenterPositionY(int y){
//        this.y = (double)y - bitmapHeight / 3;
//    }

    //座標乱数設定
    public void setRandomPosition(){
        setRandomPositionX();
        setRandomPositionY();
    }
    public void setRandomPositionX(){
        int width = BitmapCreate.width - bitmapWidth;
        x = random.nextInt(width);
    }
    public void setRandomPositionY(){
        int height = BitmapCreate.height - bitmapHeight;
        y = random.nextInt(height);
    }

    //ビットマップ取得
    public Bitmap getBitmap(){
        return bitmap;
    }

    //Id取得
    public int getId(){
        return id;
    }

    //ビットマップサイズ取得
    public int getBitmapWidth(){
        return bitmapWidth;
    }
    public int getBitmapHeight(){
        return bitmapHeight;
    }

    //  座標取得
    public double getPositionX() {
        return x;
    }
    public double getPositionY(){
        return y;
    }

    //  中心座標取得
    public double getCenterPositionX(){//タッチ移動の際に使う
        return x + bitmapWidth / 2;
    }
    public double getCenterPositionY(){
        return y + bitmapHeight / 2;
    }
}
