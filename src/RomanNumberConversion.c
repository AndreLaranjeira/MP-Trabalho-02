// Function that converts roman numbers to integers.

#include "RomanNumberConversion.h"

int romanNumberConversion (char *roman) {

    char c;
    unsigned int i;
    int sum = 0;

    if (strlen(roman) > 30)
        exit (1);

    for (i = 0; i < strlen(roman); i++) {

        c = roman[i];

        switch (c) {

            case 'I':
                sum += 1;
                break;

            default:
                exit (2);

        }

    }

    return sum;

}
