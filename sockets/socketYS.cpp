#include "linux.cpp"
#include "windows.cpp"
#include <stdlib.h>

class SocketYS: public Socket
{
public:
    char* headbuffer;
//    char* buffer;

    SocketYS()
    {
        headbuffer = char[8];
//        buffer = NULL;
    }

    int sendsYS(char* buffer, int freebuffer=1)
    {
        int size;
        memcpy((char*)&size, buffer, 4);
        //size = ntohl(size);
        printf("size %d\n", size);
        return sends(buffer, size+4);
        if (freebuffer)
            free(buffer);
    }

    int recvsn(char* buffer, int size)
    {
        int recv_size  = s.recvs(buffer, size);
        int recv_size2;
        if (recv_size < 0)
        {
            return recv_size;
        }
        while (recv_size != size)
        {
            recv_size2 = recvs(buffer+recv_size, size-recv_size);
            if (recv_size2 < 0)
            {
                return recv_size2;
            }
            recv_size += recv_size2;
        }
        return recv_size;
    }

    int recvsYS(char* buffer)
    {
        int recv_size = recvsn(headbuffer, 8);
        if (recv_size < 0)
        {
            perror("Failed to receive the headbuffer.\n");
            return recv_size;
        }

        theader head = getheadbuffer(headbuffer);
        printf("\nsize: %d, kind: %d\n", head.size, head.kind);
//        if (buffer!=NULL)
//        {
//            free(buffer);
//        }
        char* buffer = (char*)malloc(head.size-4);
        s.recvsn(buffer, head.size-4);
        //debugChar(buffer2, head.size-4);
        int res = receivedmanager(buffer, head);

        if (!res)
        {
            printf("Failed to receive\n");
            break;
        }
    }
};
