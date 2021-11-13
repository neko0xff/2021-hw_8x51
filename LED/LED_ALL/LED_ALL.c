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
int i,m;
//int rum_time=3;
//int key= 0;
//int j=0xfe;

//乒乓灯亮法
int j_ping= 0x81;
int j_pong= 0x18;
char led_ping[]={
	0x81,0x42,0x24,0x18 // 外=>內
};
char led_pong[]={
	0x18,0x24,0x42,0x81 // 內=>外
};

//接龍灯亮法

char led_rf[]={
	0x80,0x81,0x13,0x87,
	0x8F,0x9F,0XBF,0XFF
};

char led_r1[]={
	0x80,0x40,0x20,0x10,
	0x08,0x04,0x02,0x01
};
char led_r2[]={
	0x81,0x41,0x21,0x11,
	0x09,0x05,0x03
};
char led_r3[]={
	0x13,0x43,0x23,0x13,
	0x0B,0x07
};
char led_r4[]={
	0x87,0x47,0x27,0x17,0x0F
};
char led_r5[]={
	0x8F,0x4F,0x2F,0x1F
};
char led_r6[]={
	0x9F,0x5F,0x3F
};
char led_r7[]={
	0xBF,0x7F
};
char led_r8=0xFF;



/*主程式*/
void main(){
	LED_01(rum_time);
	delay(2000);
	LED_ping(rum_time);
	delay(2000);
	LED_pilix3(run_time);
	delay(2000);
	LED_02(run_time);
	delay(2000);
	
}

/*副程式*/

// LED_01: 右至左移的跑馬灯
void LED_01(int run){
  int x;
  int key=0;
  for(int x=0;x<=run;x++){
	 int i,j;
	 /*如果key=0,則重置*/
	 while(key==0){
		 /*點亮LED 0~7*/
		 for(i=1;i<8;i++){
			 P1= j; //給P1送出控制LED的信號
			 delay(5000);
			 j<<= 1; // j => 左旋1位元
			 j= j+1;
		  }
		j= 0xfe; //LED 0= 0xfe
	}
  }
}

//LED_ping: 乒乓灯
void LED_ping(int run){
 int x;
 for(x=0;x<=run;x++){
     char i,m;
     while(key==0){
	     for(i=0;i<3;i++){
		     P1= j_ping;
		     delay(2000);
		     j_ping=led_ping[i];
	     }
	     for(m=0;m<3;m++){
		     P1= j_pong;
		     delay(2000);
		     j_pong=led_pong[m];
	     }
	     j_ping= 0x81;
      }
   }   
}

//LED_pilix3:運行三回霹靂灯
void LED_pilix3(int run){
  int x,k,i,m;
  int key=0;
  for(x=0;x<=run;x++){
	 char k,i,m;
	 /*亮3回*/
	 for(k=1;k<=key;k++){
	    	/*亮法:LED 0~7*/
		  for(i=1;i<8;i++){
			 P1= j;
			 delay(1000);
			 j<<= 1; // j => 左旋1位元
			 j= j+1;
		  }
		  /*亮法:LED 7~0*/
		  for(m=1;m<8;m++){
			 P1= j;
			 delay(1000);
			 j>>=1; // j => 右旋1位元
			 j= j|80;
		 }
		 j=0xfe;
	 }
  }
}

//LED_02: 左至右移的接龍灯
void LED_02(int run){
	int x;
	for(x=0;x<=run;x++){
		char r1,r2,r3,r4,r5,r6,r7,r8; //開始值
	    char r1x,r2x,r3x,r4x,r5x,r6x,r7x,r8x; //指定
	    while(key == 0){
		   /*第1回*/
		   for(r1=0;r1<=7;r1++){
			 r1x = led_rf[0];
			 P1= r1x;
			 delay(1000);
			 r1x= led_r1[r1];
		   }
		   /*第2回*/
		   for(r2=0;r2<=7;r2++){
			 r2x = led_rf[1];
			 P1= r2x;
			 delay(1000);
			 r2x= led_r2[r2];
		   }
		   /*第3回*/
		   for(r3=0;r3<=7;r3++){
			 r3x= led_rf[2];
			 P1= r3x;
			 delay(1000);
			 r3x= led_r3[r3];
		   }
		   /*第4回*/
		   for(r4=0;r4<=7;r4++){
			 r4x= led_rf[3];
			 P1= r4x;
			 delay(1000);
			 r4x= led_r4[r4];
		   }
		   /*第5回*/
		   for(r5=0;r5<=7;r5++){
			 r5x= led_rf[4];
			 P1= r5x;
			 delay(1000);
			 r5x= led_r5[r5];
		   }
		   /*第6回*/
		   for(r6=0;r6<=7;r6++){
			 r6x= led_rf[5];
			 P1= r6x;
			 delay(1000);
			 r6x= led_r6[r6];
		   }
		  /*第7回*/
		  for(r7=0;r7<=7;r7++){
			 r7x= led_rf[6];
			 P1= r7x;
			 delay(1000);
			 r7x= led_r7[r7];
		  }
		  /*第8回*/
		  for(r8=0;r8<=7;r8++){
			 r8x= led_rf[7];
			 P1= r8x;
			 delay(1000);
			 r8x= led_r8[r8];
		  }
	}
	}
}

//delay time
void delay(int x){
	for(m=0;m<x;m++);
}