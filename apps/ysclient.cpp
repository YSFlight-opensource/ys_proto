#include "ysclient.h"
#include "../serialization/includeAll.cpp"
#include "../debug.h"

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
            int size = s.recvsYS();
            if (size<0)
            {
                perror("Failed to receive data.\n");
            }
            else
            {
                int res = receivedmanager(s.buffer, s.head);
                if (!res)
                {
                    printf("Failed to receive\n");
                    break;
                }
            }
            //s.freebuffer();

            //printf("res: %d\n", res);
        }

    }


}


