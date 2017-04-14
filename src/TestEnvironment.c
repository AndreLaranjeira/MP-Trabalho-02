// Ambiente de testes.

#include "gtest/gtest.h"
#include "RomanNumberConversion.h"

char name[30];

TEST (romanNumberConversion, Invalid_Length) {

    strcpy(name, "IIIIIIIIIIAIIIIIIIIIIAIIIIIIIIIIIIA");

    EXPECT_EXIT ({romanNumberConversion(name);}, ::testing::ExitedWithCode( romanExitConditions(invalidLength) ), "");

}

TEST (romanNumberConversion, Invalid_Character) {

    strcpy(name, "A");

    EXPECT_EXIT ({romanNumberConversion(name);}, ::testing::ExitedWithCode( romanExitConditions(invalidArgument) ), "");

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

    EXPECT_EXIT ({romanNumberConversion(name);}, ::testing::ExitedWithCode( romanExitConditions(invalidArgument) ), "");

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

    EXPECT_EXIT ({romanNumberConversion(name);}, ::testing::ExitedWithCode( romanExitConditions(invalidArgument) ), "");

}

TEST (romanNumberConversion, Three_Characters_Before_A_Bigger_Character) {

    strcpy(name, "IIIV");

    EXPECT_EXIT ({romanNumberConversion(name);}, ::testing::ExitedWithCode( romanExitConditions(invalidArgument) ), "");

}

TEST (romanNumberConversion, Invalid_Repetition) {

    strcpy(name, "VV");

    EXPECT_EXIT ({romanNumberConversion(name);}, ::testing::ExitedWithCode( romanExitConditions(invalidArgument) ), "");

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

    EXPECT_EXIT ({romanNumberConversion(name);}, ::testing::ExitedWithCode( romanExitConditions(invalidArgument) ), "");

}

TEST (romanNumberConversion, Invalid_Precedence_Before_Subtraction) {

    strcpy(name, "VIX");

    EXPECT_EXIT ({romanNumberConversion(name);}, ::testing::ExitedWithCode( romanExitConditions(invalidArgument) ), "");

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

    EXPECT_EXIT ({romanNumberConversion(name);}, ::testing::ExitedWithCode( romanExitConditions(invalidArgument) ), "");

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

    EXPECT_EXIT ({romanNumberConversion(name);}, ::testing::ExitedWithCode( romanExitConditions(invalidArgument) ), "");

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

int main(int argc, char **argv) {

::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();

}
