#include "ground.h"
#include "header.h"
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
    memcpy((char*)ground, buffer, 116);
}



