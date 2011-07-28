#ifndef MESSAGE
#define MESSAGE

#include "types/ys/tmessage.h"

char* packtmessage(tmessage* message);

void unpacktmessage(char* buffer, const int size, tmessage* message);

#endif
