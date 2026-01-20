#include <stdio.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <sys/ipc.h>


int main(void)
{
    int id = 0;
    key_t iKey;

    iKey = ftok(".", 'a');

    id = msgget(iKey, 0666);

    if (id == -1)
    {
        printf("Unable to allocate the message queue\n");
        return -1;
    }


    return 0;
}

