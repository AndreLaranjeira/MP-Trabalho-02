// Ambiente de testes.

/**

  \file
  \brief Arquivo que testa a função para converter números romanos
  em número inteiros.

*/

#include "roman_number_conversion.h"
#include "gtest/gtest.h"

char name[50];

/** Teste para argumentos com mais de 30 caracteres. */

TEST (RomanNumberConversion, Invalid_Length) {

    strcpy(name, "IIIIIIIIIIAIIIIIIIIIIAIIIIIIIIIIIIA");

    EXPECT_EQ ((RomanNumberConversion(name) == -1), 1);

}

/** Teste para argumentos com caracteres inválidos. */

TEST (RomanNumberConversion, Invalid_Character) {

    strcpy(name, "A");

    EXPECT_EQ ((RomanNumberConversion(name) == -1), 1);

}

/** Teste do número 01. */

TEST (RomanNumberConversion, 01) {

    strcpy(name, "I");

    EXPECT_EQ ((RomanNumberConversion(name) == 1), 1);

}

/** Teste do número 02. */

TEST (RomanNumberConversion, 02) {

    strcpy(name, "II");

    EXPECT_EQ ((RomanNumberConversion(name) == 2), 1);

}

/** Teste do número 03. */

TEST (RomanNumberConversion, 03) {

    strcpy(name, "III");

    EXPECT_EQ ((RomanNumberConversion(name) == 3), 1);

}

/** Teste para argumentos com 4 caracteres repetidos e sequenciais. */

TEST (RomanNumberConversion, Four_Repetitions) {

    strcpy(name, "IIII");

    EXPECT_EQ ((RomanNumberConversion(name) == -1), 1);

}

/** Teste do número 04. */

TEST (RomanNumberConversion, 04) {

    strcpy(name, "IV");

    EXPECT_EQ ((RomanNumberConversion(name) == 4), 1);

}

/** Teste do número 05. */

TEST (RomanNumberConversion, 05) {

    strcpy(name, "V");

    EXPECT_EQ ((RomanNumberConversion(name) == 5), 1);

}

/** Teste do número 08. */

TEST (RomanNumberConversion, 08) {

    strcpy(name, "VIII");

    EXPECT_EQ ((RomanNumberConversion(name) == 8), 1);

}

/** Testes para argumentos com caracteres antes de um caracter de valor maior. */

TEST (RomanNumberConversion, Two_Characters_Before_A_Bigger_Character) {

    strcpy(name, "IIV");

    EXPECT_EQ ((RomanNumberConversion(name) == -1), 1);

}

TEST (RomanNumberConversion, Three_Characters_Before_A_Bigger_Character) {

    strcpy(name, "IIIV");

    EXPECT_EQ ((RomanNumberConversion(name) == -1), 1);

}

/** Teste para argumentos com uma repetição de caracter inválida. */

TEST (RomanNumberConversion, Invalid_Repetition) {

    strcpy(name, "VV");

    EXPECT_EQ ((RomanNumberConversion(name) == -1), 1);

}

/** Teste do número 09. */

TEST (RomanNumberConversion, 09) {

    strcpy(name, "IX");

    EXPECT_EQ ((RomanNumberConversion(name) == 9), 1);

}

/** Teste do número 14. */

TEST (RomanNumberConversion, 14) {

    strcpy(name, "XIV");

    EXPECT_EQ ((RomanNumberConversion(name) == 14), 1);

}

/** Teste do número 18. */

TEST (RomanNumberConversion, 18) {

    strcpy(name, "XVIII");

    EXPECT_EQ ((RomanNumberConversion(name) == 18), 1);

}

/** Teste do número 19. */

TEST (RomanNumberConversion, 19) {

    strcpy(name, "XIX");

    EXPECT_EQ ((RomanNumberConversion(name) == 19), 1);

}

/** Teste para argumentos com precedência inválida. */

TEST (RomanNumberConversion, Invalid_Character_Precedence) {

    strcpy(name, "VX");

    EXPECT_EQ ((RomanNumberConversion(name) == -1), 1);

}

/** Teste para argumentos com precedência inválida antes de uma subtração. */

TEST (RomanNumberConversion, Invalid_Precedence_Before_Subtraction) {

    strcpy(name, "VIX");

    EXPECT_EQ ((RomanNumberConversion(name) == -1), 1);

}

/** Teste para argumentos com repetição inválida após um caracter. */

TEST (RomanNumberConversion, Invalid_Repetition_After_Character) {

    strcpy(name, "VIV");

    EXPECT_EQ ((RomanNumberConversion(name) == -1), 1);

}

/** Teste do número 24. */

TEST (RomanNumberConversion, 24) {

    strcpy(name, "XXIV");

    EXPECT_EQ ((RomanNumberConversion(name) == 24), 1);

}

/** Teste do número 29. */

TEST (RomanNumberConversion, 29) {

    strcpy(name, "XXIX");

    EXPECT_EQ ((RomanNumberConversion(name) == 29), 1);

}

/** Teste para argumentos com precedência inválida após uma subtração. */

TEST (RomanNumberConversion, Invalid_Precedence_After_Subtraction) {

    strcpy(name, "XXIXX");

    EXPECT_EQ ((RomanNumberConversion(name) == -1), 1);

}

/** Teste do número 38. */

TEST (RomanNumberConversion, 38) {

    strcpy(name, "XXXVIII");

    EXPECT_EQ ((RomanNumberConversion(name) == 38), 1);

}

/** Teste do número 40. */

TEST (RomanNumberConversion, 40) {

    strcpy(name, "XL");

    EXPECT_EQ ((RomanNumberConversion(name) == 40), 1);

}

/** Teste do número 44. */

TEST (RomanNumberConversion, 44) {

    strcpy(name, "XLIV");

    EXPECT_EQ ((RomanNumberConversion(name) == 44), 1);

}

/** Teste do número 48. */

TEST (RomanNumberConversion, 48) {

    strcpy(name, "XLVIII");

    EXPECT_EQ ((RomanNumberConversion(name) == 48), 1);

}

/** Teste do número 49. */

TEST (RomanNumberConversion, 49) {

    strcpy(name, "XLIX");

    EXPECT_EQ ((RomanNumberConversion(name) == 49), 1);

}

/** Teste para argumentos que tentam adicionar caracteres subtraídos. */

TEST (RomanNumberConversion, Invalid_Precedence_Due_To_Subtraction) {

    strcpy(name, "XLX");

    EXPECT_EQ ((RomanNumberConversion(name) == -1), 1);

}

/** Teste do número 58. */

TEST (RomanNumberConversion, 58) {

    strcpy(name, "LVIII");

    EXPECT_EQ ((RomanNumberConversion(name) == 58), 1);

}

/** Teste do número 69. */

TEST (RomanNumberConversion, 69) {

    strcpy(name, "LXIX");

    EXPECT_EQ ((RomanNumberConversion(name) == 69), 1);

}

/** Teste do número 88. */

TEST (RomanNumberConversion, 88) {

    strcpy(name, "LXXXVIII");

    EXPECT_EQ ((RomanNumberConversion(name) == 88), 1);

}

/** Teste do número 90. */

TEST (RomanNumberConversion, 90) {

    strcpy(name, "XC");

    EXPECT_EQ ((RomanNumberConversion(name) == 90), 1);

}

/** Teste do número 99. */

TEST (RomanNumberConversion, 99) {

    strcpy(name, "XCIX");

    EXPECT_EQ ((RomanNumberConversion(name) == 99), 1);

}

/** Teste do número 111. */

TEST (RomanNumberConversion, 111) {

    strcpy(name, "CXI");

    EXPECT_EQ ((RomanNumberConversion(name) == 111), 1);

}

/** Teste do número 203. */

TEST (RomanNumberConversion, 203) {

    strcpy(name, "CCIII");

    EXPECT_EQ ((RomanNumberConversion(name) == 203), 1);

}

/** Teste do número 247. */

TEST (RomanNumberConversion, 247) {

    strcpy(name, "CCXLVII");

    EXPECT_EQ ((RomanNumberConversion(name) == 247), 1);

}

/** Teste do número 338. */

TEST (RomanNumberConversion, 338) {

    strcpy(name, "CCCXXXVIII");

    EXPECT_EQ ((RomanNumberConversion(name) == 338), 1);

}

/** Teste para argumentos com letras maiúsculas e minúsculas. */

TEST (RomanNumberConversion, Mixed_Case_Letters) {

    strcpy(name, "cCCxXxVIIi");

    EXPECT_EQ ((RomanNumberConversion(name) == 338), 1);

}

/** Teste do número 400. */

TEST (RomanNumberConversion, 400) {

    strcpy(name, "CD");

    EXPECT_EQ ((RomanNumberConversion(name) == 400), 1);

}

/** Teste do número 499. */

TEST (RomanNumberConversion, 499) {

    strcpy(name, "CDXCIX");

    EXPECT_EQ ((RomanNumberConversion(name) == 499), 1);

}

/** Teste do número 550. */

TEST (RomanNumberConversion, 550) {

    strcpy(name, "DL");

    EXPECT_EQ ((RomanNumberConversion(name) == 550), 1);

}

/** Teste do número 695. */

TEST (RomanNumberConversion, 695) {

    strcpy(name, "DCXCV");

    EXPECT_EQ ((RomanNumberConversion(name) == 695), 1);

}

/** Teste do número 713. */

TEST (RomanNumberConversion, 713) {

    strcpy(name, "DCCXIII");

    EXPECT_EQ ((RomanNumberConversion(name) == 713), 1);

}

/** Teste do número 888. */

TEST (RomanNumberConversion, 888) {

    strcpy(name, "DCCCLXXXVIII");

    EXPECT_EQ ((RomanNumberConversion(name) == 888), 1);

}

/** Teste do número 900. */

TEST (RomanNumberConversion, 900) {

    strcpy(name, "CM");

    EXPECT_EQ ((RomanNumberConversion(name) == 900), 1);

}

/** Teste do número 999. */

TEST (RomanNumberConversion, 999) {

    strcpy(name, "CMXCIX");

    EXPECT_EQ ((RomanNumberConversion(name) == 999), 1);

}

/** Teste do número 1047. */

TEST (RomanNumberConversion, 1047) {

    strcpy(name, "MXLVII");

    EXPECT_EQ ((RomanNumberConversion(name) == 1047), 1);

}

/** Teste do número 1941. */

TEST (RomanNumberConversion, 1941) {

    strcpy(name, "MCMXLI");

    EXPECT_EQ ((RomanNumberConversion(name) == 1941), 1);

}

/** Teste do número 2889. */

TEST (RomanNumberConversion, 2889) {

    strcpy(name, "MMDCCCLXXXIX");

    EXPECT_EQ ((RomanNumberConversion(name) == 2889), 1);

}

/** Teste do número 3000. */

TEST (RomanNumberConversion, 3000) {

    strcpy(name, "MMM");

    EXPECT_EQ ((RomanNumberConversion(name) == 3000), 1);

}

int main(int argc, char **argv) {

::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();

}
