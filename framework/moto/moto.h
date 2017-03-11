#ifndef __MOTO_H__
#define __MOTO_H__

#include "reg52.h"
#include "is_compatible.h"

sbit moto_left_1  = P2^0;  
sbit moto_left_2  = P2^1;
sbit moto_right_1 = P2^2;
sbit moto_right_2 = P2^3;

void car_go(int speed);
void car_back(int speed);
void car_right(int speed);
void car_left(int speed);
void car_stop(void);

#endif