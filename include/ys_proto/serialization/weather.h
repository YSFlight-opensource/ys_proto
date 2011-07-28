#ifndef WEATHER
#define WEATHER

#include "ys_proto/types/ys/tweather.h"

char* packaskweather();
char* packtweather(tweather* weather);
void unpacktweather(char* buffer, int size, tweather* weather);
#endif
