// Ambiente de testes.

#include "gtest/gtest.h"
#include "RomanNumberConversion.h"

char name[30];

TEST (romanNumberConversion, I) {

    strcpy(name, "I");

    EXPECT_EQ ((romanNumberConversion(name) == 1), 1);

}

TEST (romanNumberConversion, II) {

    strcpy(name, "II");

    EXPECT_EQ ((romanNumberConversion(name) == 2), 1);

}

TEST (romanNumberConversion, III) {

    strcpy(name, "III");

    EXPECT_EQ ((romanNumberConversion(name) == 3), 1);

}

TEST (romanNumberConversion, invalidArgument) {

    strcpy(name, "A");

    EXPECT_EQ ((romanNumberConversion(name) == -1), 1);

}

int main(int argc, char **argv) {

::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();

}
