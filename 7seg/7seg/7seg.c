/*
 * File: 7seg.c
 * 功能: 用7段顯示器輸出0~F
*/

#include "io51.h"
void delay(int s);

/*7段顯示器顯示碼*/
char seg7[]={
   0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D, //0~7
   0x7F,0x6F,0x77,0x39,0x5E,0x79,0x71  //8~F
};

/*主程式*/
void main(){
   char i;
   P2= 0x0F; //啟用所有的7段顯示器(X4)
   /*重復運行*/
   while(1){
	   /*從P1輸出全部的7段顯示器顯示碼*/
	   for(i=0;i<16;i++){
		   P1=seg7[i]; 
		   delay(20000); //delay 2sec
	   }
   }
}

/*delay time*/
void delay(int s){
	int m;
	for(m=0;m<s;m++);
}