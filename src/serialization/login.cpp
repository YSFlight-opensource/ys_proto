#include "ys_proto/serialization/login.h"
#include "ys_proto/serialization/header.h"
#include "ys_proto/types/ys/tlogin.h"
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
