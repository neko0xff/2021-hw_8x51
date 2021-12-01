/*
*  File: LED_pilix3.c
*  功能: 運行三回霹靂灯
*/

#include "io51.h"
void delay(int x);
int j= 0xfe;
int i,x;
int m;

/*主程式*/
void main(){
	/*亮3回*/
	while(1){
		j=0xfe;
		  /*亮法:LED 0~7*/
		  for(i=0;i<8;i++){
			 P1= j;
			 delay(10000);
			 j<<= 1; // j => 左旋1位元
			 j= j+1;
		  }
		 /*亮法:LED 7~0*/
		 for(x=8;x>0;x--){
			P1= j;
			delay(10000);
			j>>=1; // j => 右旋1位元
			j= j|0x80;
		 }
		
	}
	
}

/*delay time*/
void delay(int x){
	for(m=0;m<x;m++);
}