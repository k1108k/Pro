package com.example.k.Honeymoon;

/**
 * Created by K on 2018/03/01.
 */

//フレームの時間をコントロールするクラス
public class FrameControl {
    private char oneFrameTime;
    private char stoppingTime;


    //フレーム停止時間設定
    public void setStoppingTime(char time){
        stoppingTime = time;
    }

    public char getOneFrameTime(){
        return oneFrameTime += BattleView.ONE_FRAME_TIME;
    }

    public boolean getJudgeResumption(){

        if(getOneFrameTime() / stoppingTime > 0) {
            oneFrameTime = 0;
            return true;
        }
        return false;
    }
}
