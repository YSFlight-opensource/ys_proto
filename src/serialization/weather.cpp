#include "serialization/weather.h"
#include "serialization/header.h"
#include "types/ys/tint.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



char* packaskweather()
{
    char* buffer = (char*)malloc(8);
    packtheader(4, 33, buffer);
    return buffer;
}

char* packtweather(tweather* weather)
{
    char* buffer = (char*)malloc(36);
    packtheader(32, 33, buffer);
    memcpy(buffer+8, (char *)weather, 28);
    return buffer;
}


void unpacktweather(char* buffer, int size, tweather* weather)
{
    memcpy((char*)weather, buffer, 32);
}


