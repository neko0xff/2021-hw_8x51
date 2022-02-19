/*
*   File: beep01.c
*   功能: 蜂鳴器發出測試
*/

#include "io51.h"
#include "s51pgm.h"

unsigned char code song[]={
	1,1,1,
	3,2,1,
	3,3,3,
	5,4,3,
	5,4,3,
    2
};

unsigned char code tone[11]={121,108,102,91,86,77,68,61,57,51,45}; //音譜定義 

//delay 1ms
void delay_1ms(int x){
   int i,j;
   for(i=0;i<x;i++){
	   for(j=0;j<120;j++);
   }
}

//delay 8.15us
void delay_8us15(unsigned char count){
	unsigned char j;
	for(j=0;j<count;j++);
}

//delay 16us
void delay_16us(int count){
	int j;
	for(j=0;j<count;j++);
}

/*主程式*/
void main(){
	unsigned char i,j,k;
	
	for(i=0;i<3;i++){
		for(j=0;j<12;j++){
			for(k=0;k<50;k++){
				B1=0; //ON
				delay_8us15(tone[song[i]]);
				B1=1; //OFF
			  delay_8us15(tone[song[i]]);
			}
		}
	}
}