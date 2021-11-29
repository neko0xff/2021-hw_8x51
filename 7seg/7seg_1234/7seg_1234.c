/*
* File: 7seg_1234.c
* 功能: 7段顯示器輸出1234
*/

#include "io51.h"
void delay(int x);
char seg_num[]={
	0x3F,0x06,0x5B,0x4F,0x66 //0,1,2,3,4
};
char num[]={
	0,1,2,3,4
};

/*
   ex: 1,2,3,4
   1(0x06) => seg_num[1]
   2(0x5B) => seg_num[2]
   3(0x4F) => seg_num[3]
   4(0x66) => seg_num[4]
*/


void main(){
	char i,j;
	P2=0x0F; //7seg = all enable
    while(1){
	   for(i=1;i<=4;i++){
		   for(j=1;j<=4;j++){
			   int x=num[j];
			   P1=seg_num[x];
		   }
	   } 
	}
}

void delay(int x){
   int m;
   for(m=0;m<x;m++);
}