#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

#include "uart.h"

int main(void)
{
    int fd = init_uart("/dev/ttyS1", B115200);
    if (fd < 0)
    {
        fprintf(stderr, "Failed to initialize UART (error code: %d)\n", fd);
        return EXIT_FAILURE;
    }

    while (1)
    {
        if (write(fd, "Hello world\n", sizeof("Hello world")) < 0)
        {
            perror("Error writing to serial port");
        }
        sleep(1);
    }

    close(fd);
    return 0;
}
