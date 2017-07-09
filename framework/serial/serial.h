#ifndef __SERIAL_H__
#define __SERIAL_H__

#include "reg52.h"
#include "is_compatible.h"


typedef enum {
  STATION_CAR_GO    = 0,
    STATION_CAR_BACK  = 1,
    STATION_CAR_LEFT  = 2,
    STATION_CAR_RIGHT = 3,
    STATION_CAR_STOP  = 4,
}car_station_type;

typedef enum {
    STATION_NUMBER_0  = 0,
  STATION_NUMBER_1  = 1,
    STATION_NUMBER_2  = 2,
    STATION_NUMBER_3  = 3,
    STATION_NUMBER_4  = 4,
    STATION_NUMBER_5  = 5,
    STATION_NUMBER_6  = 6,
    STATION_NUMBER_7  = 7,
    STATION_NUMBER_8  = 8,
    STATION_NUMBER_9  = 9,
}number_station_type;

void serial_init(void);
void serial_control_car(void);
int get_serial_number(void);

extern volatile int car_station_current ;
extern volatile int number_station_current ;
extern volatile bool receive_control_flag;
#endif