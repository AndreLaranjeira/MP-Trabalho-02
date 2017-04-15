// Função que converte números romanos para números inteiros.

#include "RomanNumberConversion.h"

// Função principal
int romanNumberConversion (char *roman) {

    char current, last = '0', pastCharacters[30] = "";
    unsigned int iterator, lastCount;
    int auxiliary, sum = 0;

    // A função não aceita argumentos com mais de 30 caracteres.
    if (strlen(roman) > 30)
        return -1;

    for (iterator = 0; iterator < strlen(roman); iterator++) {

        // Os caracteres são processados em caixa alta, evitando problemas.
        current = toupper(roman[iterator]);

        // Verifica-se se os caracteres anteriores não invalidam o argumento.
        if( !(validPrecedences(pastCharacters, current)) )
            return -1;

        pastCharacters[iterator] = current;

        auxiliary = charValue(current);

        // Se o caracter atual não existir na numeração romana, a função retorna -1.
        if(auxiliary == -1)
            return -1;

        else
            sum += auxiliary;

        if (current != last) {

            // Condicional para tratar de casos de subtração.
            if (subtractionPrecedence(last, current))
                sum -= (2 * charValue(last));

            last = current;
            lastCount = 1;
        }

        else {

            if (lastCount != 3)
                lastCount++;

            // Condicional para tratar de repetições excessivas de um caracter
            // gerando um argumento inválido.
            else
                return -1;

        }

    }

    return sum;

}

// Função auxiliar para verificar se um dado caracter pode ser repetido na numeração romana.
int canBeRepeated (char c) {

    int value = charValue(c);

    while (value >= 10)
        value = value/10;

    if (value == 1)
        return 1;

    else
        return 0;

}

// Função auxiliar que retorna o valor de um caracter na numeração romana.
int charValue (char current) {

    switch (current) {

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

// Função auxiliar para verificar se um dado par de caracteres constitui um caso em que
// o primeiro deve ser subtraido (ao invés de somado) ao valor total.
int subtractionPrecedence (char before, char after) {

    if ( (charValue(after)/charValue(before)) == 5 || (charValue(after)/charValue(before)) == 10 )
        return 1;

    else
        return 0;

}

// Função auxiliar para verificar se os caracteres anteriores a um dado caracter
// constituem um número válido na numeração romana.
int validPrecedences (char *before, char after) {

    unsigned int iterator;

    // O primeiro caracter sempre é aceito.
    if (strlen(before) == 0)
        return 1;

    // Laço verifica todos os caracteres anteriores ao atual EXCETO o último.
    for (iterator = 0; iterator < (strlen(before) - 1); iterator++) {

        // Não se pode ter um caracter de valor menor ao atual antes dele.
        // (A não ser no caso da subtração, que não é tratado aqui.).
        if ( (charValue(before[iterator])) < (charValue(after)) )
            return 0;

        else {

            if ( (charValue(before[iterator])) == (charValue(after)) ) {

                if ( !(canBeRepeated(after)) )
                    return 0;

                // Condicional especial para tratar de casos em que um caracter é
                // subtraído e depois tenta-se adicioná-lo ao número.
                if ( subtractionPrecedence(before[iterator], before[iterator + 1]) ) {

                    if ( !(subtractionPrecedence(before[(strlen(before) - 1)], after)) )
                        return 0;

                }

            }

        }

    }

    // Condicional que trata do caso de subtração.
    if ( subtractionPrecedence(before[iterator], after) )
        return 1;

    else if ( (charValue(before[iterator])) > (charValue(after)) )
        return 1;

    else if ( (charValue(before[iterator])) == (charValue(after)) ) {

        if ( (canBeRepeated(after)) )
            return 1;

        else
            return 0;

    }

    else
        return 0;

}
