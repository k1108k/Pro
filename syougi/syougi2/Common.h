//  ~Common定数~

//  デバック用マクロ
#define OK printf("ここまでおｋよ");\
                 system("PAUSE");

#define N 9     //盤面サイズN×N



//  駒番号割り当て
#define KARA 0   // 駒なし
enum Player1{ // プレイヤー駒番号
    
    KYOUSYA_P  = 1,      //1
    KEIMA_P,              //2
    GIN_P,             //3
    KIN_P,                 //4
    GYOKU_P,                //5
    HISYA_P,          //6
    KAKU_P,         //7
    HU_P,                   //8
};
enum Player1_nari{	//player1の成駒	
	TOKIN_P = 21,	//21
	NARIGIN_P,		//22
	NARIKEI_P,		//23
	NARIKYOU_P,		//24
	RYU_P,			//25
	UMA_P,			//26
};

enum Computer {  // com駒番号
    KYOUSYA_C = 11,     //11
    KEIMA_C,       //12
    GIN_C,         //13
    KIN_C,          //14
    GYOKU_C,        //15
    KAKU_C,         //16
    HISYA_C,     //17
    HU_C,           //18
};
enum Comoputer_nari{	//Computerの成駒	
	TOKIN_C = 31,	//31
	NARIGIN_C,		//32
	NARIKEI_C,		//33
	NARIKYOU_C,		//34
	RYU_C,			//35
	UMA_C,			//36
};






#pragma once
