package com.example.k.Honeymoon;

import android.util.Log;

import java.util.Random;

/**
 * Created by K on 2018/03/01.
 */

public class Scout extends Enemy {
    private int moveVariationSwitchNum;
    Random random = new Random();

    public Scout(int id){
        setId(id);
        setBitmap(6,10);
        mcf.setStoppingTime((char) 200);
        moveVariationSwitch();
    }

    private void moveVariationSwitch(){
        int num = random.nextInt(7);
        //int num = 6;
        int parameter = random.nextInt(10);
        int paraPositionX = random.nextInt(width);
        int paraPositionY = random.nextInt(height);
        moveVariationSwitchNum = num;
        if(parameter == 0){
            parameter = 1;
        }
        if(num < 4 || num == 6){
            av.setV_char(parameter);
        }
        switch (num){
            case 0:
                setPosition(paraPositionX, height + 100);
                break;
            case 1:
                setPosition(paraPositionX, -100);
                break;
            case 2:
                setPosition(width + 100, paraPositionY);
                break;
            case 3:
                setPosition(-100, paraPositionY);
                break;
            case 4:
                av.setCircle(paraPositionX, -100);
                break;
            case 5:
                av.setCircle(paraPositionX, height + 100);
                break;
            case 6:
                int number = random.nextInt(4);
                if(number == 0){
                    setPosition(paraPositionX, height + 100);
                }else if(number == 1){
                    setPosition(paraPositionX, -100);
                }else if(number == 2){
                    setPosition(width + 100, paraPositionY);
                }else{
                    setPosition(-100, paraPositionY);
                }
                break;
            default:
                break;
        }
//        if(num < 4 || num == 6){
//            av.setV_char(parameter);
//        }else if(num == 4){
//            setPosition(paraPositionX, -100);
//        }else{
//            setPosition(paraPositionX, height + 100);
//        }
    }

    @Override
    public void move() {
        switch(moveVariationSwitchNum){
            case 0:
                Log.w("Scout","upwardMove");
                av.new MoveVariation().upwardMove(mcf);
                break;
            case 1:
                Log.w("Scout","downMove");
                av.new MoveVariation().downMove(mcf);
                break;
            case 2:
                Log.w("Scout","leftMove");
                av.new MoveVariation().leftMove(mcf);
                break;
            case 3:
                Log.w("Scout","rightMove");
                av.new MoveVariation().rightMove(mcf);
                break;
            case 4:
                Log.w("Scout","sinCurveMove_down");
                av.new MoveVariation().sineCurveMove_down(mcf);
                break;
            case 5:
                Log.w("Scout","sinCurveMove_upward");
                av.new MoveVariation().sineCurveMove_upward(mcf);
                break;
            case 6:
                Log.w("Scout","chaseHimesamaMove");
                Log.d("Scout",getPositionX()+":"+getPositionY());
                av.new MoveVariation().chaseHimesamaMove(mcf);
                break;
            default:
                break;
        }
    }

    @Override
    public void attack(){

    }
}
