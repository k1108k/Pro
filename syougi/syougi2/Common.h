//  ~Common�萔~

//  �f�o�b�N�p�}�N��
#define OK printf("�����܂ł�����");\
                 system("PAUSE");

#define N 9     //�ՖʃT�C�YN�~N



//  ��ԍ����蓖��
#define KARA 0   // ��Ȃ�
enum Player1{ // �v���C���[��ԍ�
    
    KYOUSYA_P  = 1,      //1
    KEIMA_P,              //2
    GIN_P,             //3
    KIN_P,                 //4
    GYOKU_P,                //5
    HISYA_P,          //6
    KAKU_P,         //7
    HU_P,                   //8
};
enum Player1_nari{	//player1�̐���	
	TOKIN_P = 21,	//21
	NARIGIN_P,		//22
	NARIKEI_P,		//23
	NARIKYOU_P,		//24
	RYU_P,			//25
	UMA_P,			//26
};

enum Computer {  // com��ԍ�
    KYOUSYA_C = 11,     //11
    KEIMA_C,       //12
    GIN_C,         //13
    KIN_C,          //14
    GYOKU_C,        //15
    KAKU_C,         //16
    HISYA_C,     //17
    HU_C,           //18
};
enum Comoputer_nari{	//Computer�̐���	
	TOKIN_C = 31,	//31
	NARIGIN_C,		//32
	NARIKEI_C,		//33
	NARIKYOU_C,		//34
	RYU_C,			//35
	UMA_C,			//36
};






#pragma once
