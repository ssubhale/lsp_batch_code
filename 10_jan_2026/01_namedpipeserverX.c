// Named pipe server

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(void)
{
    int fd = 0;
    int iRet = 0;

    iRet = mkfifo("/tmp/marvellous", 0666);
    printf("%d\n", iRet);
    
    if (iRet == -1)
    {
        printf("Unable to create named pipe\n");
        return -1;
    }

    fd = open("/tmp/marvellous", O_WRONLY);

    if (fd == -1)
    {
        printf("Unable to open named pipe\n");
        return -1;
    }

    iRet = write(fd, "Jay Ganesh", 10);
    printf("Data gets successfully written into the pipe by the server\n");

    close(fd);

    unlink("/tmp/marvellous");


    return 0;
}

