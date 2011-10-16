#ifndef TFLIGHT
#define TFLIGHT

#pragma pack(2)

// kind=11
struct tflight
{
    int stopWatch; // float ??
    int ID;
    short i1; // OK si i1==5, sinon décaler de 2 vers droite (i1=int) si i1==3
    float x;
    float z;
    float y;
    short heading;
    short AOA;
    short bank;
    short xSpeed;
    short ySpeed;
    short zSpeed;
    char u2[8];
    short fuel;
    char u3[6];
    char spoilerBrake;
    char flapsGear;
    char afterburnerSmokeTrailsGunfire;
    char u4;
    short gunAmmo;
    char rockets;
    char u5;
    char AAM;
    char AGM;
    char bombs;
    char lives;
    short u6;
    char elevator;
    char aileron;
    short u7;
    char trim;
};
#endif
