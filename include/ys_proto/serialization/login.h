#ifndef LOGIN
#define LOGIN

#include "ys_proto/types/ys/tlogin.h"

char* packtlogin(tlogin* login);
void unpacktlogin(char* buffer, int size, tlogin* login);

#endif
