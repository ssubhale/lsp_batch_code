#include <stdio.h>
// System pipe reader


int main(void)
{
    char arr[100] = {'\0'};

    fgets(arr, sizeof(arr), stdin);

    printf("Data received : %s\n", arr);

    return 0;
}

