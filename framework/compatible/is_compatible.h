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


//模块选择  不可同时为1
#define USE_BLUETOOTH_SERIAL_MODULE      (0)           //使用蓝牙串口模块
#define USE_NRF24L01                     (1)           //使用 NRF24L01模块
//NRF功能选择
#define NRF_USED_RECEIVE             (0)
#define NRF_USED_SEND                (1)

typedef unsigned char uchar;
typedef unsigned char uint;
#endif