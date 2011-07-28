#ifndef SOCKET_YS
#define SOCKET_YS

#include "types/ys/theader.h"
#include "serialization/header.h"
#include "linux.h"
#include "windows.h"
#include <stdlib.h>

class SocketYS: public Socket
{
public:
    struct theader head;
    char headbuffer[8];
    char* buffer;



    int sendsYS(char* buffer, int freebuffer=1);

    int recvsn(char* buffer, int size);

    int recvsYS();



    void freebuffer();
};

#endif
