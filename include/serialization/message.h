#ifndef MESSAGE
#define MESSAGE

#include "../types/ys/tmessage.cpp"

char* packtmessage(tmessage* message);

void unpacktmessage(char* buffer, const int size, tmessage* message);

#endif
