#ifndef __IS_COMPATIBLE_H__
#define __IS_COMPATIBLE_H__

#define bool char
#define true 1
#define false 0

#define DEVICE_TYPE_CAR           (0x01)
#define DEVICE_TYPE_NRF           (0x02)

#ifndef DEVICE_TYPE_VALUE 
#define DEVICE_TYPE_VALUE           (DEVICE_TYPE_CAR)
#endif

#endif