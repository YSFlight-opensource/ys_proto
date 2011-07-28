#include "ys_proto/serialization/ground.h"
#include "ys_proto/serialization/header.h"
#include <stdlib.h> // malloc
#include <string.h> //memcpy


char* packtground(tground* ground)
{
    char* buffer = (char*)malloc(124);
    packtheader(120, 5, buffer);
    memcpy(buffer+8, (char *)ground, 116);
    return buffer;
}


void unpacktground(char* buffer, int size, tground* ground)
{
    if (size==120)
    {
        memcpy((char*)ground, buffer, 116);
        ground->u4 = 0;
        strcpy(ground->name2, "");
    }
    else
    {
        memcpy((char*)ground, buffer, 172);
    }
}



