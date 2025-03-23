# UART Communication Demo for Embedded Linux

This repository contains a simple demonstration of UART communication using the termios.h library on Linux systems. The code is specifically tested on BeagleBone Green but should work on other Linux-based embedded systems with minor modifications.

## Overview

This project demonstrates how to:
- Configure and initialize a UART port using the termios.h library
- Send data through a UART port
- Receive data from a UART port
- Create a loopback test using physical pins
- Handle errors gracefully in serial communication

The code provides a practical example of serial communication fundamentals that are essential for embedded systems development.

## Components

- **uart.h/uart.c**: Core UART initialization and configuration functions with configurable baudrate
- **send.c**: Application that sends "Hello world" messages over UART
- **receive.c**: Application that receives and displays messages from UART
- **makefile**: Build script to compile the applications

## Hardware Setup for Loopback Testing

To test the UART communication without additional hardware, you can create a loopback by connecting the TX and RX pins on your BeagleBone Green:

1. Locate pin #24 (UART1_TXD) and pin #26 (UART1_RXD) on your BeagleBone Green
2. Connect these pins using a jumper wire to create a loopback circuit
3. This will route any transmitted data back to the receiver

![BeagleBone Green Pinout](https://files.seeedstudio.com/wiki/BeagleBone_Green/images/PINMAP_UART.png)

### Detailed Pin Information:
- Pin #24: UART1_TXD (Transmit Data)
- Pin #26: UART1_RXD (Receive Data)

When these pins are connected, any data sent from the UART transmitter will be immediately received by the UART receiver, allowing you to test the communication without additional hardware.

## Building and Running

To build both applications:
```bash
make
```

To run the sender:
```bash
./send
```

To run the receiver (in a separate terminal):
```bash
./receive
```

To clean up build artifacts:
```bash
make clean
```

## Understanding termios.h

The termios.h library is used to control asynchronous communications ports in Unix-like systems. This demo shows how to:

1. Open a serial port using `open()`
2. Configure port settings with `tcgetattr()` and `tcsetattr()`
3. Set baud rate using `cfsetispeed()` and `cfsetospeed()`
4. Configure data bits, stop bits, and parity
5. Handle flow control settings
6. Set read timeouts with VMIN and VTIME parameters

## Error Handling

The code demonstrates proper error handling for UART operations:
- Checking for NULL parameters
- Handling file open failures
- Managing termios configuration errors
- Returning specific error codes for different failure scenarios
- Proper resource cleanup on error

## Notes

- The code uses "/dev/ttyS1" as the default serial port. You may need to adjust this based on your system configuration.
- The UART is configured for 115200 baud by default, but the code supports configurable baudrates.
- Both applications run in an infinite loop. Use Ctrl+C to terminate them.

## License

This project is licensed under the MIT License - see below for details:

```
MIT License

Copyright (c) 2023 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
