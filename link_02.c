#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(void)
{
    int iRet = 0;

    iRet = link("./demo.txt", "./test_applications/demo.txt");

    if (iRet == 0)
    {
        printf("Link is successfull\n");
    }

    return 0;
}
