#include "serialization/airDisplayOpt.h"
#include "serialization/header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "debug.h"

// RADAR ALT and THIRD VIEW
char* packtairDisplayOpt(tairDisplayOpt* airDisplayOpt)
{
    int size = strlen(airDisplayOpt->message)+9; // we should not forget \0
    //printf("display size %d\n", size);
    char* buffer = (char*)malloc(size+4);
    packtheader(size, 43, buffer);
    memcpy(buffer+8, airDisplayOpt, 4);
    memcpy(buffer+12, airDisplayOpt->message, size-8);
//    printf("DEBUG: \n");
//    debugChar(buffer, size+4);
    return buffer;
}

void unpacktairDisplayOpt(char* buffer, const int size, tairDisplayOpt* airDisplayOpt)
{
    memcpy((char *)airDisplayOpt, buffer, 4);
    airDisplayOpt->message = buffer+4;
}

