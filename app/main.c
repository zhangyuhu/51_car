/*------------------------------------------------------------------*/
/* --- 51 car by zhangyuhude@163.com -------------------------------*/
/*------------------------------------------------------------------*/

#include "reg52.h"
#include "moto.h"
#include "is_compatible.h"
#include "delay.h"
#include "buzz.h"
#include "serial.h"

//ģ��ѡ��
#define USE_BLUETOOTH_SERIAL_MODULE      (0)           //ʹ����������ģ��
#define USE_NRF24L01                     (1)           //ʹ�� NRF24L01ģ��
//add this sentence in order to test git

void main(void)
{
 serial_init();
while(1)
{
#if 0
    car_go();
    buzz_count_di(5);
    delays(5);
    car_stop();
    delays(5);
    car_back();
    delays(5);
    car_left();
    delays(5);
    car_right();
    delays(5);
#endif
    serial_control_car();
    buzz_count_di(get_serial_number());
}
}

