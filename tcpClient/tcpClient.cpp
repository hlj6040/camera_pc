#include "tcpClient.h"

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

const uint16_t sockPort = 8989;
const char* sockIPAdd = "192.168.195.1";

void tcpClientStart()
{
    printf("tcp client start.\n");

    int sockFd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockFd == -1)
    {
        printf("Notable  create socke, errno: %d.", errno);
    }
    
    sockaddr_in  sockAddr = {0};
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(sockPort);
    sockAddr.sin_addr.s_addr = inet_addr(sockIPAdd);

    while(1)
    {
        int32_t err = connect(sockFd, (const sockaddr*) &sockAddr, sizeof(sockAddr));
        if(err != 0)
        {
            printf("socket connect ip: %s, port: %d failed.\n", sockIPAdd, sockPort);
            continue;
        }
        
        char recvBuff[100] = {0};
        char sendBuff[100] = "hello world.\n";
        int recvLen = 0;
        while(1)
        {
            printf("send data: %s to IP:%s", sendBuff, sockIPAdd);
            send(sockFd, sendBuff, strlen(sendBuff), 0);
            memset(sendBuff, 0, sizeof(sendBuff));

            recvLen = recv(sockFd, recvBuff, sizeof(recvBuff)-1, 0);
            if(recvLen == -1)
            {
                printf("recv data err.\n");
                memset(recvBuff, 0, sizeof(recvBuff));
                memcpy(sendBuff, "hello world\n", 13);
            }
            else
            {
                printf("recv data: %s.\n", recvBuff);
                memcpy(sendBuff, recvBuff, sizeof(recvBuff));
            }

        }
    }
    printf("tcp client end.\n");
}