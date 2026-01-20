#include <stdio.h>
#include <unistd.h>



int main(void)
{
    printf("Process is created\n");

    _exit(11);
}

