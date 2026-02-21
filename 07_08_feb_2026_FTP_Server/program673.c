// Client Code

#include <stdio.h>              // printf, scanf
#include <stdlib.h>             // malloc, free
#include <string.h>             // memset, memcmp

#include <unistd.h>             // close, write, read
#include <fcntl.h>              // creat, unlink

#include <sys/socket.h>         // socket, bind, listen, accept, connect
#include <netinet/in.h>         // sockaddr_in, htons
#include <arpa/inet.h>          // inet_pton


int main(void)
{
    int iServerSocketFD = 0;
    int iRet = 0;
    struct sockaddr_in ServerAddr;
    int iPort = 8080;
    char chBuffer[1024] = {'\0'};

    // Step 1 : Create TCP socket

    iServerSocketFD = socket(AF_INET, SOCK_STREAM, 0);

    if (iServerSocketFD < 0)
    {
        printf("Unable to create the server socke\n");
        return -1;
    }

    printf("Socket is created successfully with fd : %d\n", iServerSocketFD);

    // Step 2 : Connect with server

    memset(&ServerAddr, 0, sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = INADDR_ANY;
    ServerAddr.sin_port = htons(iPort);

    // 127.0.0.1      -> Binary form
    inet_pton(AF_INET, "127.0.0.1", &ServerAddr.sin_addr);

    iRet = connect(iServerSocketFD, (struct sockaddr *) &ServerAddr, sizeof(ServerAddr));

    if (iRet == -1)
    {
        printf("Unable to connect with server\n");
        close(iServerSocketFD);
        return -1;
    }

    printf("Client successfully connected with Server\n");

    // Step 3 : Read data from Server
    iRet = read(iServerSocketFD, chBuffer, sizeof(chBuffer) - 1);

    if (iRet <= 0)
    {
        printf("Unable to read the data from Server\n");
        close(iServerSocketFD);      
        return -1;
    }

    printf("Data from Sever : %s\n", chBuffer);

    // Step 4 : Close all resources

    close(iServerSocketFD);

    printf("Terminating the Client Application\n");

    return 0;
}

