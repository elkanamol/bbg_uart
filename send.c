#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "uart.h"

int main(void)
{
    int fd = init_uart("/dev/ttyS1");
    while(1)
    {
        if(write(fd,"Hello world\n",sizeof("Hello world") ) < 0)
        {
            perror("Error writing to serial port");
        }
            sleep(1);
        }
    close(fd);
    return 0;
}