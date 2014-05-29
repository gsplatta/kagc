IDIR	= ~/include
CC	=
CFLAGS	= -Wall -c
LFLAGS	= -Wall

ODIR	= ~/obj
LDIR	= ~/lib
BDIR	= ~/bin

LIBS	=

_DEPS	=
DEPS	=

_OBJ	=
OBJ	=

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
