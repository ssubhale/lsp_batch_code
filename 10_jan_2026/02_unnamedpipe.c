// Un-Named pipe

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(void)
{
    int pipefd[2] = {0, 0};
    int iRet = 0;

    iRet = pipe(pipefd);

    if (iRet == 0)
    {
        printf("Un-Named pipe gets created\n");
    }
    

    return 0;
}

