#ifndef HEADER
#define HEADER

#include "../types/ys/theader.cpp"

void packtheader(int size, int kind, char* buffer);
theader unpacktheader(char* buffer);

#endif
