/* 
*  File: LCD_num.c
*  功能: 在LCD顯示二個組員的學號
*/
#include "io51.h"

/*LCD的顯示&副程式*/
char LCD_num02[]={'5','0','6','3','1','1','0','2'};
char LED_num16[]={'5','0','6','3','1','1','1','6'};
void delay(int x);
void set_lcd();
void put_ir(int data_word);
void put_dr(int cntl_word);
void cursor_home();
void check_busy();


/*主程式*/
void main(){
    int i;

    set_lcd(); //設定LCD
    
    /*LCD顯示*/
    while(1){
        /*輸出第一個人的學號*/
        cursor_home(); //Clear LCD Display + 游標歸位(左上角)
        for(i=0;i<8;i++){
            put_dr(LCD_num02[i]); //把陣列的內容戴入LCD
            delay(10000); //delay 10 sec
        }
        /*輸出第二個人的學號*/
        cursor_home(); //Clear LCD Display + 游標歸位(左上角)
        for(i=0;i<8;i++){
            put_dr(LED_num16[i]); //把陣列的內容戴入LCD
            delay(10000); //delay 10 sec
        }
    }
}

/*設定LCD*/
void set_lcd(){
    put_ir(0x30); //設定8bit伝送+單排顯示
    put_ir(0x06); //在位元顯示後遊標往右移
    put_ir(0x0E); //LCD顯示致能且遊標出現+字元不閃爍
}

/*Clear LCD Display + 游標歸位(左上角)*/
void cursor_home(){
    put_ir(0x01); //Clear LCD Display 
    put_ir(0x02); //游標歸位
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

/*delay time*/
void delay(int x){
    int m;
    for(m=0;m<x;m++);
}