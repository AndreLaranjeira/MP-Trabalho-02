IDIR = ../include
CC = g++
CFLAGS = -Wall -ftest-coverage -fprofile-arcs -I $(IDIR)

ODIR = obj
LDIR = ../lib
GCOVDIR = gcov

LIBS = -lm -lgtest

_DEPS = roman_number_conversion.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = roman_number_conversion.o test_environment.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

romanmake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: my_gcov

mv_gcov:
	mv $(ODIR)/*.gcda $(GCOVDIR)
	mv $(ODIR)/*.gcno $(GCOVDIR)
	cp $(IDIR)/$(_DEPS) $(GCOVDIR)
	cp *.c $(GCOVDIR)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
