// Ambiente de testes.

#include "gtest/gtest.h"
#include "RomanNumberConversion.h"

char name[30];

TEST (romanNumberConversion, Invalid_Length) {

    strcpy(name, "IIIIIIIIIIAIIIIIIIIIIAIIIIIIIIIIIIA");

    EXPECT_EQ ((romanNumberConversion(name) == -1), 1);

}

TEST (romanNumberConversion, Invalid_Character) {

    strcpy(name, "A");

    EXPECT_EQ ((romanNumberConversion(name) == -1), 1);

}

TEST (romanNumberConversion, 01) {

    strcpy(name, "I");

    EXPECT_EQ ((romanNumberConversion(name) == 1), 1);

}

TEST (romanNumberConversion, 02) {

    strcpy(name, "II");

    EXPECT_EQ ((romanNumberConversion(name) == 2), 1);

}

TEST (romanNumberConversion, 03) {

    strcpy(name, "III");

    EXPECT_EQ ((romanNumberConversion(name) == 3), 1);

}

TEST (romanNumberConversion, Four_Repetitions) {

    strcpy(name, "IIII");

    EXPECT_EQ ((romanNumberConversion(name) == -1), 1);

}

TEST (romanNumberConversion, 04) {

    strcpy(name, "IV");

    EXPECT_EQ ((romanNumberConversion(name) == 4), 1);

}

TEST (romanNumberConversion, 05) {

    strcpy(name, "V");

    EXPECT_EQ ((romanNumberConversion(name) == 5), 1);

}

TEST (romanNumberConversion, 08) {

    strcpy(name, "VIII");

    EXPECT_EQ ((romanNumberConversion(name) == 8), 1);

}

TEST (romanNumberConversion, Two_Characters_Before_A_Bigger_Character) {

    strcpy(name, "IIV");

    EXPECT_EQ ((romanNumberConversion(name) == -1), 1);

}

TEST (romanNumberConversion, Three_Characters_Before_A_Bigger_Character) {

    strcpy(name, "IIIV");

    EXPECT_EQ ((romanNumberConversion(name) == -1), 1);

}

TEST (romanNumberConversion, Invalid_Repetition) {

    strcpy(name, "VV");

    EXPECT_EQ ((romanNumberConversion(name) == -1), 1);

}

TEST (romanNumberConversion, 09) {

    strcpy(name, "IX");

    EXPECT_EQ ((romanNumberConversion(name) == 9), 1);

}

TEST (romanNumberConversion, 14) {

    strcpy(name, "XIV");

    EXPECT_EQ ((romanNumberConversion(name) == 14), 1);

}

TEST (romanNumberConversion, 18) {

    strcpy(name, "XVIII");

    EXPECT_EQ ((romanNumberConversion(name) == 18), 1);

}

TEST (romanNumberConversion, 19) {

    strcpy(name, "XIX");

    EXPECT_EQ ((romanNumberConversion(name) == 19), 1);

}

TEST (romanNumberConversion, Invalid_Character_Precedence) {

    strcpy(name, "VX");

    EXPECT_EQ ((romanNumberConversion(name) == -1), 1);

}

TEST (romanNumberConversion, Invalid_Precedence_Before_Subtraction) {

    strcpy(name, "VIX");

    EXPECT_EQ ((romanNumberConversion(name) == -1), 1);

}

TEST (romanNumberConversion, 24) {

    strcpy(name, "XXIV");

    EXPECT_EQ ((romanNumberConversion(name) == 24), 1);

}

TEST (romanNumberConversion, 29) {

    strcpy(name, "XXIX");

    EXPECT_EQ ((romanNumberConversion(name) == 29), 1);

}

TEST (romanNumberConversion, Invalid_Precedence_After_Subtraction) {

    strcpy(name, "XXIXX");

    EXPECT_EQ ((romanNumberConversion(name) == -1), 1);

}

TEST (romanNumberConversion, 38) {

    strcpy(name, "XXXVIII");

    EXPECT_EQ ((romanNumberConversion(name) == 38), 1);

}

TEST (romanNumberConversion, 40) {

    strcpy(name, "XL");

    EXPECT_EQ ((romanNumberConversion(name) == 40), 1);

}

TEST (romanNumberConversion, 44) {

    strcpy(name, "XLIV");

    EXPECT_EQ ((romanNumberConversion(name) == 44), 1);

}

TEST (romanNumberConversion, 48) {

    strcpy(name, "XLVIII");

    EXPECT_EQ ((romanNumberConversion(name) == 48), 1);

}

TEST (romanNumberConversion, 49) {

    strcpy(name, "XLIX");

    EXPECT_EQ ((romanNumberConversion(name) == 49), 1);

}

TEST (romanNumberConversion, Invalid_Precedence_Due_To_Subtraction) {

    strcpy(name, "XLX");

    EXPECT_EQ ((romanNumberConversion(name) == -1), 1);

}

TEST (romanNumberConversion, 58) {

    strcpy(name, "LVIII");

    EXPECT_EQ ((romanNumberConversion(name) == 58), 1);

}

TEST (romanNumberConversion, 69) {

    strcpy(name, "LXIX");

    EXPECT_EQ ((romanNumberConversion(name) == 69), 1);

}

TEST (romanNumberConversion, 88) {

    strcpy(name, "LXXXVIII");

    EXPECT_EQ ((romanNumberConversion(name) == 88), 1);

}

TEST (romanNumberConversion, 90) {

    strcpy(name, "XC");

    EXPECT_EQ ((romanNumberConversion(name) == 90), 1);

}

TEST (romanNumberConversion, 99) {

    strcpy(name, "XCIX");

    EXPECT_EQ ((romanNumberConversion(name) == 99), 1);

}

TEST (romanNumberConversion, 111) {

    strcpy(name, "CXI");

    EXPECT_EQ ((romanNumberConversion(name) == 111), 1);

}

TEST (romanNumberConversion, 203) {

    strcpy(name, "CCIII");

    EXPECT_EQ ((romanNumberConversion(name) == 203), 1);

}

TEST (romanNumberConversion, 247) {

    strcpy(name, "CCXLVII");

    EXPECT_EQ ((romanNumberConversion(name) == 247), 1);

}

TEST (romanNumberConversion, 338) {

    strcpy(name, "CCCXXXVIII");

    EXPECT_EQ ((romanNumberConversion(name) == 338), 1);

}

TEST (romanNumberConversion, Lower_Case_Letters) {

    strcpy(name, "cccxxxviii");

    EXPECT_EQ ((romanNumberConversion(name) == 338), 1);

}

TEST (romanNumberConversion, 400) {

    strcpy(name, "CD");

    EXPECT_EQ ((romanNumberConversion(name) == 400), 1);

}

TEST (romanNumberConversion, 499) {

    strcpy(name, "CDXCIX");

    EXPECT_EQ ((romanNumberConversion(name) == 499), 1);

}

TEST (romanNumberConversion, 550) {

    strcpy(name, "DL");

    EXPECT_EQ ((romanNumberConversion(name) == 550), 1);

}

TEST (romanNumberConversion, 695) {

    strcpy(name, "DCXCV");

    EXPECT_EQ ((romanNumberConversion(name) == 695), 1);

}

TEST (romanNumberConversion, 713) {

    strcpy(name, "DCCXIII");

    EXPECT_EQ ((romanNumberConversion(name) == 713), 1);

}

TEST (romanNumberConversion, 888) {

    strcpy(name, "DCCCLXXXVIII");

    EXPECT_EQ ((romanNumberConversion(name) == 888), 1);

}

TEST (romanNumberConversion, 900) {

    strcpy(name, "CM");

    EXPECT_EQ ((romanNumberConversion(name) == 900), 1);

}

TEST (romanNumberConversion, 999) {

    strcpy(name, "CMXCIX");

    EXPECT_EQ ((romanNumberConversion(name) == 999), 1);

}

TEST (romanNumberConversion, 1047) {

    strcpy(name, "MXLVII");

    EXPECT_EQ ((romanNumberConversion(name) == 1047), 1);

}

TEST (romanNumberConversion, 1941) {

    strcpy(name, "MCMXLI");

    EXPECT_EQ ((romanNumberConversion(name) == 1941), 1);

}

TEST (romanNumberConversion, 2889) {

    strcpy(name, "MMDCCCLXXXIX");

    EXPECT_EQ ((romanNumberConversion(name) == 2889), 1);

}

TEST (romanNumberConversion, 3000) {

    strcpy(name, "MMM");

    EXPECT_EQ ((romanNumberConversion(name) == 3000), 1);

}

int main(int argc, char **argv) {

::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();

}
