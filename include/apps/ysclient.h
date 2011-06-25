#ifndef YSCLIENT
#define YSCLIENT

#include <map>
#include <iostream>

#include "sockets/socketYS.h"
#include "apps.h"

#include "Vec.h"
#include "readPoly.h"
#include "Racer.h"

class YSclient : public Apps
{
    public:
        YSclient();
        void connect();

    protected:
        CheckPoints* cp;
        map<int, Racer*> racers;

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
