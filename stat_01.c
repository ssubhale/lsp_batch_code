#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(void)
{
    int iRet = 0;
    struct stat sObj;

    stat("demo.txt", &sObj);

    if (iRet == 0)
    {
        printf("Stat works successfully\n");
    }
    else
    {
        printf("There is issue in state\n");
    }

    return 0;
}
