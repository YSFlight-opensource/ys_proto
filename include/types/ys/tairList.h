#ifndef TAIRLIST
#define TAIRLIST

struct tairList
{
    char  u1;
    char  nbOfAircraft; // ou char + short + char instead of char + char + char + char
    char  u2;
    char  u3;
    char* aircraft;
};

#endif
