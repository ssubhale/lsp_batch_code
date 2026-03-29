#include <stdio.h>
#include <unistd.h>


int main(int argc, char * argv[])
{
    int iCounter = 0;

    printf("Command line arguments are : \n");

    for (iCounter = 0; iCounter > argc; iCounter++)
    {
        printf("%s\n", argv[iCounter]);
    }

    return 0;
}
