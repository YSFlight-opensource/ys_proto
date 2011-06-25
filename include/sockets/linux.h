#ifdef __linux

#ifndef LINUX
#define LINUX

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fstream>
#include <iostream>



class Socket
{
int sock;

public:

    int connects(char* ip, int port);


    int sends(char* buffer, int size);

    int recvs(char* buffer, int size);

    void closes();

};
#endif
#endif
