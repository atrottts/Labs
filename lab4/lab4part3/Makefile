# Makefile for Lab 4 Part 3. Do not edit.
#   make           build lab4part3 from main.c, readings.c and stats.c
#   make original  build the original one-file program, for comparison
#   make clean     delete everything make built

CC     = gcc
CFLAGS = -Wall -Wextra -g

# Link: join the three object files into one program.
lab4part3: main.o readings.o stats.o
	$(CC) main.o readings.o stats.o -o lab4part3

# Compile: each .c becomes a .o. Each line lists what the .o depends on.
main.o: main.c readings.h stats.h
	$(CC) $(CFLAGS) -c main.c

readings.o: readings.c readings.h
	$(CC) $(CFLAGS) -c readings.c

stats.o: stats.c stats.h
	$(CC) $(CFLAGS) -c stats.c

original: original.c
	$(CC) $(CFLAGS) original.c -o original

clean:
	rm -f *.o lab4part3 original
