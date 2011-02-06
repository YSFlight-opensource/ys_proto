#ifndef YSCLIENT
#define YSCLIENT

#include "../sockets/socketYS.cpp"
#include "apps.h"

class YSclient : public Apps
{
    public:
    void connect();

    private:
    SocketYS s;
    int alogin(tlogin* login);
    int amap(tmap* map);
    int aysversion(tint* inte);
    int amissileOpt(tint* inte);
    int aweaponOpt(tint* inte);
    int ashowUserOpt(tint* inte);
    int aweather(tweather* weather);
    int aendairlist();
    int aairList(tairList* airList);
    int aairDisplayOption(tairDisplayOpt* airDisplayOpt);
    int amessage(tmessage* message);
    int aflight(tflight* flight);
    int adamage(tdamage* damage);
    int auserlist(tuserlist* userlist);
    int aground(tground* ground);
    int aleft(tleft* left, int is_ground);
    int adefault(char* buffer, int size);
};
#endif
