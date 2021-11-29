/*
 *  File: 7seg_run.c
 *  功能: 在四位數7段顯示器輸出跑馬灯(從左開始)
 */

#include "io51.h"
int m;
void delay(int s);
void seg7_switch(int LED,int COM);
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

void seg7_switch(int LED,int COM){
    P1=seg7_LED[LED];
    P2=seg7_COM[COM];
    delay(1000);
}
void delay(int s){
    for(m=0;m<s;m++);
}
