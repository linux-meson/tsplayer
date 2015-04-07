VERSION  = 0.01
CC      ?= gcc
CFLAGS   = -Wall -g -DVERSION=\"$(VERSION)\" `pkg-config --cflags libamcodec`
LDFLAGS  = `pkg-config --libs libamcodec`

OBJ = main.o AmCodec.o IAmCodec.o

tsplayer: $(OBJ)
	$(CXX) $(CFLAGS) -o prog $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $<

all: tsplayer

clean:
	rm -f *.o $(OBJ)
