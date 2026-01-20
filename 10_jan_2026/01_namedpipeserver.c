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
    
    if (iRet == 0)
    {
        printf("Named pipe gets successfully created\n");
    }

    return 0;
}

