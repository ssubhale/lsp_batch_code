#include <stdio.h>
#include <pthread.h>


void * Demo(void *ptr)
{
    int iSum = 0;

    printf("Inside thread\n");
    
    iSum = (*((int *)ptr + 0)) + (*((int *)ptr + 1)) + (*((int *)ptr + 2)) + (*((int *)ptr + 3));

    pthread_exit((int *)iSum);
}


int main(void)
{
    pthread_t tID;
    int iRet = 0;
    int iValue = 0;
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

    pthread_join(tID, &iValue);

    printf("Summation is %d\n", iValue);

    printf("End of main thread\n");

    return 0;
}

