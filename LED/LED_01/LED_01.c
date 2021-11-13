/*
 * File: LED_01.c
 * 功能: 右至左移的跑馬灯
*/

#include "io51.h"
void delay(int x);
int key= 0; 
int j= 0xfe; //LED 0= 0xfe
int i,m;

/*主程式*/
void main(){
	/*如果key=0,則重置*/
	while(key==0){
		/*點亮LED 0~7*/
		for(i=1;i<8;i++){
			P1= j; //給P1送出控制LED的信號
			delay(1000);
			j<<= 1; // j => 左旋1位元
			j= j+1;
		}
		j= 0xfe; //LED 0= 0xfe
	}
}

/*delay time*/
void delay(int x){
	for(m=0;m<x;m++);
}