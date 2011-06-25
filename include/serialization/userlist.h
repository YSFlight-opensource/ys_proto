#ifndef USERLIST
#define USERLIST

#include "../types/ys/tuserlist.cpp"

char* packtuserlist(tuserlist* userlist);

void unpacktuserlist(char* buffer, int size, tuserlist* userlist);

#endif

