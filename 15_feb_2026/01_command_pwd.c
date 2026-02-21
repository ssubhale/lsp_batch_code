#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//  ./pwdx
//  argv[0]
//  argc = 1

/*
    Call the system call getcwd()
    Print the result of getcwd()
*/


int main(int argc, char * argv[])
{
    char chBuffer[1024] = {'\0'};
    
    getcwd(chBuffer, sizeof(chBuffer));

    printf("%s\n", chBuffer);

    return 0;
}

