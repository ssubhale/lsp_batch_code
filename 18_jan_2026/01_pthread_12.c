#include <stdio.h>
#include <pthread.h>


void * Demo(void *ptr)
{
    printf("Inside Demo thread\n");

    return NULL;
}


void * Hello(void *ptr)
{
    printf("Inside Hello thread\n");

    return NULL;
}


int main(void)
{
    pthread_t tID1, tID2;
    int iRet = 0;

    printf("Main thread started\n");

    iRet = pthread_create(
                            &tID1,               // Thread ID
                            NULL,               // Thread Atributes
                            Demo,               // Thread Callback Function
                            NULL                // Parameters for the callback function
                        );

    if (iRet == 0)
    {
        printf("Thread gets created successfully with tID1 : %lu\n", (unsigned long) tID1);
    }

    iRet = pthread_create(
                            &tID2,               // Thread ID
                            NULL,               // Thread Atributes
                            Hello,               // Thread Callback Function
                            NULL                // Parameters for the callback function
                        );

    if (iRet == 0)
    {
        printf("Thread gets created successfully with tID2 : %lu\n", (unsigned long) tID2);
    }


    // wait
    pthread_join(tID1, NULL);
    pthread_join(tID2, NULL);

    printf("End of main thread\n");

    return 0;
}

