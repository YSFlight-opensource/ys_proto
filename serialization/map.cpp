#include "map.h"
#include "header.h"
#include "../types/ys/tmap.cpp"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



char* packtmap(tmap map)
{
    char* buffer = (char*)malloc(68);
    packtheader(64, 4, buffer);
    memcpy(buffer+8, (char *)&map, 60);
    return buffer;
}


void unpacktmap(char* buffer, int size, tmap* map)
{
    memcpy((char *)map, buffer, 60);//60 == size-4
}
