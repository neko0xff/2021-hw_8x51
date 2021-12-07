/*
* File: LED_02.c
* 功能: 左至右移的接龍灯
*/

#include "io51.h"
int m;
void delay(int x);
int a,b,c,d,e,f,g,h;

/*接龍灯亮法*/
char led_ping1[]={
	0x7F,0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE
};
char led_ping2[]={
	0x7E,0xBE,0xDE,0xEE,0xF6,0xFA,0XFC 
};
char led_ping3[]={
	0x7C,0xBC,0xDC,0xEC,0xF4,0xF8 
};
char led_ping4[]={
	0x78,0xB8,0xD8,0xE8,0xF0 
};
char led_ping5[]={
	0x70,0xB0,0xD0,0xE0 
};
char led_ping6[]={
	0x60,0xA0,0xC0 
};
char led_ping7[]={
	0x40,0x80 
};

char led_r8=0x00;

void main(){
	
	while(1){
		/*第1回*/
		for(a = 0;a < 8;a++){
			P1 = led_ping1[a];
			delay(10000);
		}
		/*第2回*/
		for(b = 0;b < 7;b++){
			P1 = led_ping2[b];
			delay(10000);
		}
		/*第3回*/
		for(c = 0;c < 6;c++){
			P1 = led_ping3[c];
			delay(10000);
		}
		/*第4回*/
		for(d = 0;d < 5;d++){
			P1 = led_ping4[d];
			delay(10000);
		}
		/*第5回*/
		for(e = 0;e < 4;e++){
			P1 = led_ping5[e];
			delay(10000);
		}
		/*第6回*/
		for(f = 0;f < 3;f++){
			P1 = led_ping6[f];
			delay(10000);
		}
		/*第7回*/
		for(g = 0;g < 2;g++){
			P1 = led_ping7[g];
			delay(10000);
		}
		/*第8回*/
		P1 = led_r8;
		delay(10000);
		/*関*/
		P1 = 0xFF;
		delay(1000);
	}
}

/*delay time*/
void delay(int x){
	for(m;m<=x;m++);
}