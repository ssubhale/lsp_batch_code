
// Client Application

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
// 1st argument : IP address
// 2nd argument : Port number
// 3rd argument : Target file
// 4th argument : New file name
// 
// .client  127.0.0.1  8080     Demo.txt  A.txt
// argv[0]  argv[1]    argv[2]  argv[3]   argv[4]
// 
// argc = 5
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(int argc, char * argv[])
{
    int iPort = 0;                      // argv[2]
    int iSock = 0;
    int iReturn = 0;
    char * chIPAddr = NULL;             // argv[1]
    char * inFilename = NULL;           // argv[3]
    char * outFilename = NULL;          // argv[4]

    struct sockaddr_in ServerAddr;

    if ((argc < 5) || (argc > 5))
    {
        printf("Unable to proceed as invalid number of argument\n");
        printf("Please provide below arguments\n");
        printf("1st argument : IP address\n2nd argument : Port number\n3rd argument : Target file\n4th argument : New file name\n");
        return -1;
    }

    // Store the command line arguments into the variables

    chIPAddr = argv[1];
    iPort = atoi(argv[2]);
    inFilename = argv[3];
    outFilename = argv[4];

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Step 1 : Create TCP Socket
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    iSock = socket(AF_INET, SOCK_STREAM, 0);

    if (iSock < 0)
    {
        printf("Unable to create the client socket\n");
        return -1;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Step 2 : Connect with server
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    memset(&ServerAddr, 0, sizeof(&ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(iPort);

    // Convert the IP address binary format

    inet_pton(AF_INET, chIPAddr, &ServerAddr.sin_addr);

    iReturn = connect(iSock, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));

    if (iReturn == -1)
    {
        printf("Unable to connect with server\n");
        close(iSock);
        return -1;
    }

    // Sending filename to server from client
    write(iSock, inFilename, strlen(inFilename));

    printf("Success\n");

    // End of main
    return 0;
}

