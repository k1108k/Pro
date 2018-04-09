#include"Common.h"

//	ãÓÇíuÇ≠ä÷êî
void Position_koma(int *count1,int *count2,int p1_poke[20],int p2_poke[20],int *which,int _koma[][N],int _row_i,int _col_i,int _row_dy,int _col_dx){
	//	éËãÓÉ|ÉPÉbÉgïœêîÇ…éÊÇ¡ÇΩãÓÇäiî[
	if(_koma[_row_dy][_col_dx] != KARA){
		switch(*which){		//	Ç«ÇøÇÁÇÃÉvÉåÉCÉÑÅ[Ç©îªíf		
		case 0:	//	player1Ç™ìGÇÃãÓÇéÊÇ¡ÇΩèÍçá
			switch(_koma[_row_dy][_col_dx]){
			case KYOUSYA_C:
			case KEIMA_C: 
			case GIN_C:  
			case KIN_C:
			case GYOKU_C:
			case HU_C:
				p1_poke[*count1] = _koma[_row_dy][_col_dx]-10;
				(*count1)++;
				break;
			case HISYA_C: 
			    p1_poke[*count1] = HISYA_P;
				(*count1)++;
				break;                                                    
            case KAKU_C:               
                p1_poke[*count1] = KAKU_P;
				(*count1)++;
				break;                       
			case TOKIN_C:
				p1_poke[*count1] = HU_P;
				(*count1)++;
				break;
			case NARIGIN_C:	
				p1_poke[*count1] = GIN_P;
				(*count1)++;
				break;
			case NARIKEI_C:		
				p1_poke[*count1] = KEIMA_P;
				(*count1)++;
				break;
			case NARIKYOU_C:	
				p1_poke[*count1] = KYOUSYA_P;
				(*count1)++;
				break;
			case RYU_C:		
				p1_poke[*count1] = HISYA_P;
				(*count1)++;
				break;
			case UMA_C:		
				p1_poke[*count1] = KAKU_P;
				(*count1)++;
				break;
            default:
                break;
			}
		case 1:	//	player2Ç™ìGÇÃãÓÇéÊÇ¡ÇΩèÍçá
			switch(_koma[_row_dy][_col_dx]){
			case KYOUSYA_P:
			case KEIMA_P: 
			case GIN_P:  
			case KIN_P:
			case GYOKU_P:
			case HU_P:
				p2_poke[*count2] = _koma[_row_dy][_col_dx]+10;
				(*count2)++;
				break;
			case HISYA_P: 
			    p2_poke[*count2] = HISYA_C;
				(*count2)++;
				break;                                                    
            case KAKU_P:               
                p2_poke[*count2] = KAKU_C;
				(*count2)++;
				break;                       
			case TOKIN_P:
				p2_poke[*count2] = HU_C;
				(*count2)++;
				break;
			case NARIGIN_P:	
				p2_poke[*count2] = GIN_C;
				(*count2)++;
				break;
			case NARIKEI_P:		
				p2_poke[*count2] = KEIMA_C;
				(*count2)++;
				break;
			case NARIKYOU_P:	
				p2_poke[*count2] = KYOUSYA_C;
				(*count2)++;
				break;
			case RYU_P:		
				p2_poke[*count2] = HISYA_C;
				(*count2)++;
				break;
			case UMA_P:		
				p2_poke[*count2] = KAKU_C;
				(*count2)++;
				break;
            default:
                break;
			}
		default:
            break;
		}	
	}

	//	ìGêwÇ…ãÓÇ™ì¸ÇÈÇ∆ê¨ÇÈ
	switch(*which){
	case 0:
		if(_row_dy < 3){
			switch(_koma[_row_i][_col_i]){
			case HU_P:
				_koma[_row_i][_col_i] = TOKIN_P;
				break;
			case GIN_P:
				_koma[_row_i][_col_i] = NARIGIN_P;
				break;
			case KEIMA_P:
				_koma[_row_i][_col_i] = NARIKEI_P;
				break;
			case KYOUSYA_P:
				_koma[_row_i][_col_i] = NARIKYOU_P;	//Ç±Ç±Ç©ÇÁ
				break;
			case HISYA_P:
				_koma[_row_i][_col_i] = RYU_P;
				break;
			case KAKU_P:
				_koma[_row_i][_col_i] = UMA_P;
				break;
			default:
				break;	
			}
		}
	case 1:
		if(_row_dy > 5){
			switch(_koma[_row_i][_col_i]){
			case HU_C:
				_koma[_row_i][_col_i] = TOKIN_C;
				break;
			case GIN_C:
				_koma[_row_i][_col_i] = NARIGIN_C;
				break;
			case KEIMA_C:
				_koma[_row_i][_col_i] = NARIKEI_C;
				break;
			case KYOUSYA_C:
				_koma[_row_i][_col_i] = NARIKYOU_C;	
				break;
			case HISYA_C:
				_koma[_row_i][_col_i] = RYU_C;
				break;
			case KAKU_C:
				_koma[_row_i][_col_i] = UMA_C;
				break;
			default:
				break;	
			}
		}
	default:
		break;	
	}
	//	ãÓÇíuÇ´ä∑Ç¶ÇÈ
	_koma[_row_dy][_col_dx] = _koma[_row_i][_col_i];
	_koma[_row_i][_col_i] = KARA;

}