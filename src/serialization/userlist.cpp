#include "serialization/userlist.h"
#include "serialization/header.h"
#include <stdlib.h> // malloc
#include <string.h> //memcpy


char* packtuserlist(tuserlist* userlist)
{
    char* buffer = (char*)malloc(36);
    packtheader(32, 1, buffer);
    memcpy(buffer+8, (char *)userlist, 28);
    return buffer;
}


void unpacktuserlist(char* buffer, int size, tuserlist* userlist)
{
    memcpy((char*)userlist, buffer, 28);
}

