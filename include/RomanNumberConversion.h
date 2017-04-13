// Function that converts roman numbers to integers - header.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    working,
    invalidLength,
    invalidCharacter
} romanExitConditions;

int romanNumberConversion (char *);
int charValue (char);
