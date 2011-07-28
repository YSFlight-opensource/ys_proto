#ifndef ACKNOWLEDGE
#define ACKNOWLEDGE

#include "ys_proto/types/ys/tacknowledge.h"

char* packtacknowledge(tacknowledge* ack);
void unpacktacknowledge(char* buffer, int size, tacknowledge* acknowledge);

#endif
