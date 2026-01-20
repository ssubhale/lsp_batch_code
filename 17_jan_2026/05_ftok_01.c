#include <stdio.h>
#include <sys/ipc.h>


int main(void)
{
    key_t iKey;
    
    iKey = ftok("./lsp.txt", 's');

    printf("Key is : %d\n", iKey);

    return 0;
}

