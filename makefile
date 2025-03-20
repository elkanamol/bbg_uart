CC = gcc
CFLAGS = -Wall -O2

all: send receive

uart.o: uart.c
	$(CC) $(CFLAGS) -c uart.c 

send: send.c uart.o
	$(CC) $(CFLAGS) send.c uart.o -o send

receive: send.c uart.o
	$(CC) $(CFLAGS) receive.c uart.o -o receive

clean:
	rm -f send receive uart.o