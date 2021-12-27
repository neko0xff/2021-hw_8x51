/*
*  File: LED_pilix3.c
*  功能: 運行三回霹靂灯
*/

#include "io51.h"
void delay(int x);
int j= 0xfe;
int i,a;
int m;
int x,y;
char led_pilix1[]={
	0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F 
};
char led_pilix2[]={
	0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE 
};
/*主程式*/
void main(){
	/*亮3回*/
	while(1){
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

/*delay time*/
void delay(int x){
	for(m=0;m<x;m++);
}