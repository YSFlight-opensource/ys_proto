#ifndef AIRDISPLAYOPT
#define AIRDISPLAYOPT

#include "ys_proto/types/ys/tairDisplayOpt.h"

char* packtairDisplayOpt(tairDisplayOpt* airDisplayOpt);
void unpacktairDisplayOpt(char* buffer, const int size, tairDisplayOpt* airDisplayOpt);

#endif
