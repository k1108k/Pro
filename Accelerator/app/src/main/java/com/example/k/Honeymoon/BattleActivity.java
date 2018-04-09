package com.example.k.Honeymoon;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.MotionEvent;

public class BattleActivity extends AppCompatActivity {
    private BattleView bv;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_battle);
        setContentView(bv = new BattleView(this));
    }

    @Override
    public boolean onTouchEvent(MotionEvent event){
        switch(event.getAction()){
            case MotionEvent.ACTION_UP:
                BattleView.touch_x = bv.sc.getCenterPositionX();
                BattleView.touch_y = bv.sc.getCenterPositionY();
                BattleView.isTouched = false;
                break;
            case MotionEvent.ACTION_DOWN:
            case MotionEvent.ACTION_MOVE:
                double x = event.getX(); //x座標を取得
                double y = event.getY(); //y座標を取得
                bv.getTouchPoint(x, y);
                BattleView.isTouched = true;
                break;
            default:
                break;
        }
        return true;
    }
}
