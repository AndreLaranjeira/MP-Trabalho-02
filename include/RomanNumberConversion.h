// Function that converts roman numbers to integers - header.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    working,
    invalidLength,
    invalidArgument
} romanExitConditions;

int romanNumberConversion (char *);
int canBeRepeated (char);
int charValue (char);
int subtractionPrecedence (char, char);
int validPrecedences (char *, char);
