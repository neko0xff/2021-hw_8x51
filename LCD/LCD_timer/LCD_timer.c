/*
*  File: LCD_timer.c
*  功能: 在LCD實現計時器功能(mm:ss)
*/

#include "io51.h"
void delay(int x);
void set_lcd();
void set_timer0();
void cursor_home();
void put_dr(int cntl_word);
void put_ir(int data_word);
char LCD_num[]={'0','1','2','3','4','5','6','7','8','9'};
void check_busy();
int SEC_ONE=0;
int SEC_TEN=0;
int MIN_ONE=0;
int MIN_TEN=0;
int INT_NUM=0;
void display();
void LCD_outputType();
void one_mm();
void ten_mm();
void one_ss();
void ten_ss();


void main(){
	
   set_lcd();
   while(1){
	   cursor_home();
	   set_timer0();
	   /*進位處理:
		   (1) 個位=>十位:10進位
		   (2) 秒=>分:60進位
		 */
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
                MIN_ONE++;
                if(MIN_ONE !=10){
                    display();
                }else{
                    MIN_ONE=0;
                    MIN_TEN++;
                    if(MIN_TEN !=10){
                        display();
                    }
                }
             }
            goto again;
          }   
    }
}

void set_timer0(){
    TMOD= 0x01; //Timer0:16bit Timer(0000 0001)
    TH0=(65536-5000)/256;
    TL0=(65536-5000)%256;
    IE=0x82; //啟用溢位中斷
    TR0=1; //啟動Timer0
}

/*輸出時間格式*/
void display(){
	ten_mm();
	one_mm();
	put_dr(':');
	ten_ss();
	one_ss();
	put_dr(' ');
}

/*時間格式變數*/
void one_mm(){
	put_dr(LCD_num[MIN_ONE]);
}
void ten_mm(){
	put_dr(LCD_num[MIN_TEN]);
}
void one_ss(){
	put_dr(LCD_num[SEC_ONE]);
}
void ten_ss(){
	put_dr(LCD_num[SEC_TEN]);
}

/*設定LCD*/
void set_lcd(){
    put_ir(0x30); //設定8bit伝送+單排顯示
    put_ir(0x06); //在位元顯示後遊標往右移
    put_ir(0x0C); //LCD顯示致能且遊標不出現+字元不閃爍
}

/*Clear LCD Display */
void cursor_home(){
    put_ir(0x01); //Clear LCD Display 
}

/*寫入控制字元的副程式*/
void put_ir(int data_word){
    check_busy(); //檢視LCD是否忙碌
    P1= data_word; //P1=送出LCD的控制碼
    P2= 0x00; //資料寫入到LCD的位址暫存器:RS=0,R/-W=0,E=0(LOW)
    P2= 0x04; //資料寫入到LCD的位址暫存器:RS=0,R/-W=0,E=1(HIGH)
    delay(100); //delay 100ms=0.1sec
    P2= 0x00; //資料寫入到LCD的位址暫存器:RS=0,R/-W=0,E=0(LOW)
}

/*寫入資料的副程式*/
void put_dr(int cntl_word){
    check_busy(); //檢視LCD是否忙碌
    P1= cntl_word; //P1=送出LCD的顯示碼
    P2= 0x01; //寫入LCD的位置暫存器:RS=1,R/-W=0,E=0(LOW)
    P2= 0x05; //讀LCD的位置暫存器:RS=1,R/-W=1,E=1(HIGH)
    delay(100); //delay 100ms=0.1sec
    P2= 0x01; //RS=1,R/-W=0,E=0(LOW)
}

/*檢視LCD是否忙碌 */
void check_busy(){
    int busy_flag;

    P2=0x02; //資料寫入LCD的指令暫存器:RS=0,R/-W=1,E=0(LOW)
    P2=0x06; //資料寫入LCD的指令暫存器:RS=0,R/-W=1,E=1(HIGH)
    delay(100); //delay 100ms=0.1sec
	
    READ_AGAIN:
    busy_flag=P1; //經由P1讀取LCD的狀態字組
    busy_flag&=0x80; //保留狀態字組的最高位元
    
    /*最高位元判斷*/
    if(busy_flag == 0x80){ //if 最高位元=1
        goto READ_AGAIN; //讀取狀態字組
    }else{ //else 最高位元=0
        P2=0x02; //資料寫入LCD的指令暫存器:RS=0,R/-W=1,E=0(LOW)
    }
}

/*設定Timer0 INT中斷*/
void Timer0(void) interrupt 0x0B{
    TH0=(65536-5000)/256;
    TL0=(65536-5000)%256;
    INT_NUM++;
	
	  /*是否中斷200回*/
    if(INT_NUM == 200){
        SEC_ONE++;
        INT_NUM=0;
    }
}

void delay(int x){
   int m;
   for(m=0;m<x;m++);
}