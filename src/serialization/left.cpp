#include "serialization/left.h"
#include "serialization/header.h"
#include <stdlib.h> // malloc
#include <string.h> //memcpy


char* packtleft(tleft* left)
{
    char* buffer = (char*)malloc(32);
    packtheader(12, 13, buffer);
    memcpy(buffer+8, (char *)left, 8);
    return buffer;
}


void unpacktleft(char* buffer, int size, tleft* left)
{
    memcpy((char*)left, buffer, 8);
}

