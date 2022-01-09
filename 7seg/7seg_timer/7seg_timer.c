/*
*   File:7seg_timer.c
*   功能: 用7段顯示器做一個計時器(mm:ss)
*/

#include "io51.h"

/*7段顯示器顯示碼*/
char seg7_number[]={
   0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D, //0~6
   0x07,0x7F,0x6F //7~9
};

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
	   /*Timer0 設定: 5000us中斷一回*/
		   TMOD= 0x01; //Timer0:16bit Timer(0000 0001)
       TH0=(65536-5000)/256;
       TL0=(65536-5000)%256;
       IE=0x82; //啟用溢位中斷
       TR0=1; //啟動Timer0
		 
	   /*進位處理:
		   (1) 個位=>十位:10進位
		   (2) 秒=>分:60進位
		 */
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
                SEC_TEN_mm++;
                if(SEC_TEN_mm !=10){
                    display();
                }else{
                    SEC_TEN_mm=0;
                    SEC_ONE_mm++;
                    if(SEC_ONE_mm !=10){
                        display();
                    }
                }
             }
            goto again;
          }   
   }
}

/*輸出控制*/
void display(){
    one_ss();
    delay(500);
    ten_ss();
    delay(500);
    one_mm();
    delay(500);
    ten_mm();
    delay(500);
}

/*設定Timer0 INT中斷*/
void Timer0(void) interrupt 0x0B{
    TH0=(65536-5000)/256;
    TL0=(65536-5000)%256;
    INT_NUM++;
	
	  /*是否中斷200回*/
    if(INT_NUM == 200){
        SEC_ONE_ss++;
        INT_NUM=0;
    }
}

/*位數輸出*/
void one_mm(){
    P1= seg7_number[SEC_ONE_mm];
    P2= 0x01;
}
void ten_mm(){
    P1= seg7_number[SEC_TEN_mm];
    P2= 0x02;
}
void one_ss(){
    P1= seg7_number[SEC_ONE_ss];
    P2= 0x08;
}
void ten_ss(){
    P1= seg7_number[SEC_TEN_ss];
    P2= 0x04;
}

/*delay time*/
void delay(int x){
    int m;
    for(m=0;m<x;m++);
}