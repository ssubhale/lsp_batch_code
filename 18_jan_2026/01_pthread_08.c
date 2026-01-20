#include <stdio.h>
#include <pthread.h>


void * Demo(void *ptr)
{
    printf("Inside thread with value : \n");
    printf("%d\n", *(((int *)ptr + 0)));
    printf("%d\n", *(((int *)ptr + 1)));
    printf("%d\n", *(((int *)ptr + 2)));
    printf("%d\n", *(((int *)ptr + 3)));

    return NULL;
}


int main(void)
{
    pthread_t tID;
    int iRet = 0;
    int Arr[] = {11, 21, 51, 101};

    printf("Main thread started\n");

    iRet = pthread_create(
                            &tID,               // Thread ID
                            NULL,               // Thread Atributes
                            Demo,               // Thread Callback Function
                            Arr                 // Parameters for the callback function
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

