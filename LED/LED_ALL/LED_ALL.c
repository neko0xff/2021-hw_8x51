/*
*  File: LED_ALL.c
*  功能: 題目整合
*/

#include "io51.h"

/*變數*/
void delay(int x);
void LED_01(int run);
void LED_pilix3(int run);
void LED_ping(int run);
void LED_02(int run);
int i,m;
int run_time=3;

//乒乓灯亮法
int j_ping= 0x7E;
char led_ping[]={
	0x7E,0xBD,0xDB,0xE7,0xDB,0xBD,0X7E 
};
 
//霹靂灯亮法
char led_pilix1[]={
	0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F 
};
char led_pilix2[]={
	0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE 
};

//接龍灯亮法
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
	 LED_01(run_time);
	 LED_ping(run_time);
	 LED_pilix3(run_time);
	 LED_02(run_time);
   }
}

/*副程式*/

// LED_01: 右至左移的跑馬灯
void LED_01(int run){
  int x;
  for(x=0;x<=run;x++){
	   int i,j;
	   /*點亮LED 0~7*/
	   for(i=0;i<8;i++){
			P1= j; //給P1送出控制LED的信號
			delay(7000);
			j<<= 1; // j => 左旋1位元
			j= j+1;
	    }
	   j= 0xfe; //LED 0= 0xfe
	}
  }


//LED_ping: 乒乓灯
void LED_ping(int run){
 int x;
 for(x=0;x<run;x++){
     char i;
	/*8顆LED*/
	for(i=0;i<7;i++){
		P1= led_ping[i];
		delay(10000); //delay 10sec
    }
   }   
}

//LED_pilix3:運行三回霹靂灯
void LED_pilix3(int run){
  int x,y,i,a;
  for(x=0;x<run;x++){
	 /*亮3回*/
	    /*左*/
	    for(i=0;i<8;i++){
			for(a=0;a<3;a++){
				P1 = led_pilix1[i];
				delay(10000);
				P1 = 0xFF;
				delay(10000);
			}
		} 
		/*右*/
		for(x=0;x< 7;x++){
			for(y=0;y<3;y++){
				P1 = led_pilix2[x];
				delay(10000);
				P1 = 0xFF;
				delay(10000);
			}
		} 
  }
}

//LED_02: 左至右移的接龍灯
void LED_02(int run){
 int x;
 for(x=0;x<run;x++){
    int a, b, c, d, e, f, g; //迴圈變數
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

//delay time
void delay(int x){
	int m;
	for(m=0;m<x;m++);
}