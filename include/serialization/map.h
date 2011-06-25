#ifndef MAP
#define MAP

#include "types/ys/tmap.h"

char* packtmap(tmap map);
void unpacktmap(char* buffer, int size, tmap* map);

#endif
