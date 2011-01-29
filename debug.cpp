#include <stdio.h>
#include "debug.h"

void debugHex(const char* buffer, int end=0)
{
    if (end == 0)
        end = sizeof(buffer);
    for(int i=0 ; i < end ; i++)
    {
        if (i%16 == 0)
            printf("\n");
        printf("%x ",(unsigned char)buffer[i]); // with signed char we would get -127 instead of 129 for example
    }
    printf("\n");
}

void debugDec(const char* buffer, unsigned int end=0)
{
    for(unsigned int i=0 ; i < end ; i++)
    {
        printf("%d ",(unsigned char)buffer[i]);
    }
    printf("\n");
}

void debugChar(const char* buffer, unsigned int end=0)
{
    for(unsigned int i=0 ; i < end ; i++)
    {
        printf("%c ",(unsigned char)buffer[i]);
    }
    printf("\n");
}

