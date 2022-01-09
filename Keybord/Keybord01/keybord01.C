/*--------------------------------------------------------------------------------------*/
/*程式檔名：keypad.c									*/
/*											*/
/*											*/
/*本程式可控制 4x4 矩陣式鍵盤的輸入並將其顯示於七段顯示器上				*/
/*--------------------------------------------------------------------------------------*/
#include "io51.h"
                   
char 	seg7[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
	        0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};/* 0 ~ F 的顯示碼 */
          		
char	keys[]={0xee,0xde,0xbe,0x7e,0xed,0xdd,0xbd,0x7d,
                0xeb,0xdb,0xbb,0x7b,0xe7,0xd7,0xb7,0x77};/* 按鍵 0 ~ F 的按鍵碼	*/
            	
char	key_code,i,test_code=0xf0,n1=0,n2=4,n3=8,n4=12;

void 	show_key(char scan_signal,char n);

void main(){
	P1=0x40;				/*┐同時點亮 4 顆七段顯示器的 -('g' 節段)	*/
	P2=0x0F;				/*┘					*/
	while (1)	{
		P3=test_code;			/* 經由 P3 送出測試信號 0xf0 		*/
		key_code=P3;			/* 經由 P3 讀取按鍵碼 			*/
 		if (key_code!=0xf0){		/* 如果有按鍵按下時, 即 key_code!=0xf0  */
  			key_code=P3;		/* 再次的經由 P3 讀取按鍵碼 		*/
	 		if (key_code!=0xf0){	/* 如果有按鍵按下時, 即 key_code!=0xf0  */
  	 			show_key(0xfe,n1);/*┐開始逐一掃描, 以判斷		*/
  	 			show_key(0xfd,n2);/*│是那一鍵按下      		*/
  	 			show_key(0xfb,n3);/*│					*/
  	 			show_key(0xf7,n4);/*┘					*/ 
  	 		}
		}                           
 	}
}
void show_key(char scan_signal,char n){
	P3=scan_signal;				/* 經由 P3 送出測試信號 		*/
	key_code=P3;				/* 經由 P3 讀取按鍵碼 			*/
	for (i=n;i<n+4;i++){
		if (key_code==keys[i]){		/* 找出按鍵碼相對應的七段顯示碼 	*/
  			P1=seg7[i];		/* 將七段顯示碼顯示於七段顯示器上	*/
  	  		break;
  		}
	}
}

