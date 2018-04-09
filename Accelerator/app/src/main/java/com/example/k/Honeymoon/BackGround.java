package com.example.k.Honeymoon;

/**
 * Created by K on 2018/02/28.
 */

//背景と設置物の設定クラス
public final class BackGround extends BitmapCreate {
    ActionVariation av = new ActionVariation(this);
    FrameControl mcf = av.new MoveVariation().control();

    public BackGround(int id, int ratioW, int ratioH, int x, int y){
        setId(id);//セットする画像
        setBitmap(ratioW, ratioH);//画面サイズに対する比率を設定
        setPosition(x,y);//画像の位置を設定
    }

    public BackGround(int id, int ratioW, int ratioH, int x, int y, int v){
        setId(id);//セットする画像
        setBitmap(ratioW, ratioH);//画面サイズに対する比率を設定
        setPosition(x,y);//画像の位置を設定
        av.setV_char(v);//移動する設置物の移動速度設定
        mcf.setStoppingTime((char)64);
    }

    public void move(){
        av.new MoveVariation().leftMove(mcf);
    }
}
