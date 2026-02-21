// Client Code

#include <stdio.h>              // printf, scanf
#include <stdlib.h>             // malloc, free
#include <string.h>             // memset, memcmp

#include <unistd.h>             // close, write, read
#include <fcntl.h>              // creat, unlink

#include <sys/socket.h>         // socket, bind, listen, accept, connect
#include <netinet/in.h>         // sockaddr_in, htons


int main(void)
{
    int iServerSocketFD = 0;

    // Step 1 : Create TCP socket

    iServerSocketFD = socket(AF_INET, SOCK_STREAM, 0);

    if (iServerSocketFD < 0)
    {
        printf("Unable to create the server socke\n");
        return -1;
    }

    printf("Socket is created successfully with fd : %d\n", iServerSocketFD);

    return 0;
}

