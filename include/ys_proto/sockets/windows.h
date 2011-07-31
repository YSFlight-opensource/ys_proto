
#ifndef __linux

#ifndef WINDOWS
#define WINDOWS

#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

// WARNING: to avoid "undefined reference WSAStartup"
// Code::Blocks->Settings->Compiler->Linker->Other linker options: => "-lws2_32";

class Socket
{
    SOCKET sock;

public:

    int connects(char* ip, int port);

    int recvs(char* buffer, int size);

    int sends(char* buffer, int size);

    void closes();

};
#endif
#endif
