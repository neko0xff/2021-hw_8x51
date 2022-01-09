/*
* File: 7seg_1234.c
* 功能: 7段顯示器輸出1234
*/

#include "io51.h"
void delay(int x);
void seg7En(int COM,int NUM);

char seg7_num[]={
	0x3F,0x06,0x5B,0x4F,0x66 //0,1,2,3,4
};
char seg7_COM[]={
    0x00,0x01,0x02,0x04,0x08 //CLEAR,COM1~4
};
char num[]={
	0,1,2,3,4
};

/*
   ex: 1,2,3,4
   1(0x06) => seg7_num[1]
   2(0x5B) => seg7_num[2]
   3(0x4F) => seg7_num[3]
   4(0x66) => seg7_num[4]
*/

/*主程式*/
void main(){
	char i;
	for(i=1;i<=4;i++){
		seg7En(i,i);
		delay(100);
		P2= 0x00;
	}
}

/*7段顯示器輸出*/
void seg7En(int COM, int NUM){
    P2 = seg7_COM[COM];
	  P1 = seg7_num[NUM];
}

/*delay time*/
void delay(int x){
   int m;
   for(m=0;m<x;m++);
}