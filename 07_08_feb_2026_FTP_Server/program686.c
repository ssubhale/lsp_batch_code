
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

void SendFileToClient(int, char *);


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
    __pid_t iPid = 0;

    char fileName[50];
    
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
        printf("Unable to bind\n");
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

        printf("\nServer is waiting for client requests...\n");

        iClientSocket = accept(iServerSocket, (struct sockaddr *)&ClientAddr, &iAddrLen);

        if (iClientSocket < 0)
        {
            printf("Unbale to client requests\n");
            close(iClientSocket);
            continue;           // Used for while
        }

        printf("Client gets connected : %s\n", inet_ntoa(ClientAddr.sin_addr));

        ////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Step 5 : Create new process to handle client request
        ////////////////////////////////////////////////////////////////////////////////////////////////////////

        iPid = fork();

        if (iPid < 0)
        {
            printf("Unable to create the new process for client request\n");
            close(iClientSocket);
            continue;;
        }

        // New process gets created for client
        if (iPid == 0)
        {
            printf("New process is created for client request\n");

            close(iServerSocket);

            iReturn = read(iClientSocket, fileName, sizeof(fileName));

            printf("Requested file by client : %s\n", fileName);

            SendFileToClient(iClientSocket, fileName);

            close(iClientSocket);
            printf("File transfer done & client disconnected\n");
            exit(0);

        }   // End of if (fork)
        else    // Parent process (Server)
        {
            close(iClientSocket);
        }   // End of else

    }   // End of while

    close(iServerSocket);

    // End of main
    return 0;
}



void SendFileToClient(int iClientSocket, char * fileName)
{
    int fd = 0;
    struct stat sObj;
    char chBuffer[1024];
    int bytesRead = 0;
    char chHeader[64] = {'\0'};

    fileName[strcspn(fileName, "\n")] = '\0';

    fd = open(fileName, O_RDONLY);
    printf("fd : %d\n", fd);

    printf("filename : %s\n", fileName);
    printf("strlen(filename) : %ld\n", strlen(fileName));

    if (fd < 0)
    {
        // Send error message to client
        write(iClientSocket, "ERR\n", 4);
        return;
    }

    stat(fileName, &sObj);

    if (stat(fileName, &sObj) == -1)
    {
        write(iClientSocket, "ERR\n", 4);
        close(fd);
        return;
    }

    // Header : "OK : 1700"
    snprintf(chHeader, sizeof(chHeader), "OK : %ld\n", (long)sObj.st_size);


    // Write header to client

    write(iClientSocket, chHeader, strlen(chHeader));

    // Send actual file contents
    while ((bytesRead = read(fd, chBuffer, sizeof(chBuffer))) > 0)
    {
        // Send the data to client 
        write(iClientSocket, chBuffer, bytesRead);
    }

    close(fd);

}

