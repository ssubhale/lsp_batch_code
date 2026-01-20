#include <stdio.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <string.h>

#define MAXTEXT 512


struct MarvellousMessage
{
    long int msg_type;
    char data[MAXTEXT];

};


int main(void)
{
    int id = 0;
    key_t iKey;
    struct MarvellousMessage mObj;
    int iRet = 0;

    iKey = ftok(".", 'a');

    id = msgget(iKey, 0666 | IPC_CREAT);

    if (id == -1)
    {
        printf("Unable to allocate the message queue\n");
        return -1;
    }

    // iRet = msgrcv(id, (void *) &mObj, MAXTEXT, 11, 0);           // this will wait for message
    iRet = msgrcv(id, (void *) &mObj, MAXTEXT, 11, IPC_NOWAIT);     // this will not wait for message

    if (iRet > 0)
    {
        printf("Data received from message is : %s\n", mObj.data);
    }

    return 0;
}

