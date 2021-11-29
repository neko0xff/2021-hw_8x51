/*
 * File: 7seg_num.c
 * 功能: 用7段顯示器輸出組員學號
*/

#include "io51.h"
void delay(int s);
/*7段顯示器顯示碼*/
char seg7[]={
   0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D, //0~7
   0x7F,0x6F,0x77,0x39,0x5E,0x79,0x71  //8~F
};

/*學號*/
char num8_02[]={
	5,0,6,3,1,1,0,2 
};
char num8_16[]={
	5,0,6,3,1,1,1,6
};

/*
   ex: 50631102
   5(0x6D) => seg7[5]
   0(0x3F) => seg7[0]
   6(0x7D) => seg7[6]
   3(0x4F) => seg7[3]
   1(0x06) => seg7[1]
   2(0x5B) => seg7[2]
   
   ex: 50631116
   5(0x6D) => seg7[5]
   0(0x3F) => seg7[0]
   6(0x7D) => seg7[6]
   3(0x4F) => seg7[3]
   1(0x06) => seg7[1]
*/

void main(){
   char i_02,j_02;
   char i_16,j_16;
   P2=0x0F; //啟用所有的7段顯示器(X4)
   /*重復運行*/
   while(1){
	   /*從P1輸出7seg顯示碼*/
	   for(i_02=0;i_02<8;i_02++){
        for(j_02=0;j_02<8;j_02++){
			int x=num8_02[j_02];
			P1=seg7[x];
			delay(2000);
			}
		}
		
		for(i_16=0;i_16<8;i_16++){
			for(j_16=0;j_16<8;j_16++){
				int y=num8_16[j_16];
                P1=seg7[y];
                delay(2000);				
			}
		}
		
	   }
   }


/*功能:delay*/
void delay(int s){
	int m;
	for(m=0;m<s;m++);
}