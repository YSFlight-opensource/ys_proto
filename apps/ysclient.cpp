#include "ysclient.h"
#include "../serialization/includeAll.cpp"


void YSclient::connect()
{
    //int res = s.connects((char *)"127.0.0.1",7915);
    int res = s.connects((char *)"192.168.1.2",7910);
    //int res = s.connects((char *)"192.168.56.1",7915);
    //int res = s.connects((char *)"192.168.1.2",7915);
    //int res = s.connects((char *)"195.146.247.50",7915);
    if (res)
    {
        printf("Connected\n");
        tlogin login;
        strcpy(login.username, "doing_tests");
        login.YSversion = 20101211;
        s.sendsYS(packtlogin(&login),0);
        while (1)
        {
            char* buffer = (char*)malloc(8);
            int recv_size = s.recvs(buffer, 8);
            if (recv_size == 8)
            {
                theader head = getheadbuffer(buffer);
                printf("\nsize: %d, kind: %d\n", head.size, head.kind);
                char* buffer2 = (char*)malloc(head.size-4);
                s.recvs(buffer2, head.size-4);
                //debugChar(buffer2, head.size-4);
                int res = receivedmanager(buffer2, head);
                free(buffer);
                free(buffer2);
                if (!res)
                {
                    printf("Failed to receive\n");
                    break;
                }
            }

            //printf("res: %d\n", res);
        }

    }


}


