/*
*   File:7seg_timer.c
*   功能: 用7段顯示器做一個計時器(mm:ss)
*/

/*7段顯示器顯示碼*/
char seg7_number[]={
   0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D, //0~7
   0x7F,0x6F,0x77,0x39,0x5E,0x79,0x71  //8~F
};
char seg7_COM[]={
   0x08,0x04,0x02,0x01
};

int i,j,m;
int SEC_ONE=0;
int SEC_TEN=0;
int INT_NUM=0;
void delay(int x);

void main(){
   while(1){
       TMOD= 0x01;
       TH0=(65536-5000)/256;
       TL0=(65536-5000)%256;
       IE=0X82;
       TR0=1;
       again:
          if(SEC_ONE != 10){
              display();
          }else{
              SEC_ONE=0;
              SEC_TEN++;
              if(SEC_TEN !=6){
                display();
             }else{
                SEC_TEN=0;
             }
            goto again;
          }   
   }
}

void display(){
    one();
    delay(500);
    ten();
    delay(500);
}

interrput [0x0B] void timer0(){
    TH0=(65536-5000)/256;
    TL0=(65536-5000)%256;
    INT_NUM++;
    if(INT_NUM == 200){
        SEC_ONE++;
        INT_NUM=0;
    }
}

void one(){
    P1= seg[SEC_ONE];
    P2= 0x02;
}

void ten(){
    P1= seg[SEC_TEN];
    P2= 0x01;
}

void delay(int x){
    int m;
    for(m=0;m<x;m++);
}