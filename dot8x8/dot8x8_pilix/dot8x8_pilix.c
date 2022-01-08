/*
* File: dot8x8_pilix.c
* 功能: 令點矩陣某一行做霹靂燈的動作
*/

#include "io51.h"
/*霹靂燈顯示碼*/
char code dot8x8_loop[]={ 0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF };
char buf[8]; //緩衝器
void delay(int x);
void shift_left();
void shift_right();

/*主程式*/
void main(){
   int i,j,k;

   /*清除buf[8]的資料*/
   for(i=0;i<8;i++) buf[i]=0xFF; 

   while(1){
		 /*左移*/
     for(i=0;i<8;i++){
           /*把左移資料分別存在buf[]中*/
           for(j=0;j<7;j++) buf[j]= buf[j+1];
			     
			     /*把亮法加入至左移資料*/
           buf[j]= dot8x8_loop[i];
           
           /*重復掃描各字型50回(增加亮度)*/
           for(k=0;k<50;k++) shift_left(); //字型左移
     }
		 
		 /*清除buf[8]的資料*/
     for(i=0;i<8;i++) buf[i]=0xFF;
		 
		 /*右移*/
	   for(i=0;i<8;i++){
           /*把左移資料分別存在buf[]中*/
           for(j=0;j<7;j++) buf[j]= buf[j+1];
			 
			     /*把亮法加入至右移資料*/
           buf[j]= dot8x8_loop[i];
           
           /*重復掃描各字型50回(增加亮度)*/
           for(k=0;k<50;k++) shift_right(); //字型右移
       }
   }
}

/*call 左移的副程式*/
void shift_left(){
    int i;
    int enable_signal=0x01;//致能=0x01

    /*各字型由8筆資料組成=掃8回*/
    for(i=0;i<8;i++){
		/*把左移資料分別存在buf[]中*/
        P1=buf[i];
        P2=enable_signal;
        delay(50); //delay 50ms=0.05sec
        enable_signal<<=1; //左移1個位元
    }
}

/*call 右移的副程式*/
void shift_right(){
    int i;
    int enable_signal=0x80;//致能=0x80

    /*各字型由8筆資料組成=掃8回*/
    for(i=0;i<8;i++){
		/*把右移資料分別存在buf[]中*/
        P1=buf[i];
        P2=enable_signal;
        delay(50); //delay 50ms=0.05sec
        enable_signal>>=1; //右移1個位元
    }
}

/*delay time*/
void delay(int x){
    int m;
    for(m=0;m<x;m++);
}