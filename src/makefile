IDIR = ../include
CC = g++
CFLAGS = -Wall -I $(IDIR)

ODIR = obj
LDIR = ../lib

LIBS = -lm -lgtest

_DEPS = RomanNumberConversion.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = RomanNumberConversion.o TestEnvironment.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

romanmake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
