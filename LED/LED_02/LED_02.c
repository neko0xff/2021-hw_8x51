/*
* File: LED_02.c
* 功能: 左至右移的接龍灯
*/

#include "io51.h"
void delay(int x);

/*接龍灯亮法*/
int a, b, c, d, e, f, g; //迴圈變數
char led1[] = {0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE}; //第1回
char led2[] = {0x7E, 0xBE, 0xDE, 0xEE, 0xF6, 0xFA, 0xFC}; //第2回
char led3[] = {0x7C, 0xBC, 0xDC, 0xEC, 0xF4, 0xF8}; //第3回
char led4[] = {0x78, 0xB8, 0xD8, 0xE8, 0xF0}; //第4回
char led5[] = {0x70, 0xB0, 0xD0, 0xE0}; //第5回
char led6[] = {0x60, 0xA0, 0xC0}; //第6回
char led7[] = {0x40, 0x80}; //第7回
char led8 = 0x00; //第8回

/*主程式*/
void main(){
  while(1){
	  /*第1回*/
	  for(a=0;a<8;a++){
		P1 = led1[a]; //指定P1=陣列內的內容
		delay(10000); //delay 10sec
	   }
	  /*第2回*/
	  for(b=0;b<7;b++){
		P1 = led2[b]; //指定P1=陣列內的內容
		delay(10000); //delay 10sec
	  }
	  /*第3回*/
	  for(c=0;c<6;c++){
		P1 = led3[c]; //指定P1=陣列內的內容
		delay(10000); //delay 10sec
	  }
	  /*第4回*/
	  for(d=0;d<5;d++){
		P1 = led4[d]; //指定P1=陣列內的內容
		delay(10000); //delay 10sec
	  }
	  /*第5回*/
	  for(e=0;e<4;e++){
		P1 = led5[e]; //指定P1=陣列內的內容
		delay(10000); //delay 10sec
	  }
	  /*第6回*/
	  for(f=0;f<3;f++){
		P1 = led6[f]; //指定P1=陣列內的內容
		delay(10000); //delay 10sec
	  }
	  /*第7回*/
	  for(g=0;g<2;g++){
		P1 = led7[g]; //指定P1=陣列內的內容
		delay(10000); //delay 10sec
	  }
	  /*第8回*/
      P1 = led8; //P1=全亮
	  delay(10000); //delay 10sec
	  /*全関*/
	  P1 = 0xFF; //P1=全関
	  delay(10000); //delay 10sec
	
    }
}

/*delay time*/
void delay(int x){
	int m;
	for(m;m<=x;m++);
}