#include <stdio.h>
#include <unistd.h>


int main(void)
{
    void *ptr = NULL;

    ptr = sbrk(100);        // ptr = malloc(25 * sizeof(int));

    printf("Current brak value : %p\n", ptr);


    ptr = sbrk(0);
    
    printf("Current brak value : %p\n", ptr);


    ptr = sbrk(-100);       // free(ptr);
    
    printf("Current brak value : %p\n", ptr);


    ptr = sbrk(0);
    
    printf("Current brak value : %p\n", ptr);

    return 0;
}

