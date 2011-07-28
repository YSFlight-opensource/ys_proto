#ifndef MESSAGE
#define MESSAGE

#include "ys_proto/types/ys/tmessage.h"

char* packtmessage(tmessage* message);

void unpacktmessage(char* buffer, const int size, tmessage* message);

#endif
