#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unpack.h"

int unpack_int(char* buffer, int pos)
{
    int res;
    memcpy((char*)&res, buffer+pos, 4);
    return res;
}

float unpack_float(char* buffer, int pos)
{
    float res;
    memcpy((char*)&res, buffer+pos, 4);
    return res;
}

short unpack_short(char* buffer, int pos)
{
    short res;
    memcpy((char*)&res, buffer+pos, 2);
    return res;
}

void display_unpack(char* format, char* buffer)
{
    int pos = 0;
    char* type = strtok (format,",");
    while (type != NULL)
    {
        if (type[0]=='i')
        {
            printf("%d) int: %d\n", pos, unpack_int(buffer, pos));
            pos +=4;
        }
        else if (type[0]=='f')
        {
            printf("%d) float: %f\n", pos, unpack_float(buffer, pos));
            pos +=4;
        }
        else if(type[0]=='s')
        {
            printf("%d) short: %d\n", pos, unpack_short(buffer, pos));
            pos +=2;
        }
        else if(type[0]=='c')
        {
            int length = atoi(type+1);
            printf("%d) string: %s\n", pos, buffer+pos);
            pos += length;
        }
        type = strtok (NULL, ",");
    }
}


