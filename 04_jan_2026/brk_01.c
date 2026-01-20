#include <stdio.h>
#include <unistd.h>



int main(void)
{
    void *ptr = NULL;

    // brk break
    // sbrk system break

    ptr = sbrk(0);
    printf("Current brak value : %p\n", ptr);

    // *(char *)ptr = 'A';         // This is not good coding practice

    return 0;
}

