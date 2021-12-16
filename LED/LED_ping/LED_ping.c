/*
*  File: LED_ping.c
*  功能: 乒乓灯
*/
#include "io51.h"
void delay(int x);


int j_ping= 0x7E; //設定第一個位置是0x7E
/*乒乓灯亮法*/
char led_ping[]={
	0x7E,0xBD,0xDB,0xE7,0xDB,0xBD,0X7E 
};

/* 亮法順序:
*  LED 0,7 ==> 0x7E 
*  LED 1,6 ==> 0xBD
*  LED 2,5 ==> 0xDB
*  LED 3,4 ==> 0xE7
*/

/*主程式*/
void main(){
   int i;
   while(1){
       /*8顆LED*/
	   for(i=0;i<7;i++){
		   P1= j_ping;
		   delay(10000); //delay 10sec
		   j_ping=led_ping[i];
	   }
   }   
}

/*delay time*/
void delay(int x){
    int m;
    for(m=0;m<x;m++);
}