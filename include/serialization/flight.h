#ifndef FLIGHT
#define FLIGHT

#include "types/ys/tflight.h"

char* packtflight(tflight* flight);

void unpacktflight(char* buffer, int size, tflight* flight);

#endif

