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

using namespace std;

class Socket
{
int sock;

public:

    int connects(char* ip, int port)
    {
        struct sockaddr_in server;
        /* Create the TCP socket */
        if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        {
          perror("Failed to create the socket.\n");
          return 0;
        }

        /* Construct the server sockaddr_in structure */
        memset(&server, 0, sizeof(server));       /* Clear struct */
        server.sin_family = AF_INET;                  /* Internet/IP */
        server.sin_addr.s_addr = inet_addr(ip);  /* IP address */
        server.sin_port = htons(port);       /* server port */

        /* Establish connection */
        if (connect(sock,
                    (struct sockaddr *) &server,
                    sizeof(server)) < 0)
        {
          perror("Failed to connect with the server.\n");
          return 0;
        }
        else
            return 1;
    }


    int sends(char* buffer, int size)
    {
        if (send(sock, buffer, size, 0) != size)
        {
            perror("Failed to send data to the server.\n");
            return 0;
        }
        else
            return 1;
    }

    int recvs(char* buffer, int size)
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
        if (recv_size < 0)
        {
            perror("Failed to receive data from server.\n");
            return recv_size;// make exception
        }
        else
            return recv_size;
    }

    void closes()
    {
        close(sock);
    }

};
#endif
#endif
