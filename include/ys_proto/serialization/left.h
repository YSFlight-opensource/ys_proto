#ifndef LEFT
#define LEFT

#include "ys_proto/types/ys/tleft.h"
#include "ys_proto/serialization/left.h"
#include "ys_proto/serialization/header.h"


char* packtleft(tleft* left);


void unpacktleft(char* buffer, int size, tleft* left);

#endif
