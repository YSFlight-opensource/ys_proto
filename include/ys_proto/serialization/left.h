#ifndef LEFT
#define LEFT

#include "types/ys/tleft.h"
#include "serialization/left.h"
#include "serialization/header.h"


char* packtleft(tleft* left);


void unpacktleft(char* buffer, int size, tleft* left);

#endif
