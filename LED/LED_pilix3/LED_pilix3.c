/*
*  File: LED_pilix3.c
*  功能: 運行三回霹靂灯
*/

#include "io51.h"
void delay(int x);
int key=3;
int j= 0xfe;
int m;

/*主程式*/
void main(){
	char k,i,m;
	/*亮3回*/
	for(k=1;k<=key;k++){
		/*亮法:LED 0~7*/
		for(i=1;i<8;i++){
			P1= j;
			delay(1000);
			j<<= 1; // j => 左旋1位元
			j= j+1;
		}
		/*亮法:LED 7~0*/
		for(m=1;m<8;m++){
			P1= j;
			delay(1000);
			j>>=1; // j => 右旋1位元
			j= j|80;
		}
		j=0xfe;
	}
}

/*delay time*/
void delay(int x){
	for(m;m<=x;m++);
}