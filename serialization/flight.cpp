#include "flight.h"
#include "header.h"
#include "../debug.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h> // malloc
#include <string.h> //memcpy




struct ttflight
{
    float x;
    float z;
    float y;
};

char* packtflight(tflight* flight)
{
    char* buffer = (char*)malloc(93);
    packtheader(74, 11, buffer);
    memcpy(buffer+8, (char *)flight, 69);
    return buffer;
}


void unpacktflight(char* buffer, int size, tflight* flight)
{
//    std::cout << "....................."<< std::endl;
    memcpy((char*)flight, buffer, 69);//69
    struct ttflight tf;
    memcpy((char*)&tf, buffer+10, 12);
//    debugHex((char*)&tf.x,4);
//    debugHex((char*)&tf.y,4);
//    debugHex((char*)&tf.z,4);
//    debugHex(buffer+8, 14);
//    std::cout << (float)tf.x << std::endl;
//    printf("test: %d ID: %d x: %f   y: %f   z: %f\n", size, flight->ID, flight->x, flight->y, flight->z);
//    printf("true: %f %f %f\n", tf.x, tf.y, tf.z);

}

