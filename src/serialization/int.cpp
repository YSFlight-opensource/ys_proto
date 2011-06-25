#include "serialization/int.h"
#include "serialization/header.h"
#include <stdlib.h>
#include <string.h>


char* packtint(tint* inte)
{
    char* buffer = (char*)malloc(12);
    packtheader(8, 6, buffer);
    memcpy(buffer+8, (char*)inte, 4);
    return buffer;
}


void unpacktint(char* buffer, int size, tint* inte)
{
    memcpy((char *)inte, buffer, 4);
}

