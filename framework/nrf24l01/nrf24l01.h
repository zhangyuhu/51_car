#ifndef __NRF24L01_H__
#define __NRF24L01_H__

typedef unsigned char uchar;
typedef unsigned char uint;

extern uchar   TxBuf[32];                  // 预设发送缓冲区
extern uchar   RxBuf[32];                  // 预设接收缓冲区

//**********************************子函数申明*********************************************
void Delay(unsigned int s);
void inerDelay_us(unsigned char n);
void init_NRF24L01(void);
void SetRX_Mode(void);
unsigned char nRF24L01_RxPacket(unsigned char* rx_buf);
void nRF24L01_TxPacket(unsigned char * tx_buf);
void nRF24L01_flush(void);
#endif