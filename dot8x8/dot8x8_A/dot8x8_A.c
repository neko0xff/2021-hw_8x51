/*
*   File: dot8x8_A.char
*   功能: 令字型 A 週而復始的以順時針方向旋轉，每次旋轉 90 度
*/

#include "io51.h"
char code dot8x8_A[32]={
    0xFF,0x03,0xED,0xEE,0xEE,0xED,0x03,0xFF, //第1回
    0xBD,0xBD,0xBD,0x81,0xBD,0xBD,0xDB,0xE7, //第2回
    0xFF,0xC0,0XB8,0x77,0x77,0xB7,0xC0,0xFF, //第3回
    0xE7,0xDB,0xBD,0xBD,0x81,0xBD,0xBD,0xBD  //第4回
};

char buf[8];
void delay(int x);
void shift_left();

void main(){
    int i,j,k;

    /*清除存放左移資料的buf[8]*/
    for(i=0;i<8;i++) buf[i]=0xFF;
    
    while(1){
       for(i=0;i<8*4;i++){
        /*把左移資料分別存在buf[]中*/
        for(j=0;j<7;j++)
            buf[j]= buf[j+1];
            buf[j]= dot8x8_A[i];
        
        /*重復掃描各字型50回(增加亮度)*/
        for(k=0;k<50;k++){
            shift_left(); //字型左移
        }
    }
   }
}

/*call 左移的副程式*/
void shift_left(){
    int i;
    int enable_signal=0x01;//致能=0x01

    /*各字型由8筆資料組成=掃8回*/
    for(i=0;i<8;i++){
		/*點亮8x8點陣某一字型第Cx(0<=x<=7)*/
        P1=buf[i]; 
        P2=enable_signal; 
        delay(50); //delay 50ms=0.05sec
        enable_signal<<=1; //左移1個位元
    }
}

void delay(int x){
    int m;
    for(m=0;m<x;m++);
}