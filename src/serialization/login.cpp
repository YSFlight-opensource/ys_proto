#include "serialization/login.h"
#include "serialization/header.h"
#include "types/ys/tlogin.cpp"
#include <stdlib.h> // malloc
#include <string.h> //memcpy


char* packtlogin(tlogin* login)
{
    char* buffer = (char*)malloc(28);
    packtheader(24, 1, buffer);
    //htontlogin(&login); //convert the endianess
    memcpy(buffer+8, (char *)login, 20);
    return buffer;
}


void unpacktlogin(char* buffer, int size, tlogin* login)
{
    memcpy((char*)login, buffer, 20);
    //ntohtlogin(&login);
}
