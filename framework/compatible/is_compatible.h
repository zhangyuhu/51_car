#ifndef __IS_COMPATIBLE_H__
#define __IS_COMPATIBLE_H__

#define bool char
#define true 1
#define false 0

//#define DEVICE_TYPE_CAR           (0x01)
//#define DEVICE_TYPE_NRF           (0x02)

//#ifndef DEVICE_TYPE_VALUE 
//#define DEVICE_TYPE_VALUE           (DEVICE_TYPE_CAR)
//#endif


//ģ��ѡ��  ����ͬʱΪ1
#define USE_BLUETOOTH_SERIAL_MODULE      (0)           //ʹ����������ģ��
#define USE_NRF24L01                     (1)           //ʹ�� NRF24L01ģ��
//NRF����ѡ��
#define NRF_USED_RECEIVE             (0)
#define NRF_USED_SEND                (1)

typedef unsigned char uchar;
typedef unsigned char uint;
#endif