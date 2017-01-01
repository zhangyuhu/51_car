#include "reg52.h"
#include "moto.h"

#define MAX_SPEED  10;
static void left_wheel_run(bool is_left_run_flag)
{
	if(is_left_run_flag) 
	{
		moto_left_1 = 1;
	}
	else
	{
    moto_left_1 = 0;
  }
	moto_left_2 = ~moto_left_1; 
}

static void right_wheel_run(bool is_right_run_flag)
{
	if(is_right_run_flag) 
	{
		moto_right_1 = 1;
	}
	else
	{
    moto_right_1 = 0;
  }
	moto_right_2 = ~moto_right_1; 
}

static void all_wheel_stop()
{
 moto_left_1  = 0;  
 moto_left_2  = 0;
 moto_right_1 = 0;
 moto_right_2 = 0;
}

void car_go(int speed)
{
int max_speed_use = MAX_SPEED;

if (speed > 10) speed = 10;
if (speed < 0)  speed =  0;

while(max_speed_use--)
{
		speed--;
		if(speed >=0)
		{
	  	left_wheel_run(1);
	  	right_wheel_run(1);
		}
		else
		{
		  moto_left_1  = 0;  
	  	moto_left_2  = 0;
		  moto_right_1 = 0;
		  moto_right_2 = 0;
		}
}
}

void car_stop(void)
{
all_wheel_stop();
}

void car_back(int speed)
{
int max_speed_use = MAX_SPEED;

if (speed > 10) speed = 10;
if (speed < 0)  speed =  0;

while(max_speed_use--)
{
		speed--;
		if(speed >=0)
		{
	  	left_wheel_run(0);
	  	right_wheel_run(0);
		}
		else
		{
		  moto_left_1  = 0;  
	  	moto_left_2  = 0;
		  moto_right_1 = 0;
		  moto_right_2 = 0;
		}
}
}

void car_right(int speed)
{
int max_speed_use = MAX_SPEED;

if (speed > 10) speed = 10;
if (speed < 0)  speed =  0;

while(max_speed_use--)
{
		speed--;
		if(speed >=0)
		{
	  	left_wheel_run(1);
	  	right_wheel_run(0);
		}
		else
		{
		  moto_left_1  = 0;  
	  	moto_left_2  = 0;
		  moto_right_1 = 0;
		  moto_right_2 = 0;
		}
}
}

void car_left(int speed)
{
int max_speed_use = MAX_SPEED;

if (speed > 10) speed = 10;
if (speed < 0)  speed =  0;

while(max_speed_use--)
{
		speed--;
		if(speed >=0)
		{
	  	left_wheel_run(0);
	  	right_wheel_run(1);
		}
		else
		{
		  moto_left_1  = 0;  
	  	moto_left_2  = 0;
		  moto_right_1 = 0;
		  moto_right_2 = 0;
		}
}
}