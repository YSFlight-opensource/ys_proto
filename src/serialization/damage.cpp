#include "ys_proto/serialization/damage.h"
#include "ys_proto/serialization/header.h"
#include <stdlib.h> // malloc
#include <string.h> //memcpy


char* packtdamage(tdamage* damage)
{
    char* buffer = (char*)malloc(32);
    packtheader(28, 22, buffer);
    memcpy(buffer+8, (char *)damage, 24);
    return buffer;
}


void unpacktdamage(char* buffer, int size, tdamage* damage)
{
    memcpy((char*)damage, buffer, 24);
    //ntohtlogin(&login);
}


