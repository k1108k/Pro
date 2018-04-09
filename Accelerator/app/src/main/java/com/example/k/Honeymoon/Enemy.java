package com.example.k.Honeymoon;

/**
 * Created by K on 2018/02/28.
 */

public abstract class Enemy extends BitmapCreate implements Action {
    ActionVariation av = new ActionVariation(this);

    FrameControl mcf = av.new MoveVariation().control();//移動用フレームコントロールフィールド
    FrameControl acf = av.new AttackVariation().control();//攻撃用フレームコントロールフィールド
    FrameControl dcf = av.new DefenseVariation().control();//防御用フレームコントロールフィールド


    private boolean isLive=true;

    public boolean checkIsLive(){
        return isLive;
    }

    public void changeIsLiveToFalse(){
            isLive = false;
    }
}



