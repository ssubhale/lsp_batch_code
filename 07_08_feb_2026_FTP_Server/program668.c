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
    int iServerSocket = 0;
    int iRet = 0;
    int iPort = 8080;

    struct sockaddr_in ServerAddr;

    //Step 1 : Create TCP socket
    iServerSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (iServerSocket < 0)
    {
        printf("Unable to create the socket\n");
        return -1;
    }

    printf("Socket gets created successfully with fd %d\n", iServerSocket);

    // Step 2 : Attach the socket to IP address & port number

    // Set memory with zero
    memset(&ServerAddr, 0, sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = INADDR_ANY;
    ServerAddr.sin_port = htons(iPort);

    iRet = bind(iServerSocket, (struct sockaddr *) &ServerAddr, sizeof(ServerAddr));

    if (iRet == -1)
    {
        printf("Unable to bind the socket\n");
        close(iServerSocket);
        return -1;
    }

    printf("Bind operation with socket is successfull\n");

    // Step 3 : mark the socket as active socket

    iRet = listen(iServerSocket, 11);               // Server is able to listen the 11 max requests at a time 

    if (iRet == -1)
    {
        printf("Unable to convert socket in listen mode\n");
        close(iServerSocket);
        return -1;
    }

    printf("Server is live at port %d\n", iPort);
    
    return 0;
}

