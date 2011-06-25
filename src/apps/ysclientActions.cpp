#include "apps/ysclient.h"
#include "serialization/includeAll.h"
#include "debug.h"
#include <math.h>

#include <time.h>


// IDEA ---------
// ALL PACK FUNCTION IN SERIALIZE  COULD WRITE THE SIZE

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
    ack.info = 0;
    return s.sendsYS(packtacknowledge(&ack));
}

int YSclient::amissileOpt(tint* inte)
{
    printf("Missile option: %d\n", inte->val);
    tacknowledge ack;
    ack.id = 10;
    ack.info = 0;
    return s.sendsYS(packtacknowledge(&ack));
}

int YSclient::aweaponOpt(tint* inte)
{
    printf("Weapon option: %d\n", inte->val);
    tacknowledge ack;
    ack.id = 11;
    ack.info = 0;
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
    ack.info = 0;
    return s.sendsYS(packtacknowledge(&ack));
}

int YSclient::aendairlist()
{
    tacknowledge ack;
    ack.id = 7;
    ack.info = 0;
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
    //printf("ID: %d x: %f   z: %f   y: %f\n", flight->ID, flight->x, flight->z, flight->y);
    float speed = 0.19438612860586*sqrt(flight->xSpeed * flight->xSpeed + flight->ySpeed * flight->ySpeed + flight->zSpeed * flight->zSpeed);
    int d = racers[flight->ID]->check(flight->x, flight->z, flight->y, speed, time (NULL));
    if (d == -1)
    {
            cout  <<racers[flight->ID]->name() << " missed a check-point !" << endl;
    }
    else if (d == 2)
    {
        cout <<  racers[flight->ID]->name() << " finished the lap " << racers[flight->ID]->lapNumber()-1 << endl;
    }
    else if (d == 3)
    {
        tmessage* mess = (tmessage*)malloc(sizeof(*mess));
        mess->u = 0;
        mess->message = (char*)malloc(500);
        sprintf (mess->message, "%s finished in %d s ; Top speed %d kt", racers[flight->ID]->name().c_str(), (int)racers[flight->ID]->time(), racers[flight->ID]->topSpeed());
        s.sendsYS(packtmessage(mess));
       cout << racers[flight->ID]->name() << " finished the race in " <<  racers[flight->ID]->time() << "s ; Top speed: "<< racers[flight->ID]->topSpeed() << "kt" << endl;
    }
    if (d != 0)
    {
        printf ("check %d at %d\n", d, flight->stopWatch);
        printf ("speed: %f \n", speed);
    }
    //cout << clock() << endl;
    //cout << flight->stopWatch << endl;
    return 1;
}

int YSclient::adamage(tdamage* damage)
{
    printf("DAMAGE: killer: (%d,%d)  victim: (%d,%d) power: %d weapon: %d shot: %d, u1: %d, u2: %d\n", damage->killer, damage->killerID, damage->victim, damage->victimID, damage->power, damage->weapon, damage->shot, damage->u1, damage->u2);
    return 1;
}

int YSclient::auserlist(tuserlist* userlist)
{
    return 1;
}

int YSclient::aground(tground* ground)
{
    //printf("Join %s %s type: %d iff: %d id:%d gro_id: %d flag: %d u1: %d u2: %f u3: %d u4: %d (x,y,z,r1,r2,r3)=(%f,%f,%f,%f,%f,%f)\n", ground->name2, ground->name, ground->type, ground->iff, ground->id, ground->gro_id, ground->flag, ground->u1, ground->u2, ground->u3, ground->u4, ground->x, ground->y, ground->z, ground->r1, ground->r2, ground->r3);
    tacknowledge ack;
    if (ground->type == 65537)
    {
        printf("GROUNDJOIN %s %s type: %d iff: %d id:%d\n", ground->name2, ground->name, ground->type, ground->iff, ground->id);
        ack.id = 1;
    }
    else
    {
        printf("PLAYERJOIN %s %s type: %d iff: %d id:%d\n", ground->name2, ground->name, ground->type, ground->iff, ground->id);
        ack.id=0;
        racers[ground->id] = new Racer(ground->name2, ground->name, 1, cp);
    }
    ack.info = ground->id;
    return s.sendsYS(packtacknowledge(&ack));
}

int YSclient::aleft(tleft* left, int is_ground=0)
{

    tacknowledge ack;
    if (is_ground)
    {
        ack.id = 3;
        printf("GROUNDLEFT: %d has left %d.\n", left->id, left->u);
    }
    else
    {
        ack.id = 2;
        printf("PLAYERLEFT: %d has left %d.\n", left->id, left->u);
        racers.erase(left->id);
    }
    ack.info = left->id;
    return s.sendsYS(packtacknowledge(&ack));
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
