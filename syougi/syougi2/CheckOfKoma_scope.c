#include"Common.h"

//  駒能力の範囲内の移動かチェックする関数
int CheckOfKoma_scope(int _koma[][N], int _row_i, int _col_i, int _row_dy, int _col_dx) {
    int i,j;
    int dy[] = { -1 , -1 , -1 , 0 , 1 , 1 ,  1 , 0 };   //  マス方向 左上から時計周り
    int dx[] = { -1 ,  0 ,  1  , 1 , 1 , 0 , -1, -1 };  //  
    //  iの数　上「１」　下「５」　左「７」　右「３」　左上「０」　右上「２」　右下「４」　左下「６」

    switch (_koma[_row_i][_col_i]) {
    case HU_P:
        if (_row_dy == _row_i + dy[1] && _col_dx == _col_i ) { //  ！訂正箇所　歩はチェックいらない
            return 0;
        }
        break;
    case HU_C:
        if (_row_dy == _row_i + dy[5] && _col_dx == _col_i) { //  ！訂正箇所　歩はチェックいらない
            return 0;
        }
        break;
    case KYOUSYA_P:
        if (_col_dx == _col_i && _row_dy < _row_i) {
            return 0;
        }
        break;
    case  KYOUSYA_C:
        if (_col_dx == _col_i && _row_dy > _row_i) {
            return 0;
        }
        break;
    case KEIMA_P:
        if ((_col_dx == _col_i - 1 && _row_dy == _row_i - 2) ||
            (_col_dx == _col_i + 1 && _row_dy == _row_i - 2)) {
            return 0;
        }
        break;
    case KEIMA_C:
        if ((_col_dx == _col_i - 1 && _row_dy == _row_i + 2) ||
            (_col_dx == _col_i + 1 && _row_dy == _row_i + 2)) {
            return 0;
        }
        break;
    case GIN_P:
        if ((_row_dy == _row_i + dy[0] && _col_dx == _col_i + dx[0]) ||
            (_row_dy == _row_i + dy[1] && _col_dx == _col_i + dx[1]) ||
            (_row_dy == _row_i + dy[2] && _col_dx == _col_i + dx[2]) ||
            (_row_dy == _row_i + dy[4] && _col_dx == _col_i + dx[4]) ||
            (_row_dy == _row_i + dy[6] && _col_dx == _col_i + dx[6])) {             
            return 0;
        }
        break;
        case  GIN_C:
            if ((_row_dy == _row_i + dy[0] && _col_dx == _col_i + dx[0]) ||
                (_row_dy == _row_i + dy[5] && _col_dx == _col_i + dx[5]) ||
                (_row_dy == _row_i + dy[2] && _col_dx == _col_i + dx[2]) ||
                (_row_dy == _row_i + dy[4] && _col_dx == _col_i + dx[4]) ||
                (_row_dy == _row_i + dy[6] && _col_dx == _col_i + dx[6])) {
                return 0;
            }
            break;
        case  KIN_P:
		case TOKIN_P:
		case NARIGIN_P:
		case NARIKEI_P:
		case NARIKYOU_P:		
            if ((_row_dy == _row_i + dy[0] && _col_dx == _col_i + dx[0]) ||
                (_row_dy == _row_i + dy[1] && _col_dx == _col_i + dx[1]) ||
                (_row_dy == _row_i + dy[2] && _col_dx == _col_i + dx[2]) ||
                (_row_dy == _row_i + dy[3] && _col_dx == _col_i + dx[3]) ||
                (_row_dy == _row_i + dy[5] && _col_dx == _col_i + dx[5]) ||
                (_row_dy == _row_i + dy[7] && _col_dx == _col_i + dx[7])) {
                return 0;
            }
            break;
        case KIN_C:
		case TOKIN_C:
		case NARIGIN_C:
		case NARIKEI_C:
		case NARIKYOU_C:	
            if ((_row_dy == _row_i + dy[4] && _col_dx == _col_i + dx[4]) ||
                (_row_dy == _row_i + dy[1] && _col_dx == _col_i + dx[1]) ||
                (_row_dy == _row_i + dy[6] && _col_dx == _col_i + dx[6]) ||
                (_row_dy == _row_i + dy[3] && _col_dx == _col_i + dx[3]) ||
                (_row_dy == _row_i + dy[5] && _col_dx == _col_i + dx[5]) ||
                (_row_dy == _row_i + dy[7] && _col_dx == _col_i + dx[7])) {
                return 0;
            }
            break;
        case GYOKU_P:
        case GYOKU_C:
            if ((_row_dy == _row_i + dy[4] && _col_dx == _col_i + dx[4]) ||
                (_row_dy == _row_i + dy[1] && _col_dx == _col_i + dx[1]) ||
                (_row_dy == _row_i + dy[6] && _col_dx == _col_i + dx[6]) ||
                (_row_dy == _row_i + dy[3] && _col_dx == _col_i + dx[3]) ||
                (_row_dy == _row_i + dy[0] && _col_dx == _col_i + dx[0]) ||
                (_row_dy == _row_i + dy[2] && _col_dx == _col_i + dx[2]) ||
                (_row_dy == _row_i + dy[5] && _col_dx == _col_i + dx[5]) ||
                (_row_dy == _row_i + dy[7] && _col_dx == _col_i + dx[7])) {
                return 0;
            }
            break;   
        case HISYA_P:
        case HISYA_C:
            if (_row_dy == _row_i || _col_dx == _col_i) {
                return 0;
            }
            break;     
        case KAKU_P:
        case KAKU_C:
            for (i = 0;i <= 6;i+=2) {
                for (j = 1;j < 9;j++) {
                    if (_row_dy == _row_i + dy[i] * j && _col_dx == _col_i + dx[i] * j) {
                        return 0;
                    }
                }
            }
            break;  
		case RYU_P:
		case RYU_C:
			if (_row_dy == _row_i || _col_dx == _col_i) {
                return 0;
            }
			if ((_row_dy == _row_i + dy[4] && _col_dx == _col_i + dx[4]) ||
                (_row_dy == _row_i + dy[1] && _col_dx == _col_i + dx[1]) ||
                (_row_dy == _row_i + dy[6] && _col_dx == _col_i + dx[6]) ||
                (_row_dy == _row_i + dy[3] && _col_dx == _col_i + dx[3]) ||
                (_row_dy == _row_i + dy[0] && _col_dx == _col_i + dx[0]) ||
                (_row_dy == _row_i + dy[2] && _col_dx == _col_i + dx[2]) ||
                (_row_dy == _row_i + dy[5] && _col_dx == _col_i + dx[5]) ||
                (_row_dy == _row_i + dy[7] && _col_dx == _col_i + dx[7])) {
                return 0;
            }
			break;
		case UMA_P:
		case UMA_C:
			for (i = 0;i <= 6;i+=2) {
                for (j = 1;j < 9;j++) {
                    if (_row_dy == _row_i + dy[i] * j && _col_dx == _col_i + dx[i] * j) {
                        return 0;
                    }
                }
            }
			if ((_row_dy == _row_i + dy[4] && _col_dx == _col_i + dx[4]) ||
                (_row_dy == _row_i + dy[1] && _col_dx == _col_i + dx[1]) ||
                (_row_dy == _row_i + dy[6] && _col_dx == _col_i + dx[6]) ||
                (_row_dy == _row_i + dy[3] && _col_dx == _col_i + dx[3]) ||
                (_row_dy == _row_i + dy[0] && _col_dx == _col_i + dx[0]) ||
                (_row_dy == _row_i + dy[2] && _col_dx == _col_i + dx[2]) ||
                (_row_dy == _row_i + dy[5] && _col_dx == _col_i + dx[5]) ||
                (_row_dy == _row_i + dy[7] && _col_dx == _col_i + dx[7])) {
                return 0;
            }
			break;
        default:
            break;
    }
    return 1;
}
                        
                        
                      
                        
           
            
            

           
                 
                
                  
                 
              
            
                     
