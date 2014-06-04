EXE = kagc
CC = gcc
CFLAGS	= -std=c11 `pkg-config gtk+-3.0 --cflags` -o $(EXE)
LDFLAGS	= `pkg-config gtk+-3.0 --libs`

help:
	@ echo "The following make targets are available: "
	@ echo "make help:  print this message."
	@ echo "make gui:   install the GUI; only for testing purposes."
	@ echo "make clean: remove all object files."

all:
	
install-exec:

install-data:

gui: 
	$(CC) $(CFLAGS) main.c $(LDFLAGS)

docs: 

check:

clean: 
	rm -f *.o
