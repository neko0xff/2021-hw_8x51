/*
*   File: s51pgm.h
*   功能: 定義KT-89S51燒錄實驗器的部分接腳
*/
#ifndef s51pgm_HEADER_FILE
#define s51pgm_HEADER_FILE 1
    /*其它*/
sbit B1  = 0xB7;  // 蜂鳴器
    /*按鈕*/
sbit PB1 = 0xB3;  // INT0
sbit PB2 = 0xB2;  // INT1
sbit PB3 = 0xA1;  // P2.1按鈕
sbit PB4 = 0xA0;  // P2.0按鈕
    /*LED*/
sbit DS1 = 0x90;  // P1.0
sbit DS2 = 0x91;  // P1.1
sbit DS3 = 0x92;  // P1.2
sbit DS4 = 0x93;  // P1.3
sbit DS5 = 0x94;  // P1.4
sbit DS6 = 0x95;  // P1.5
sbit DS7 = 0x96;  // P1.6
sbit DS8 = 0x97;  // P1.7


#endif