#ifndef LOGIN
#define LOGIN

#include "../types/ys/tlogin.cpp"

char* packtlogin(tlogin* login);
void unpacktlogin(char* buffer, int size, tlogin* login);

#endif
