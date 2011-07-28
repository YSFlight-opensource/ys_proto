#ifndef USERLIST
#define USERLIST

#include "ys_proto/types/ys/tuserlist.h"

char* packtuserlist(tuserlist* userlist);

void unpacktuserlist(char* buffer, int size, tuserlist* userlist);

#endif

