/*
*  File: LED_ping.c
*  功能: 乒乓灯
*/

#include "io51.h"
void delay(int x);
int key= 0;
int m;

/*乒乓灯亮法*/
int j_ping= 0x81;
int j_pong= 0x18;
char code led_ping[]={
	0x81,0x42,0x24,0x18 // 外=>內
};
char code led_pong[]={
	0x18,0x24,0x42,0x81 // 內=>外
};

/* 亮法順序:
*  LED 0,7(led_ping[0],led_pong[3]) ==> 0x81 
*  LED 1,6(led_ping[1],led_pong[2]) ==> 0x42
*  LED 2,5(led_ping[2],led_pong[1]) ==> 0x24
*  LED 3,4(led_ping[3],led_pong[0]) ==> 0x18
*/

/*主程式*/
void main(){
   int i,m;
   while(key==0){
	   for(i=0;i<3;i++){
		   P1= j_ping;
		   delay(2000);
		   j_ping=led_ping[i];
	   }
	   for(m=0;m<3;m++){
		   P1= j_pong;
		   delay(2000);
		   j_pong=led_pong[m];
	   }
	   j_ping= 0x81;
   }   
}

/*delay time*/
void delay(int x){
	for(m=0;m<x;m++);
}