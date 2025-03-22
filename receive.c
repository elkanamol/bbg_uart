#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

#include "uart.h"

#define MAX_BUFFER_SIZE 255

int main(void)
{
    int fd = init_uart("/dev/ttyS1", B115200);
    if (fd < 0)
    {
        fprintf(stderr, "Failed to initialize UART (error code: %d)\n", fd);
        return EXIT_FAILURE;
    }

    char buff[MAX_BUFFER_SIZE];
    int n;

    while (1)
    {
        n = read(fd, buff, sizeof(buff) - 1);
        if (n > 0)
        {
            buff[n] = '\0';
            printf("%s\n", buff);
        }
        sleep(1);
    }

    close(fd);
    return 0;
}
