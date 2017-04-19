// Função que converte números romanos para números inteiros.

/**

  \file
  \brief Arquivo que contém a função para converter números romanos
  em número inteiros, bem como as funções auxiliares neste processo.

*/

#include "roman_number_conversion.h"

/** Função que converte números romanos.

    \param roman_number recebe um vetor de caracteres.
    \return A função retorna o valor de roman_number caso o parâmetro passado
    seja um argumento válido e -1 caso o argumento passado seja inválido.

    */

int RomanNumberConversion (char *roman_number) {

  char current_char, last_char = '\0', past_characters[30] = "";
  unsigned int iterator, last_char_count;
  int auxiliary_value, sum = 0;

  // A função não aceita argumentos com mais de 30 caracteres.

  if (strlen(roman_number) > 30)
    return -1;

  for (iterator = 0; iterator < strlen(roman_number); iterator++) {

    // Os caracteres são processados em caixa alta, evitando problemas.

    current_char = toupper(roman_number[iterator]);

    if(!ValidPrecedences(past_characters, current_char))
      return -1;

    // Armazena-se o caractere atual.

    past_characters[iterator] = current_char;

    auxiliary_value = CharacterValue(current_char);

    // Se o caractere não existir na numeração romana, a função
    // CharacterValue retorna -1.

    if(auxiliary_value == -1)
      return -1;

    else
      sum += auxiliary_value;

    if (current_char != last_char) {

      // Condicional para tratar de casos de subtração.
      // Note que o valor é subtraído duas vezes, pois ele havia sido somado
      // anteriormente.

      if (SubtractionPrecedence(last_char, current_char))
        sum -= (2 * CharacterValue(last_char));

      last_char = current_char;
      last_char_count = 1;

    }

    else {

      if (last_char_count != 3)
        last_char_count++;

      // Condicional para tratar de repetições excessivas de um caractere
      // gerando um argumento inválido.

      else
        return -1;

    }

  }

  return sum;

}

/** Função auxiliar para verificar se um dado caractere pode ser repetido na
    numeração romana.

    \param current_char recebe um caractere.
    \return A função retorna 1 caso current_char possa ser repetido e -1 caso
    não possa ser repetido.

     */

int CanBeRepeated (char current_char) {

  int char_value = CharacterValue(current_char);

  // Para que o caractere possa ser repetido, seu valor deve ser uma potência
  // de 10 exata.

  while (char_value >= 10)
    char_value = char_value/10;

  if (char_value == 1)
    return 1;

  else
    return 0;

}

/** Função auxiliar para retornar o valor de um dado caractere na numeração
    romana.

    \param current_char recebe um caractere.
    \return A função retorna o número inteiro equivalente a current_char caso
    este seja um caractere presente na numeração romana e -1 caso contrário.
    */

int CharacterValue (char current_char) {

  switch (current_char) {

    case 'I':
      return 1;

    case 'V':
      return 5;

    case 'X':
      return 10;

    case 'L':
      return 50;

    case 'C':
      return 100;

    case 'D':
      return 500;

    case 'M':
      return 1000;

    default:
      return -1;

  }

}

/** Função auxiliar para verificar se um dado par de caracteres constitui um caso
    em que o primeiro deve ser subtraido (ao invés de somado) ao valor total.

    \param precedent_char recebe um caractere.
    \param current_char recebe um caractere.
    \return A função retorna 1 caso precedent_char e current_char constituam uma
    precedência de subtração e -1 caso contrário.
     */

int SubtractionPrecedence (char precedent_char, char current_char) {

  // Para que a precedência de subtração ocorra, a razão entre o caractere
  // atual e o caractere que o precede deve ser 5 ou 10.

  if (CharacterValue(current_char)/CharacterValue(precedent_char) == 5 ||
  CharacterValue(current_char)/CharacterValue(precedent_char) == 10)
    return 1;

  else
    return 0;

}

/** Função auxiliar para verificar se os caracteres anteriores em conjunto com o
    caractere não constiuem um argumento inválido na numeração romana.

    \param past_characters recebe um vetor de caracteres.
    \param current_char recebe um caractere.
    \return A função retorna 1 caso current_char possa ser precedido por
    past_characters e -1 caso contrário.

    */

int ValidPrecedences (char *past_characters, char current_char) {

  unsigned int iterator;

  // O primeiro caractere sempre é aceito.

  if (strlen(past_characters) == 0)
    return 1;

  // Laço verifica todos os caracteres anteriores ao atual EXCETO o último.
  // Essa implementação é justificada devido à precedência de subtração,
  // uma excessão às regras que só ocorre entre caracteres sequenciais
  // (Ou seja, o último caracter anterior e o atual).

  for (iterator = 0; iterator < (strlen(past_characters) - 1); iterator++) {

    if (CharacterValue(past_characters[iterator]) < CharacterValue(current_char))
      return 0;

    else {

      if (CharacterValue(past_characters[iterator]) == CharacterValue(current_char)) {

        if (!CanBeRepeated(current_char))
          return 0;

        // Condicional especial para tratar de casos em que um caractere
        // é subtraído e depois tenta-se adicioná-lo ao número.
        // (Algo que não pode acontecer).

        if (SubtractionPrecedence(past_characters[iterator], past_characters[iterator + 1]) &&
        !SubtractionPrecedence(past_characters[(strlen(past_characters) - 1)], current_char))
          return 0;

      }

    }

  }

  // Condicionais para tratar exclusivamente do último caractere.

  // Condicional que trata do caso de subtração.

  if (SubtractionPrecedence(past_characters[iterator], current_char))
    return 1;

  else if (CharacterValue(past_characters[iterator]) > CharacterValue(current_char))
    return 1;

  else if (CharacterValue(past_characters[iterator]) == CharacterValue(current_char)) {

    if (CanBeRepeated(current_char))
      return 1;

    else
      return 0;

  }

  else
    return 0;

}
