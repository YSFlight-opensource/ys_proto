#ifndef DAMAGE
#define DAMAGE

#include "../types/ys/tdamage.cpp"

char* packtdamage(tdamage* damage);

void unpacktdamage(char* buffer, int size, tdamage* damage);

#endif
