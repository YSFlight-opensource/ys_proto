#ifndef WEATHER
#define WEATHER

#include "../types/ys/tweather.cpp"

char* packaskweather();
char* packtweather(tweather* weather);
void unpacktweather(char* buffer, int size, tweather* weather);
#endif