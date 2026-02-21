#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>


//  ./unamex
//  argv[0]
//  argc = 1

/*
    Call the system call uname()
    Print the information from utsname structure
*/


int main(int argc, char * argv[])
{
    struct utsname sObj;
    int iRet = 0;

    iRet = uname(&sObj);

    if (iRet < 0)
    {
        printf("Error : Unable to fetch the system information\n");
        return -1;
    }

    printf("Operating system name : %s\n", sObj.sysname);
    printf("Node name : %s\n", sObj.nodename);
    printf("Operating system version : %s\n", sObj.release);

    return 0;
}

