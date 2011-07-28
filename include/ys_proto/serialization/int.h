#ifndef INTE
#define INTE

#include "ys_proto/types/ys/tint.h"

char* packtint(tint inte);
void unpacktint(char* buffer, int size, tint* inte);

#endif

