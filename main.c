#include <stdio.h>
#include "tcpClient.h"
int main()
{
    printf("main start.\n");

    tcpClientStart();
    printf("main end.\n");
    
    return 0;
}