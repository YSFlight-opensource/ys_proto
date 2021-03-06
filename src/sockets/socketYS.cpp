#include "ys_proto/sockets/socketYS.h"

int SocketYS::sendsYS(char* buffer, int freebuffer)
{
    int size;
    memcpy((char*)&size, buffer, 4);
    //size = ntohl(size);
    //printf("size %d\n", size);
    int res = sends(buffer, size+4);
    if (freebuffer)
        free(buffer);
    return res;
}

int SocketYS::recvsn(char* buffer, int size)
{
    int recv_size  = recvs(buffer, size);
    int recv_size2;
    if (recv_size < 0)
    {
        return recv_size;
    }
    while (recv_size != size)
    {
        perror("Expected a longer packet!");
        recv_size2 = recvs(buffer+recv_size, size-recv_size);
        if (recv_size2 < 0)
        {
            return recv_size2;
        }
        recv_size += recv_size2;
    }
    return recv_size;
}

int SocketYS::recvsYS()
{
    int recv_size = recvsn(headbuffer, 8);
    if (recv_size < 0)
    {
        perror("Failed to receive the headbuffer.\n");
        return recv_size;
    }

    head = unpacktheader(headbuffer);
//        if (head.kind != 11)
//            printf("\nsize: %d, kind: %d\n", head.size, head.kind);
//        if (buffer!=NULL)
//        {
//            free(buffer);
//        }
    buffer = (char*)malloc(head.size-4);
    return recvsn(buffer, head.size-4);
    //debugChar(buffer2, head.size-4);

}



void SocketYS::freebuffer()
{
    free(buffer);
}

