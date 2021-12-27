/*
*   File:7seg_timer.c
*   功能: 用7段顯示器做一個計時器(mm:ss)
*/

#include "io51.h"

/*7段顯示器顯示碼*/
char seg7_number[]={
   0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D, //0~7
   0x7F,0x6F,0x77,0x39,0x5E,0x79,0x71  //8~F
};

int i,j,m;
int SEC_ONE_ss=0;
int SEC_TEN_ss=0;
int SEC_ONE_mm=0;
int SEC_TEN_mm=0;
int INT_NUM=0;
void delay(int x);
void one_mm();
void one_ss();
void ten_mm();
void ten_ss();
void display();

void main(){
   while(1){
       TMOD= 0x01;
       TH0=(65536-5000)/256;
       TL0=(65536-5000)%256;
       IE=0x82;
       TR0=1;
       again:
          if(SEC_ONE_ss != 10){
              display();
          }else{
              SEC_ONE_ss=0;
              SEC_TEN_ss++;
              if(SEC_TEN_ss !=6){
                display();
             }else{
                SEC_TEN_ss=0;
                /*SEC_TEN_mm++;
                if(SEC_TEN_mm !=10){
                    display();
                }else{
                    SEC_TEN_mm=0;
                    SEC_ONE_mm++;
                    if(SEC_ONE_mm !=10){
                        display();
                    }
                }*/
             }
            goto again;
          }   
   }
}

void display(){
    one_ss();
    delay(500);
    ten_ss();
    delay(500);
    /*one_mm();
    delay(500);
    ten_mm();
    delay(500);*/
}

void Timer0(void) interrupt 0x0B{
    TH0=(65536-5000)/256;
    TL0=(65536-5000)%256;
    INT_NUM++;
    if(INT_NUM == 200){
        SEC_ONE_ss++;
        INT_NUM=0;
    }
}


void one_mm(){
    P1= seg7_number[SEC_ONE_mm];
    P2= 0x08;
}
void ten_mm(){
    P1= seg7_number[SEC_TEN_mm];
    P2= 0x04;
}
void one_ss(){
    P1= seg7_number[SEC_ONE_ss];
    P2= 0x02;
}
void ten_ss(){
    P1= seg7_number[SEC_TEN_ss];
    P2= 0x01;
}

void delay(int x){
    int m;
    for(m=0;m<x;m++);
}