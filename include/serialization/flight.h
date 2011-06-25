#ifndef FLIGHT
#define FLIGHT

#include "../types/ys/tflight.cpp"

char* packtflight(tflight* flight);

void unpacktflight(char* buffer, int size, tflight* flight);

#endif

