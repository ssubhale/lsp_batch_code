
// Server Application

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  
// Command Line Argument Application
// 1st argument : Port Number       // argv[1]
// ./server 8080
// argv[0]  argv[1]
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(int argc, char * argv[])
{
    int iServerSocket = 0;
    int iClientSocket = 0;
    int iPort = 0;
    int iReturn = 0;
    
    struct sockaddr_in ServerAddr;
    struct sockaddr_in ClientAddr;

    socklen_t iAddrLen = sizeof(ClientAddr);

    if ((argc < 2) || (argc > 2))
    {
        printf("Unable to proceed as invalid number of argument\n");
        printf("Please provide port number\n");
        return -1;
    }

    // Port number of server

    iPort = atoi(argv[1]);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Step 1 : Create TCP Socket
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    iServerSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (iServerSocket < 0)
    {
        printf("Unable to create server socket\n");
        return 0;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Step 2 : Bind Socket to IP and Port
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    memset(&ServerAddr, 0, sizeof(ServerAddr));

    // Initialize the structure
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(iPort);
    ServerAddr.sin_addr.s_addr = INADDR_ANY;

    iReturn = bind(iServerSocket, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));

    if (iReturn == -1)
    {
        printf("Unable to bind");
        close(iServerSocket);
        return -1;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Step 3 : Listen for Client Connections
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    iReturn = listen(iServerSocket, 11);

    if (iReturn == -1)
    {
        printf("Server unable to listen the requests\n");
        close(iServerSocket);
        return -1;
    }

    printf("Server is running on port %d\n", iPort);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Loop which accepts client requests continiously
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Loop to accept multiple client requests
    while (1)
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Step 4 : Accept the client requests
        ////////////////////////////////////////////////////////////////////////////////////////////////////////

        memset(&ClientAddr, 0, sizeof(ClientAddr));

        printf("Server is waiting for client requests...\n");

        iClientSocket = accept(iServerSocket, (struct sockaddr *)&ClientAddr, &iAddrLen);

        if (iClientSocket < 0)
        {
            printf("Unbale to client requests\n");
            close(iClientSocket);
            continue;           // Used for while
        }

        printf("Client gets connected : %s\n", inet_ntoa(ClientAddr.sin_addr));

    }   // End of while

    // End of main
    return 0;
}

