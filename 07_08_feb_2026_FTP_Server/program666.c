// Server Code

#include <stdio.h>
#include <sys/socket.h>


//Check all system calls and its all parameters on the man page 7 and 

int main(void)
{
    int iServerSocket = 0;

    iServerSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (iServerSocket < 0)
    {
        printf("Unable to create the socket\n");
        return -1;
    }

    printf("Socket gets created successfully with fd %d\n", iServerSocket);

    return 0;
}

