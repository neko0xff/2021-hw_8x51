/*
 * File: 7seg_num.c
 * 功能: 用7段顯示器輸出組員學號
*/

#include "io51.h"
void delay(int s);
void seg7En(int a,int b);
void user1();
void user2();

/*7段顯示器顯示碼*/
char seg7_number[]={
   0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D, //0~7
   0x7F,0x6F,0x77,0x39,0x5E,0x79,0x71  //8~F
};
char seg7_COM[]={
   0x08,0x04,0x02,0x01
};


void main(){
   /*重復運行*/   
   while(1){
      user1();
      user2();
   }   
}

/*組員1*/
void user1(){
   seg7En(0,5);
   delay(20000);
   seg7En(1,0);
   delay(20000);
   seg7En(2,6);
   delay(20000);
   seg7En(3,3);
   delay(20000);
   seg7En(0,1);
   delay(20000);
   seg7En(1,1);
   delay(20000);
   seg7En(2,0);
   delay(20000);
   seg7En(3,2);
   delay(20000);
}

/*組員二*/
void user2(){
   seg7En(0,5);
   delay(20000);
   seg7En(1,0);
   delay(20000);
   seg7En(2,6);
   delay(20000);
   seg7En(3,3);
   delay(20000);
   seg7En(0,1);
   delay(20000);
   seg7En(1,1);
   delay(20000);
   seg7En(2,1);
   delay(20000);
   seg7En(3,6);
   delay(20000);
}

/*7段顯示器輸出*/
void seg7En(int a, int b){
   P2 = seg7_COM[a];
	P1 = seg7_number[b];
}

/*功能:delay*/
void delay(int s){
	int m;
	for(m=0;m<s;m++);
}