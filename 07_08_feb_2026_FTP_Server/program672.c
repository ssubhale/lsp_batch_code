// Server Code

#include <stdio.h>              // printf, scanf
#include <stdlib.h>             // malloc, free
#include <string.h>             // memset, memcmp

#include <unistd.h>             // close, write, read
#include <fcntl.h>              // creat, unlink

#include <sys/socket.h>         // socket, bind, listen, accept, connect
#include <netinet/in.h>         // sockaddr_in, htons


/*
struct sockaddr_in
{
    sa_family_t sa_family;
    char sa_data[14];
};
*/


int main(void)
{
    int iServerSocketFD = 0;
    int iRet = 0;
    int iPort = 8080;
    int iClientSoketFD = 0;
    struct sockaddr_in ServerAddr;
    char * szMessage = "Jay Ganesh from Server\n";

    //Step 1 : Create TCP socket
    iServerSocketFD = socket(AF_INET, SOCK_STREAM, 0);

    if (iServerSocketFD < 0)
    {
        printf("Unable to create the socket\n");
        return -1;
    }

    printf("Socket gets created successfully with fd %d\n", iServerSocketFD);

    // Step 2 : Attach the socket to IP address & port number

    // Set memory with zero
    memset(&ServerAddr, 0, sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = INADDR_ANY;
    ServerAddr.sin_port = htons(iPort);

    iRet = bind(iServerSocketFD, (struct sockaddr *) &ServerAddr, sizeof(ServerAddr));

    if (iRet == -1)
    {
        printf("Unable to bind the socket\n");
        close(iServerSocketFD);
        return -1;
    }

    printf("Bind operation with socket is successfull\n");

    // Step 3 : mark the socket as active socket

    iRet = listen(iServerSocketFD, 11);               // Server is able to listen the 11 max requests at a time 

    if (iRet == -1)
    {
        printf("Unable to convert socket in listen mode\n");
        close(iServerSocketFD);
        return -1;
    }

    printf("Server is live at port %d\n", iPort);

    //Step 4 : Accept new socket request

    iClientSoketFD = accept(iServerSocketFD, NULL, NULL);

    if (iClientSoketFD == -1)
    {
        printf("Unable to aacept the request from client\n");
        close(iServerSocketFD);
        return -1;
    }

    printf("Request accepted by server \n");

    // Step 5 : Send message to client

    write(iClientSoketFD, szMessage, strlen(szMessage));

    // Step 6 : Close all resources

    close(iServerSocketFD);
    close(iClientSoketFD);

    printf("Terminating the Server Application\n");
    
    return 0;
}

