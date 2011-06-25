#ifndef AIRDISPLAYOPT
#define AIRDISPLAYOPT

#include "../types/ys/tairDisplayOpt.cpp"

char* packtairDisplayOpt(tairDisplayOpt* airDisplayOpt);
void unpacktairDisplayOpt(char* buffer, const int size, tairDisplayOpt* airDisplayOpt);

#endif
