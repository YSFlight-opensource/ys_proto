#include "ys_proto/serialization/message.h"
#include "ys_proto/serialization/header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ys_proto/debug.h"


char* packtmessage(tmessage* message)
{
    int size = strlen(message->message)+13; // we should not forget \0
    //printf("display size %d\n", size);
    char* buffer = (char*)malloc(size+4);
    packtheader(size, 32, buffer);
    memcpy(buffer+8, message, 8);
    memcpy(buffer+16, message->message, size-12);
//    printf("DEBUG: \n");
//    debugChar(buffer, size+4);
    return buffer;
}

void unpacktmessage(char* buffer, const int size, tmessage* message)
{
    memcpy((char *)message, buffer, 8);
    message->message = buffer+8;
}


