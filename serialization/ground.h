#ifndef GROUND
#define GROUND

#include "../types/ys/tground.cpp"

char* packtground(tground* ground);

void unpacktground(char* buffer, int size, tground* ground);

#endif

