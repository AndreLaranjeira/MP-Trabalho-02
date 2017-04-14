// Function that converts roman numbers to integers.

#include "RomanNumberConversion.h"

int romanNumberConversion (char *roman) {

    char current, last = '0', pastCharacters[30] = "";
    unsigned int iterator, lastCount;
    int auxiliary, sum = 0;

    if (strlen(roman) > 30)
        exit(1);

    for (iterator = 0; iterator < strlen(roman); iterator++) {

        current = toupper(roman[iterator]);

        if( !(validPrecedences(pastCharacters, current)) )
            exit(2);

        pastCharacters[iterator] = current;

        auxiliary = charValue(current);

        if(auxiliary == -1)
            exit(2);

        else
            sum += auxiliary;

        if (current != last) {

            if (subtractionPrecedence(last, current)) {

                if (lastCount != 1)
                    exit(2);

                sum -= (2 * charValue(last));

            }

            last = current;
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

int canBeRepeated (char c) {

    int value = charValue(c);

    while (value >= 10)
        value = value/10;

    if (value == 1)
        return 1;

    else
        return 0;

}

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

int subtractionPrecedence (char before, char after) {

    if ( (charValue(after)/charValue(before)) == 5 || (charValue(after)/charValue(before)) == 10 )
        return 1;

    else
        return 0;

}

int validPrecedences (char *before, char after) {

    unsigned int iterator;

    if (strlen(before) == 0)
        return 1;

    for (iterator = 0; iterator < (strlen(before) - 1); iterator++) {

        if ( (charValue(before[iterator])) < (charValue(after)) )
            return 0;

        else {

            if ( (charValue(before[iterator])) == (charValue(after)) ) {

                if ( !(canBeRepeated(after)) )
                    return 0;

                if ( subtractionPrecedence(before[iterator], before[iterator + 1]) ) {

                    if ( !(subtractionPrecedence(before[(strlen(before) - 1)], after)) )
                        return 0;

                }

            }

        }

    }

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
