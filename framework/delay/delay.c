#include "reg52.h"
#include "intrins.h"
#include "delay.h"
#include "is_compatible.h"

void delayms(int i)
{
    unsigned char a,b,c;
    while(i--)
    {
        for(c=1;c>0;c--)
            for(b=142;b>0;b--)
                for(a=2;a>0;a--);
    }
}

void delays(int i)
{
    unsigned char a,b,c;
    while(i--)
    {
        for(c=167;c>0;c--)
            for(b=171;b>0;b--)
                for(a=16;a>0;a--);
        _nop_();  //if Keil,require use intrins.h
    }
}