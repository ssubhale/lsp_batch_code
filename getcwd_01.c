#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(void)
{
    printf("Current directory name : %s\n", getcwd());      // Error

    return 0;
}

