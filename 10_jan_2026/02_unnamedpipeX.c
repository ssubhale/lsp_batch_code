// Un-Named pipe

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(void)
{
    int pipefd[2] = {0, 0};
    int iRet = 0;
    char Arr[100] = {'\0'};

    iRet = pipe(pipefd);

    if (iRet == 0)
    {
        printf("Un-Named pipe gets created\n");
    }

    write(pipefd[1], "Jay Ganesh", 10);

    read(pipefd[0], Arr, 10);

    printf("Data from pipe is : %s\n", Arr);
    

    return 0;
}

