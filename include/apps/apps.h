#ifndef APPS
#define APPS

#include "types/includeAll.h"

class Apps
{
    protected:
    theader getheadbuffer(char* buffer);
    int receivedmanager(char* buffer, theader headbuffer);
    virtual int alogin(tlogin* login) = 0;
    virtual int amap(tmap* map) = 0;
    virtual int aysversion(tint* inte) = 0;
    virtual int amissileOpt(tint* inte) = 0;
    virtual int aweaponOpt(tint* inte) = 0;
    virtual int ashowUserOpt(tint* inte) = 0;
    virtual int aweather(tweather* weather) = 0;
    virtual int aendairlist() = 0;
    virtual int aairList(tairList* airList) = 0;
    virtual int aairDisplayOption(tairDisplayOpt* airDisplayOpt) = 0;
    virtual int amessage(tmessage* message) = 0;
    virtual int aflight(tflight* flight) = 0;
    virtual int adamage(tdamage* damage) = 0;
    virtual int auserlist(tuserlist* userlist) = 0;
    virtual int aground(tground* ground) = 0;
    virtual int aleft(tleft* left, int is_ground) = 0;
    virtual int adefault(char* buffer, int size) = 0;
};
#endif
