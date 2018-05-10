# Nome do executável do projeto.

EXE = Roman_Numeral_Tests.exe

# Nome do compilador, extensão dos arquivos source e dados de compilação (flags e bibliotecas).

CC = g++
EXT = c

CFLAGS = -Wall -g -I $(IDIR) -ftest-coverage -fprofile-arcs
# Flags do gtest: -ftest-coverage -fprofile-arcs

LIBS = -lm -lgtest -pthread
# Libs do gtest: -lgtest -pthread

# Caminhos até pastas importantes (arquivos .h, bibliotecas externas, arquivos .o, arquivos com testes e, opcionalmente, arquivos do gcov).

IDIR = include
LDIR = lib
ODIR = src/obj
SDIR = src
GCOVDIR = src/gcov

# Lista de dependências do projeto (arquivos .h).

_DEPS = roman_number_conversion.h

# Lista de arquivos intermediários de compilação gerados pelo projeto (arquivos .o).

_OBJ = roman_number_conversion.o test_environment.o

# Lista de arquivos fontes utilizados para compilação.

_SRC = roman_number_conversion.$(EXT) test_environment.$(EXT)

# Junção dos nomes de arquivos com seus respectivos caminhos.

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

# Atualização de arquivos que foram alterados.

$(ODIR)/%.o: $(SDIR)/%.$(EXT) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Compilação do executável do projeto.

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Lista de comandos adicionais do makefile.

.PHONY: clean
.PHONY: mv_gcov
.PHONY: structure
.PHONY: verify_tests

# Comando para limpar o executável do projeto e os arquivos .o.

clean:
	rm -f $(ODIR)/*.o *~ core $(TDIR)/*.gcda $(TDIR)/*.gcno $(TDIR)/*.o
	if [ -f $(EXE) ]; then rm $(EXE); fi

# Comando para mover os arquivos gerados pelo gcov para a pasta do gcov.

mv_gcov:
	cp $(DEPS) $(GCOVDIR)
	cp *.cpp $(GCOVDIR)
	if [ -f $(ODIR)/*.gcno ]; then mv $(ODIR)/*.gcno $(GCOVDIR); fi
	if [ -f $(TDIR)/*.gcno ]; then mv $(ODIR)/*.gcno $(GCOVDIR); fi
	if [ -f $(ODIR)/*.gcda ]; then mv $(ODIR)/*.gcda $(GCOVDIR); fi
	if [ -f $(TDIR)/*.gcda ]; then mv $(ODIR)/*.gcda $(GCOVDIR); fi

# Comando para gerar a estrutura inicial do projeto.

structure:

	# Criação das pastas do projeto.

	mkdir include
	mkdir lib
	mkdir src
	mkdir src/obj
	mkdir src/gcov

	# Movimentação dos arquivos existentes para suas respectivas pastas.

	if [ -f *.h ]; then mv *.h $(IDIR); fi
	if [ -f *$(EXT) ]; then mv *$(EXT) $(SDIR); fi
	if [ -f *.o ]; then mv *.o $(ODIR); fi
	if [ -f *.gcno ]; then mv *.gcno $(GCOVDIR); fi
	if [ -f *.o ]; then mv *.gcda $(GCOVDIR); fi

# Comando para verificar os testes utilizando o cppcheck e o valgrind.

verify_tests:
	cppcheck %$(EXT) ./$(EXE) --enable=all
	valgrind --leak-check=full ./$(EXE)
