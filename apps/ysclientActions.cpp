#include "ysclient.h"
#include "../serialization/includeAll.cpp"
#include "../debug.h"

int YSclient::alogin(tlogin* login)
{
    printf("Login: %s %d\n",login->username, login->YSversion);
    return 1;
}

int YSclient::amap(tmap* map)
{
    printf("Map: %s\n",map->map);
    int res1 = s.sendsYS(packaskweather());
    return s.sendsYS(packtmap(*map)) * res1;
    // put a free...
}

int YSclient::aysversion(tint* inte)
{
    printf("YS version: %d\n", inte->val);
    tacknowledge ack;
    ack.id = 9;
    return s.sendsYS(packtacknowledge(&ack));
}

int YSclient::amissileOpt(tint* inte)
{
    printf("Missile option: %d\n", inte->val);
    tacknowledge ack;
    ack.id = 10;
    return s.sendsYS(packtacknowledge(&ack));
}

int YSclient::aweaponOpt(tint* inte)
{
    printf("Weapon option: %d\n", inte->val);
    tacknowledge ack;
    ack.id = 11;
    return s.sendsYS(packtacknowledge(&ack));
}

int YSclient::ashowUserOpt(tint* inte)
{
    printf("Show user option: %d\n", inte->val);
    //tacknowledge ack;
    //ack.id = 11;
    //return s.sendsYS(packtacknowledge(&ack));
    //FIXME: TO CHANGE
    return 1;
}

int YSclient::aweather(tweather* weather)
{
    printf("Weather:\n");
    printf("day: %d\noptions: %d\nvisib: %f\nwind: %f %f %f\n", weather->day, weather->options, weather->visibility, weather->windX, weather->windY, weather->windZ);
    tacknowledge ack;
    ack.id = 4;
    return s.sendsYS(packtacknowledge(&ack));
}

int YSclient::aendairlist()
{
    tacknowledge ack;
    ack.id = 7;
    return s.sendsYS(packtacknowledge(&ack));
}

int YSclient::aairList(tairList* airList)
{
    printf("Nb aircraft %d\n", airList->nbOfAircraft);
    printsarray(airList->aircraft, airList->nbOfAircraft);
    //BEWARE THE AIRCRAFT LIST DISEAPEAR AFTER THE free(buffer2), EVEN IF WE MAKE A COPY OF THE STRUCT BECAUSE WE USED A POINTER FOR airList.aircraft
    return s.sendsYS(packtairList(airList));
}


int YSclient::aairDisplayOption(tairDisplayOpt* airDisplayOpt)
{
    printf("Option: %s\n", airDisplayOpt->message);
    return s.sendsYS(packtairDisplayOpt(airDisplayOpt));
}

int YSclient::amessage(tmessage* message)
{
    printf("Message: %s\n", message->message);
    return 1;
}

int YSclient::aflight(tflight* flight)
{
    return 1;
}

int YSclient::adamage(tdamage* damage)
{
    printf("Damage: %d %d %d %d %d %d\n", damage->killer, damage->killerID, damage->victim, damage->victimID, damage->power, damage->weapon);
    return 1;
}

int YSclient::auserlist(tuserlist* userlist)
{
    return 1;
}

int YSclient::adefault(char* buffer, int size)
{
//    printf("\n ---- Hex ----- \n");
//    debugHex(buffer, size);
//    printf("\n ---- Dec ----- \n");
//    debugDec(buffer, size);
//    printf("\n ---- Char ----- \n");
//    debugChar(buffer, size);
//    printf("\n");
    return 1;
}
