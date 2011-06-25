#include "apps/ysclient.h"
#include "serialization/includeAll.h"
#include "debug.h"
#include "apps/activity_message.h"





YSclient::YSclient()
{
     cp = read_file((char*)"midohiol.race");
     //cout << *cp  << std::endl;


}

void YSclient::connect()
{
    //int res = s.connects((char *)"127.0.0.1",7915);
    //int res = s.connects((char *)"127.0.0.1",7915);
    //int res = s.connects((char *)"192.168.56.1",7915);
    int res = s.connects((char *)"192.168.1.2",7915);
    //int res = s.connects((char *)"195.146.247.50",7915);
    if (res)
    {
        printf("Connected\n");
        printf("int %ld float %ld\n", sizeof(int), sizeof(float));
        tlogin login;
        strcpy(login.username, "doing_tests");
        login.YSversion = 20110207;
        s.sendsYS(packtlogin(&login),0);
        pthread_t thread_activity_message;
        pthread_create(&thread_activity_message, NULL, send_activity_message, (void *)&s);

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
        int rest = pthread_cancel(thread_activity_message);
        printf("Fin thread %d.", rest);

    }


}


