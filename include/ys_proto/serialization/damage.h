#ifndef DAMAGE
#define DAMAGE

#include "types/ys/tdamage.h"

char* packtdamage(tdamage* damage);

void unpacktdamage(char* buffer, int size, tdamage* damage);

#endif
