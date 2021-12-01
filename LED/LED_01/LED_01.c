/*
 * File: LED_01.c
 * 功能: 右至左移的跑馬灯
*/

#include "io51.h"
void delay(int x);
int j= 0xFE; //LED 0= 0xfe
int i,m;

/*主程式*/
void main(){
	while(1){
		/*點亮LED 0~7*/
		for(i=0;i<8;i++){
			P1= j; //給P1送出控制LED的信號
			delay(7000);
			j<<= 1; // j => 左旋1位元
			j= j+1;
		}
		j= 0xFE; //LED 0= 0xfe
	}
}

/*delay time*/
void delay(int x){
	for(m=0;m<x;m++);
}
