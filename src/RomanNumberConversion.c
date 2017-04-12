// Function that converts roman numbers to integers.

#include "RomanNumberConversion.h"

int romanNumberConversion (char *roman) {

    char c;
    unsigned int i;
    int sum = 0;

    for (i = 0; i < strlen(roman); i++) {

        c = roman[i];

        switch (c) {

            case 'I':
                sum += 1;
                break;

            default:
                sum = -1;
                break;

        }

        if(sum == -1)
            break;

    }

    return sum;

}
