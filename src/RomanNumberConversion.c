// Function that converts roman numbers to integers.

#include "RomanNumberConversion.h"

int charValue (char c) {

    switch (c) {

        case 'I':
            return 1;

        case 'V':
            return 5;

        case 'X':
            return 10;

        case 'L':
            return 50;

        default:
            return -1;

    }

}

int romanNumberConversion (char *roman) {

    char c, last = '0';
    unsigned int i, lastCount;
    int aux, sum = 0;

    if (strlen(roman) > 30)
        exit(1);

    for (i = 0; i < strlen(roman); i++) {

        c = roman[i];

        aux = charValue(c);

        if(aux == -1)
            exit(2);

        else
            sum += aux;

        if (c != last) {

            if (subtractionPrecedence(last, c)) {

                if (lastCount != 1)
                    exit(2);

                sum -= (2 * charValue(last));

            }

            else {
                if ( (last != '0') && charValue(c) > charValue(last) )
                    exit(2);
            }

            last = c;
            lastCount = 1;
        }

        else {

            if (lastCount != 3)
                lastCount++;

            else
                exit(2);

        }

    }

    return sum;

}

int subtractionPrecedence (char before, char after) {

    if ( (charValue(after)/charValue(before)) == 5 || (charValue(after)/charValue(before)) == 10 )
        return 1;

    else
        return 0;

}
