#ifndef __BUZZ_H__
#define __BUZZ_H__

#include "reg52.h"
#include "is_compatible.h"

sbit buzz_io  = P2^4;  


void buzz_count_di(int count);


#endif