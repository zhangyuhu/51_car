#include "reg52.h"
#include "is_compatible.h"
#include "delay.h"
#include "buzz.h"

static void use_buzz_io (bool is_use_flag)
{
	if(is_use_flag) 
	{
		buzz_io = 0;
	}
	else
	{
    buzz_io = 1;
  }
}


void buzz_count_di(int count)
{
	while(count--)
	{
  	use_buzz_io(true);
	delayms(200);
	use_buzz_io(false);
	delayms(200);
	}
	use_buzz_io(false);
}
