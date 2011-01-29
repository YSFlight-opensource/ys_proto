#ifndef TDAMAGE
#define TDAMAGE

// kind=22, size=24
struct tdamage
{
    int victim; // ground object or pilot
    int victimID;
    int killer; // ground object or pilot
    int killerID;
    short power;
    short weapon;
};
#endif
