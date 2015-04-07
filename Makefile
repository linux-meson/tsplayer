VERSION = 0.01
CC      ?= gcc
CFLAGS  = -Wall -g -DVERSION=\"$(VERSION)\" `pkg-config --cflags libamcodec`
LDFLAGS = `pkg-config --libs libamcodec --cflags`

OBJ = tsplayer.o

prog: $(OBJ)
	$(CC) $(CFLAGS) -o prog $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
