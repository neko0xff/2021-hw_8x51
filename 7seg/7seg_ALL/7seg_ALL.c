/*
* File: 7seg_ALL.c
* 功能: 題目整合
*/

#include "io51.h"
void delay(int s);
void seg7_1(int seg_time);
void seg7_num(int num_time);
void seg7_run(int run_time);
void seg7_switch(int LED,int COM);
int m;
int run=3;

/*7段顯示器顯示碼*/
char seg7_nums[]={
   0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D, //0~7
   0x7F,0x6F,0x77,0x39,0x5E,0x79,0x71  //8~F
};
char seg7_LED[]={
    0x00, //0:not define
    0x01, //1:a
    0x02, //2:b
    0x04, //3:c
    0x08, //4:d
    0x10, //5:e
    0x20, //6:f
    0x40, //7:g
    0x80  //8:dot
};
char seg7_COM[]={
    0x00, //0:not define
    0x01, //1:com1
    0x02, //2:com2
    0x04, //3:com3
    0x08, //4:com4
    0x0f  //5:com1~4(FULL)
};

void main(){
   while(1){
     seg7_1(run);
     delay(2000);
     seg7_run(run);
     delay(2000);
     seg7_num(run);
     delay(2000);
   }
}

void seg7_1(int seg_time){
   char i;
   int seg_x;
   
   for(seg_x=1;seg_x<=seg_time;seg_x++){
      P2= 0x0F; //啟用所有的7段顯示器(X4)
      /*重復運行*/
      while(1){
	    /*從P1輸出全部的7段顯示器顯示碼*/
	    for(i=0;i<16;i++){
		   P1=seg7_nums[i]; 
		   delay(20000); //delay 2sec
	    }
    }

   }
   
}

void seg7_num(int num_time){
   int num_x;
   
   /*學號*/
   char num8_02[]={ 5,0,6,3,1,1,0,2 };
   char num8_16[]={ 5,0,6,3,1,1,1,6 };

   char i_02,j_02;
   char i_16,j_16;

   for(num_x=1;num_x<=num_time;num_x++){
      P2=0x0F; //啟用所有的7段顯示器(X4)
      /*重復運行*/
      while(1){
	      /*從P1輸出7seg顯示碼*/
	      for(i_02=0;i_02<8;i_02++){
           for(j_02=0;j_02<8;j_02++){
			        int x=num8_02[j_02];
			        P1=seg7_nums[x];
			        delay(2000);
			}
		  }
		
		  for(i_16=0;i_16<8;i_16++){
			   for(j_16=0;j_16<8;j_16++){
			    int y=num8_16[j_16];
                P1=seg7_nums[y];
                delay(2000);				
			   }
		   }
       }
   }
}

void seg7_run(int run_time){
   int run_x;
   for(run_x=1;run_x<=run_time;run_x++){
       while(1){
       seg7_switch(1,1); //1(a,com1)
       seg7_switch(1,2); //2(a,com2)
       seg7_switch(1,3); //3(a,com3)
       seg7_switch(1,4); //4(a,com4)
       seg7_switch(2,4); //5(b,com4)
       seg7_switch(3,4); //6(c,com4)
       seg7_switch(4,4); //7(dot,com4)
       seg7_switch(8,4); //8(d,com4)
       seg7_switch(4,3); //9(dot,com3)
       seg7_switch(8,3); //10(d,com3)
       seg7_switch(4,2); //11(dot,com2)
       seg7_switch(8,2); //12(d,com2)
       seg7_switch(4,1); //13(dot,com1)
       seg7_switch(8,1); //14(d,com1)
       seg7_switch(5,1); //15(e,com1)
       seg7_switch(6,1); //16(f,com1)
       }    
   }
   
}

void seg7_switch(int LED,int COM){
    P1=seg7_LED[LED];
    P2=seg7_COM[COM];
    delay(1000);
}

void delay(int s){
    for(m=0;m<s;m++);
}