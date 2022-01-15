/*
*   File: `int.c`
*   功能: int0 & int1 中斷
*/

#include "io51.h"
void delay(int x);
void setINT();
void reset();
int i,j;

void main(){
    while(1){
			 setINT();
       reset();
    }
}
/*RESET*/
void reset(){
  for(;;){
     P1=0x00; //LED全亮
     delay(20000);
     P1=0xFF; //LED全暗
     delay(20000);
  }
}
/*INT0(中斷優先權:IP.0=0x00)*/
void int0(void) interrupt 0x00{
	while(1){
		 P1= 0xF0; //LED亮右側四顆
		 delay(20000); 
		 P1= 0xFF; //LED全暗
		 delay(20000);
  }
}

/*INT1(中斷優先權:IP.2=0x02)*/
void int1(void) interrupt 0x02{
  while(1){   
		 P1= 0x0F; //LED亮左側四顆
		 delay(20000);
		 P1= 0xFF; //LED全暗
		 delay(20000);
	}
}

/*INT0&1設定*/
void setINT(){
   IT0=1; 
   IT1=1;
   IE=0x85; // IE=10000101B
}

void delay(int x){
    int m;
    for(m=0;m<x;m++);
}