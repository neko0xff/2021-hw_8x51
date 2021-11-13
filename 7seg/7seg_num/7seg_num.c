/*
 * File: 7seg_num.c
 * 功能: 用7段顯示器輸出學號
*/

#include "io51.h"
void delay(int s);
/*7段顯示器顯示碼*/
char code seg7[]={
   0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D, //0~7
   0x7F,0x6F,0x77,0x39,0x5E,0x79,0x71  //8~F
};
char code num8[]={
	5,0,6,3,1,1,0,2 //學號
};

/*
   ex: 50631102
   5(0x6D) => seg7[5]
   0(0x3F) => seg7[0]
   6(0x7D) => seg7[6]
   3(0x4F) => seg7[3]
   1(0x06) => seg7[1]
   2(0x5B) => seg7[2]
*/

void main(){
   char i,j;
   P2=0x0F; //啟用所有的7段顯示器(X4)
   /*重復運行*/
   while(1){
	   /*從P1輸出7seg顯示碼*/
	   for(i=0;i<8;i++){
        for(j=0;j<8;j++){
			int x=num8[j];
			 P1=seg7[x];
			delay(20000);
			}
		}
		/* old 
		   P1=seg7[5]; 
		   delay(20000); //delay 2sec
		   P1=seg7[0];
		   delay(20000);
		   P1=seg7[6];
		   delay(20000);
		   P1=seg7[3];
		   delay(20000);
		   P1=seg7[1];
		   delay(20000);
		   P1=seg7[1];
		   delay(20000);
		   P1=seg7[0];
		   delay(20000);
		   P1=seg7[2];
		   delay(20000);
		*/
	   }
   }


/*功能:delay*/
void delay(int s){
	int m;
	for(m=0;m<s;m++);
}