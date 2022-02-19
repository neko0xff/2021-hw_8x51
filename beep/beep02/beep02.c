/*
*  File: beep02.c
*  功能: 輸出 低 => 中 => 高 的八個音符
*/

#include "io51.h"
#include "s51pgm.h"

unsigned char Tone[3][12]={
/*   Do  Do#  Re Re#  Mi  Fa Fa#  So So#  La La#  Si      */
	{229,217,204,193,182,172,162,153,145,136,129,121}, // 低音
	{115,108,102, 97, 91, 86, 81, 77, 72, 68, 64 ,61}, // 中音
	{ 57, 54, 51, 48, 45, 43, 41, 38, 36, 34, 32 ,30}  // 高音
};

//delay 8.15us
void delay_8us15(unsigned char count){
	unsigned char j;
	for(j=0;j<count;j++);
}

void main(){
	int i,j,k;
	for(i=0;i<3;i++){
		for(j=0;j<12;j++){
			for(k=0;k<60+i*120+j*10;k++){
				B1=0; //ON
				delay_8us15(Tone[i][j]);
				B1=1; //OFF
				delay_8us15(Tone[i][j]);
			}
			B1=0;
			delay_8us15(255);
		}
	}
}