# Roman numeral converter C library

Biblioteca de funções da linguagem C que permite a conversão de números romanos
para números inteiros de 1 a 3000. Trabalho da disciplina de Métodos de
programação 2017/1 da Universidade de Brasília.

#### Modo de uso

1. Copie o arquivo roman_number_conversion.h para a sua pasta de includes.

2. Copie o arquivo roman_number_conversion.c para sua pasta de código fonte.

3. Inclua esses arquivos no seu makefile, caso necessário.

4. Coloque a seguinte linha de código ao seu arquivo
 de cabeçalho:

```
 include "roman_number_conversion.h"
```

5. Chame a função RomanNumberConversion() no seu código.

#### Documentação da biblioteca

A documentação da biblioteca pode ser obtida através do programa doxygen. Basta ter o doxygen instalado e executar o seguinte comando na pasta do doxygen:

```
doxygen Doxyfile
```

#### Testes realizados

A biblioteca desse repositório foi testada tanto pelo módulo de testes test_environment.c. Para gerar o executável com os testes, execute o seguinte comando:

```
make
```

Isso gerará um arquivo executável com os testes realizados.

Após executar esse arquivo, os arquivos objeto e o arquivo executável gerados podem ser removidos com o seguinte comando:

```
make clean
```

Além disso, a extensão do arquivo executado de testes foi confirmada com a utilização do programa gcov. Os arquivos relacionados a esse programa podem ser encontrados na pasta src/gcov.
