#include <reg52.h>
#include <serial.h>
#include "moto.h"
#include "is_compatible.h"
#include "delay.h"

#define ALLOWABLE_STATION  ((car_station_current >= STATION_CAR_GO) &&(car_station_current <= STATION_CAR_STOP))?(true):(false)

unsigned char receive_buf[3];
unsigned char receive_count;
int car_station_current = STATION_CAR_STOP;
int number_station_current = STATION_NUMBER_0;
bool receive_control_flag = false;

#if (USE_BLUETOOTH_SERIAL_MODULE == 1)
void sint() interrupt 4
{
    if(RI)
    {
        RI=0;
        receive_buf[receive_count]=SBUF;
        receive_count++;
        if(receive_count==3)
        {
            receive_control_flag = true;
            switch(receive_buf[2])
            {
                case 'A'://前进
                {
                    car_station_current = STATION_CAR_GO;
                    break;
                }
                case 'B'://后退
                {
                    car_station_current = STATION_CAR_BACK;
                    break;
                }
                case 'C'://左转
                {
                    car_station_current = STATION_CAR_LEFT;
                    break;
                }
                case 'D'://右转
                {
                    car_station_current = STATION_CAR_RIGHT;
                    break;
                }
                case 'F'://stop
                {
                    car_station_current = STATION_CAR_STOP;
                    break;
                }

                case '1':
                {
                    number_station_current = STATION_NUMBER_1;
                    break;
                }
                case '2':
                {
                    number_station_current = STATION_NUMBER_2;
                    break;
                }
                case '3':
                {
                    number_station_current = STATION_NUMBER_3;
                    break;
                }
                case '4':
                {
                    number_station_current = STATION_NUMBER_4;
                    break;
                }
                case '5':
                {
                    number_station_current = STATION_NUMBER_5;
                    break;
                }
                case '6':
                {
                    number_station_current = STATION_NUMBER_6;
                    break;
                }
                case '7':
                {
                    number_station_current = STATION_NUMBER_7;
                    break;
                }
                case '8':
                {
                    number_station_current = STATION_NUMBER_8;
                    break;
                }
                case '9':
                {
                    number_station_current = STATION_NUMBER_9;
                    break;
                }
                default:
                {
                    car_station_current = STATION_CAR_STOP;
                    number_station_current = STATION_NUMBER_0;
                    break;
                }
            }
            receive_count=0;
            receive_control_flag = false;
        }

    }
}

void serial_init(void)
{
    TMOD=0x20;
    TH1=0xFd;          //11.0592M,9600
    TL1=0xFd;
    SCON=0x50;
    PCON=0x00;
    TR1=1;
    ES=1;
    EA=1;
}

void serial_control_car(void)
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

int get_serial_number(void)
{
    return number_station_current;
}
#endif

 #if (USE_NRF24L01 == 1)
void serial_init(void)
{
                     //初始化串行口和波特率发生器
    SCON =0x58;          //选择串口工作方式，打开接收允许
    TMOD =0x21;          //定时器1工作在方式2，定时器0工作在方式1
    TH1 =0xfd;           //实现波特率9600（系统时钟11.0592MHZ）
    TL1 =0xfd;
    TR1 =1;              //启动定时器T1
    ET1 =0;
    ES=1;                //允许串行口中断
    PS=1;                //设计串行口中断优先级
    EA =1;               //单片机中断允许
}
#endif
