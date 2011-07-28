#ifndef HEADER
#define HEADER

#include "ys_proto/types/ys/theader.h"

void packtheader(int size, int kind, char* buffer);
struct theader unpacktheader(char* buffer);

#endif
