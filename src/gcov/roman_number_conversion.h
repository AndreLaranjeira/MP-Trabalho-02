// Função que converte números romanos para números inteiros - cabeçalho.

// O arquivo contém os cabeçalhos da função que converte números
// romanos para números inteiros e das funções auxiliares a ela.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int RomanNumberConversion (char *);
int CanBeRepeated (char);
int CharacterValue (char);
int SubtractionPrecedence (char, char);
int ValidPrecedences (char *, char);
