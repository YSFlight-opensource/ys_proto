#include "acknowledge.h"
#include "header.h"
#include <stdlib.h>
#include <string.h>


char* packtacknowledge(tacknowledge* ack)
{
    char* buffer = (char*)malloc(16);
    packtheader(12, 6, buffer);
    memcpy(buffer+8, (char*)ack, 4);
    return buffer;
}



