#ifndef DAMAGE
#define DAMAGE

#include "ys_proto/types/ys/tdamage.h"

char* packtdamage(tdamage* damage);

void unpacktdamage(char* buffer, int size, tdamage* damage);

#endif
