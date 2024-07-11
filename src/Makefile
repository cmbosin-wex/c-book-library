
CC = gcc
SRC = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRC))
INCLUDEDIR = ../include

CFLAGS = -std=c99 -Wall -Wextra -Werror \
		 -pedantic \
		 -Wno-unused-parameter  \
		 -g -I$(INCLUDEDIR)

LDFLAGS = -lm



book-library: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f book-library $(OBJS) 