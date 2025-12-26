#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(void)
{
    // char arr[50] = {'\0'};
    
    char arr[50];

    memset(arr, '\0', sizeof(arr));

    getcwd(arr, sizeof(arr));

    printf("Current directory name : %s\n", arr);

    return 0;
}

