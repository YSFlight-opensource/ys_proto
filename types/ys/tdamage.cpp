#ifndef TDAMAGE
#define TDAMAGE

// kind=22, size=24
struct tdamage
{
    int victim; // ground object (0) or pilot (1)
    int victimID;
    int killer; // ground object or pilot
    int killerID;
    short power;
    short shot; //10=missile/rocket hit its target, 11 gun bullet/bomb hit its target, 12 bomb/rocket explosion (not hit directly)
    short weapon; // gun=0, aim9=1, AGM=2, bomb500=3, rocket=4, AIM120=6, bomb250=7, bomb500HD=9, AIM9X=10 ; nothing sent for kamikaze kills!
    short u1;
    short u2;
};
#endif
