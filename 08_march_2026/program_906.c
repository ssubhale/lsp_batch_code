#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// ./myexe.exe 11 12

int main(int argc, char * argv[])
{
    int iAns = 0;

    if (argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    iAns = atoi(argv[1]) + atoi(argv[2]);

    printf("Addition is : %d\n", iAns);

    return 0;
}
