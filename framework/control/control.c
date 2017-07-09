#include "reg52.h"
#include <serial.h>
#include "moto.h"
#include "is_compatible.h"
#include "delay.h"
#include "control.h"

#define ALLOWABLE_STATION  ((car_station_current >= STATION_CAR_GO) &&(car_station_current <= STATION_CAR_STOP))?(true):(false)

void car_control(car_station_type car_station)
{
    if(ALLOWABLE_STATION == true)
    {
        switch(car_station_current)
        {
            case STATION_CAR_GO :
            {
                car_go(10);
                //delayms(100);
                break;
            }

            case STATION_CAR_BACK :
            {
                car_back(10);
                //delayms(100);
                break;
            }

            case STATION_CAR_LEFT :
            {
                car_left(10);
                //delayms(100);
                break;
            }

            case STATION_CAR_RIGHT :
            {
                car_right(10);
                //delayms(100);
                break;
            }

            case STATION_CAR_STOP :
            {
                car_stop();
                break;
            }
        }
    }
    else
    {
        car_stop();
    }
}