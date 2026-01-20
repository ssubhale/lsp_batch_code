#include <stdio.h>
#include <pthread.h>


void * Demo(void *ptr)
{
    printf("Inside thread\n");

    return NULL;
}


int main(void)
{
    pthread_t tID;
    int iRet = 0;

    printf("Main thread started\n");

    iRet = pthread_create(
                            &tID,               // Thread ID
                            NULL,               // Thread Atributes
                            Demo,               // Thread Callback Function
                            NULL                // Parameters for the callback function
                        );

    if (iRet == 0)
    {
        printf("Thread gets created successfully with tID : %lu\n", (unsigned long) tID);
    }

    // wait
    pthread_join(tID, NULL);

    printf("End of main thread\n");

    return 0;
}

