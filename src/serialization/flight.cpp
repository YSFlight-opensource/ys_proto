#include "ys_proto/serialization/flight.h"
#include "ys_proto/serialization/header.h"
#include "ys_proto/debug.h"
#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> //memcpy




char* packtflight(tflight* flight, tflight2* flight2)
{
    char* buffer = (char*)malloc(93);
    packtheader(74, 11, buffer);
    memcpy(buffer+8, (char *)flight, 10);
    if (flight->i1 == 5)
        memcpy(buffer+18, (char *)flight2, 59);
    else if (flight->i1 == 3)
        memcpy(buffer+20, (char *)flight2, 59);
    return buffer;
}


void unpacktflight(char* buffer, int size, tflight* flight, tflight2* flight2)
{
//    std::cout << "....................."<< std::endl;
//    memcpy((char*)flight, buffer, 69);
    memcpy((char*)flight,  buffer, 10);
    if (flight->i1 == 5)
        memcpy((char*)flight2, buffer+10, 59);
    else if (flight->i1 == 3)
        memcpy((char*)flight2, buffer+12, 59);
    else
        printf("Unknown i1 %d \n", flight->i1);
//    struct ttflight tf;
//    memcpy((char*)&tf, buffer+10, 12);
//    debugHex((char*)&tf.x,4);
//    debugHex((char*)&tf.y,4);
//    debugHex((char*)&tf.z,4);
//    debugHex(buffer+8, 14);
//    std::cout << (float)tf.x << std::endl;
//    printf("test: %d ID: %d x: %f   y: %f   z: %f\n", size, flight->ID, flight->x, flight->y, flight->z);
//    printf("true: %f %f %f\n", tf.x, tf.y, tf.z);

}

