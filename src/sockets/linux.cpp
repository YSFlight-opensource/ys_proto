#ifdef __linux

#include "ys_proto/sockets/linux.h"

using namespace std;


int Socket::connects(char* ip, int port)
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


int Socket::sends(char* buffer, int size)
{
    if (send(sock, buffer, size, 0) != size)
    {
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
    if (recv_size < 0)
    {
        perror("Failed to receive data from server.\n");
        return recv_size;// make exception
    }
    else
        return recv_size;
}

void Socket::closes()
{
    close(sock);
}


#endif
