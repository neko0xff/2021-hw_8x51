/*
*  FilE：keybord01.C									
*  功能:可控制 4x4 矩陣式鍵盤的輸入並將其顯示於七段顯示器上				
*/

#include "io51.h"

/* 0 ~ F 的顯示碼 */              
char seg7[]={
	0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
	0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71
};
/* 按鍵 0 ~ F 的按鍵碼*/          		
char keys[]={
	0xEE,0xDE,0xBE,0x7E,0xED,0xDD,0xBD,0x7D,
    0xEB,0xDB,0xBB,0x7B,0xE7,0xD7,0xB7,0x77
};    	
char i;
char key_code,test_code=0xF0;
char n1=0,n2=4,n3=8,n4=12;
void show_key(char scan_signal,char n);

void main(){

/*同時點亮 4 顆七段顯示器的 'g' 節段(七段顯示碼顯示:`-`)*/
P1=0x40;				
P2=0x0F;				
	
while(1){
	P3=test_code;  // 經由 P3 送出測試信號 0xF0
	key_code=P3;  //經由 P3 讀取按鍵碼 
	/* 如果有按鍵按下時, 即 key_code!=0xF0  */
 	if(key_code!=0xF0){		
  		key_code=P3; //再次的經由 P3 讀取按鍵碼 
		/* 如果有按鍵按下時, 即 key_code!=0xF0  */
	 	if(key_code!=0xF0){
            /*開始逐一掃描, 以判斷是那一鍵按下*/				
  	 		show_key(0xFE,n1); //0~3
  	 		show_key(0xFD,n2); //4~7
  	 		show_key(0xFB,n3); //8~b
  	 		show_key(0xF7,n4); //C~F
  	 	}
	}                           
 }
}

/*輸出到七段顯示器*/
void show_key(char scan_signal,char n){
	P3=scan_signal;	//經由 P3 送出測試信號 	
	key_code=P3;	//經由 P3 讀取按鍵碼 
	for (i=n;i<n+4;i++){
		/*找出按鍵碼相對應的七段顯示碼 */
		if(key_code==keys[i]){		
  			P1=seg7[i];	//將七段顯示碼顯示於七段顯示器上
  	  		break;
  		}
	}
}

