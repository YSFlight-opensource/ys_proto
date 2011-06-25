#ifndef AIRLIST
#define AIRLIST

#include "types/ys/tairList.h"

char* packtairList(tairList* airList);
void unpacktairList(char* buffer, const int size, tairList* airList);
//void unpacktairList(char* buffer, int size, tairList* airList);

#endif
