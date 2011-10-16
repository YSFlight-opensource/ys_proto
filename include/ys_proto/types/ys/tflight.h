#ifndef TFLIGHT
#define TFLIGHT

//#pragma pack(2)

// kind=11
struct tflight
{
    int stopWatch;
    int ID;
    short i1; // 5 when lives (damages) can be a char, 3 else
};
#endif
