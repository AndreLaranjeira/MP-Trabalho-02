// Função que converte números romanos para números inteiros - cabeçalho.

/**

  \file
  \brief Arquivo que contém os cabeçalhos da função para converter números
  romanos em número inteiros, bem como das funções auxiliares neste processo.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int RomanNumberConversion (char *);
int CanBeRepeated (char);
int CharacterValue (char);
int SubtractionPrecedence (char, char);
int ValidPrecedences (char *, char);
