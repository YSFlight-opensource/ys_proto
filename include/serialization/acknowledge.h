#ifndef ACKNOWLEDGE
#define ACKNOWLEDGE

#include "../types/ys/tacknowledge.cpp"

char* packtacknowledge(tacknowledge* ack);
void unpacktacknowledge(char* buffer, int size, tacknowledge* acknowledge);

#endif
