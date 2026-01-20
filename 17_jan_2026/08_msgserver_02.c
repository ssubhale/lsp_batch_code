#include <stdio.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <string.h>
#include <errno.h>

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
    if (iKey == -1)
    {
        printf("Failed to generate key\n");
        return -1;
    }

    id = msgget(iKey, 0666 | IPC_CREAT);
    if (id == -1)
    {
        printf("Unable to allocate the message queue\n");
        return -1;
    }

    mObj.msg_type = 11;
    strcpy(mObj.data, "Jay Ganesh...!");

    iRet = msgsnd(id, &mObj, MAXTEXT, 0);
    if (iRet == -1)
    {
        printf("Failed to send message\n");
        return -1;
    }

    printf("Message sent successfully\n");

    return 0;
}
