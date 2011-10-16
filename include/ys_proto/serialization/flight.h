#ifndef FLIGHT
#define FLIGHT

#include "ys_proto/types/ys/tflight.h"
#include "ys_proto/types/ys/tflight2.h"

char* packtflight(tflight* flight, tflight2* flight2);

void unpacktflight(char* buffer, int size, tflight* flight, tflight2* flight2);

#endif

