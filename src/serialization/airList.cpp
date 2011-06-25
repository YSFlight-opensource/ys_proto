#include "airList.h"
#include "header.h"
#include "../types/stringarray.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../debug.h"

char* packtairList(tairList* airList)
{
    int size = sizeofsarray(airList->aircraft, airList->nbOfAircraft)+8;
    //printf("size to send %d\n", size);
    char* buffer = (char*)malloc(size+4);
    packtheader(size, 44, buffer);
    memcpy(buffer+8, (char*)airList, 4);
    memcpy(buffer+12, airList->aircraft, size-8);
    //printf("Debug: \n");
    //debugChar(buffer,size+4);
    return buffer;
}

void unpacktairList(char* buffer, const int size, tairList* airList)
{
    memcpy((char *)airList, buffer, 4);
    airList->aircraft = buffer+4;
}

