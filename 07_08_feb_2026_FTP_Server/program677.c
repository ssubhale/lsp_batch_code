#include <stdio.h>


int main(int argc, char * argv[])
{
    printf("No of command line arguments are : %d\n", argc);

    int iCounter = 0;

    for (iCounter; iCounter < argc; iCounter++)
    {
        printf("%s\n", argv[iCounter]);
    }

    return 0;
}

