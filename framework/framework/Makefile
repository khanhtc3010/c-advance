CC = gcc
CFLAGS = -g -std=c99

all: main

main: main.o
	$(CC) main.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -rf *.o *~ main