#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <errno.h>

#include "uart.h"

int init_uart(const char* port)
{
    int fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1)
    {
        perror("Error open serial port");
        return -1;
    }

    struct termios options;

    if (tcgetattr(fd, &options) < 0)
    {
        perror("Error getting current port settings");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // set baudrate
    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);

    // 8N1
    options.c_cflag = (options.c_cflag & ~CSIZE) | CS8;

    options.c_iflag = IGNBRK;

    options.c_oflag = 0;
    options.c_lflag = 0;
    
    options.c_cflag |= CLOCAL | CREAD;

    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 5;


    options.c_iflag &= ~(IXON | IXOFF | IXANY);

    options.c_cflag &= ~(PARENB |PARODD);

    if (tcsetattr(fd, TCSANOW ,&options) < 0)
    {
        perror("Error getting current port settings");
        close(fd);
        exit(EXIT_FAILURE);
    }

    tcflush(fd, TCIOFLUSH);
    return fd;
    
}
