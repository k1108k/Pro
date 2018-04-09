package com.example.k.Honeymoon;

/**
 * Created by K on 2018/03/03.
 */

public class MainCharacter extends Player {
    public MainCharacter(int id){
        setId(id);
        setBitmap(6,10);
        setPosition(width / 2, height - 300);
        //移動範囲設定
        av.setV_char(5);
        //弾速と弾の始点をキャラクターの座標にセット
        av.setV_bullet(30, 30);
        mcf.setStoppingTime((char)106);
        //ecf.setStoppingTime((char)200);
    }

    @Override
    public void move(){
//            av.new MoveVariation().sineCurveMove_under(mcf);
//            av.new MoveVariation().leftAndRightMove(mcf);
        if(BattleView.checkGameEnd){
            av.new MoveVariation().ridingMove(mcf);
        }else{
            av.new MoveVariation().chaseGoeiMove(mcf);
        }
    }

    @Override
    public void attack(){

    }

}
