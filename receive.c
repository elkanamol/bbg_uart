#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "uart.h"

int main(void)
{
    int fd = init_uart("/dev/ttyS1");
    char buff[255];
    int n;

    while(1)
    {
        n = read(fd, buff, sizeof(buff) - 1);
        if (n > 0 )
        {
            buff[n] = '\0';
            printf("%s \n", buff);
        }
        sleep(1);
    }
    close(fd);
    return 0;
}