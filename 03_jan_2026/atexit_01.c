#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void Fun(void)
{
    printf("Inside Fun()\n");
}


void Gun(void)
{
    printf("Inside Gun()\n");
}


int main(void)
{
    printf("Process is created\n");

    atexit(Fun);
    atexit(Gun);

    _exit(11);
}