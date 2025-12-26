#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(void)
{
    int iRet = 0;

    iRet = unlink("demo.txt");

    if (iRet == 0)
    {
        printf("Unlink is successfull\n");
    }

    return 0;
}
