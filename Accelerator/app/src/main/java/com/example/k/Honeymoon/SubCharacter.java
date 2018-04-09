package com.example.k.Honeymoon;

/**
 * Created by K on 2018/03/03.
 */

public class SubCharacter extends Player {
    public SubCharacter(int id){
        setId(id);
        setBitmap(6,10);
        setPosition(width / 3, height - 500);
        //移動範囲設定
        av.setV_char(5);
        //弾速と弾の始点をキャラクターの座標にセット
        av.setV_bullet(30, 30);
        mcf.setStoppingTime((char)64);
    }

    @Override
    public void move(){
        if(BattleView.checkGameEnd){
            av.new MoveVariation().ridingMove(mcf);
        }else {
            av.new MoveVariation().touchMove(mcf);
        }
    }

    @Override
    public void attack(){

    }
}
