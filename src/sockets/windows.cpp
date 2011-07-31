#ifndef __linux
#include "ys_proto/sockets/windows.h"

int Socket::connects(char* ip, int port)
{
    WSADATA WSAData;
    int error = WSAStartup(MAKEWORD(2,0), &WSAData);
    if (error!=0)
    {
        perror("Cannot init Winsock\n");
        return 0;
    }
    SOCKADDR_IN sin;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
    {
        perror("Cannot create the socket\n");
        return 0;
    }

  // ********************************************************
  // Activation de l'option permettant d'activer l'algorithme de Nagle
  // ********************************************************
  int tempo=1;
  int erreur=setsockopt(sock,IPPROTO_TCP,TCP_NODELAY,(char *)&tempo,sizeof(tempo));
  if (erreur!=0)
        printf("Sorry, I cannot use this conf because of : %d %d",erreur,WSAGetLastError());
  else
        printf("\nsetsockopt  : OK\n");

    sin.sin_family				= AF_INET;
    sin.sin_addr.s_addr			= inet_addr(ip);
    sin.sin_port				= htons(port);

    if (connect(sock, (SOCKADDR *)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        perror("Failed to connect with the server.\n");
        return 0;
    }
    else
        return 1;
}

int Socket::sends(char* buffer, int size)
{
    if (send(sock, buffer, size, 0) == SOCKET_ERROR)
    {
        //printf("Error: %d ", send(sock, buffer, size, 0));
        perror("Failed to send data to the server.\n");
        return 0;
    }
    else
        return 1;
}

int Socket::recvs(char* buffer, int size)
{
    int recv_size = recv(sock, buffer, size, 0);
    if (recv_size != size)
    {
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\nWarning only received %d bytes instead of %d\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n", recv_size, size);
        if (recv_size==0)
        {// occurs after inactivity -> YS seems to send a void packet
            int i;
            printf("Press ENTER\n");
            scanf("%d",&i);
            return -1;
        }
    }
    if (recv_size < 0)// blocking
    {
        perror("Failed to receive data from the server.\n");
        return recv_size;// make exception
    }
    else
        return recv_size;
}

void Socket::closes()
{
    closesocket(sock);
    WSACleanup();
}

#endif
