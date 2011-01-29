#include "flight.h"
#include "header.h"
#include <stdlib.h> // malloc
#include <string.h> //memcpy


char* packtflight(tflight* flight)
{
    char* buffer = (char*)malloc(93);
    packtheader(89, 11, buffer);
    memcpy(buffer+8, (char *)flight, 85);
    return buffer;
}


void unpacktflight(char* buffer, int size, tflight* flight)
{
    memcpy((char*)flight, buffer, 20);
}


