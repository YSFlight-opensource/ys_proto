#include "serialization/acknowledge.h"
#include "serialization/header.h"
#include <stdlib.h>
#include <string.h>


char* packtacknowledge(tacknowledge* ack)
{
    char* buffer = (char*)malloc(16);
    packtheader(12, 6, buffer);
    memcpy(buffer+8, (char*)ack, 8);
    return buffer;
}


void unpacktacknowledge(char* buffer, int size, tacknowledge* acknowledge)
{
    memcpy((char*)acknowledge, buffer, 8);
}
