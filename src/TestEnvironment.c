// Ambiente de testes.

#include "gtest/gtest.h"
#include "RomanNumberConversion.h"

char one[30] = "I", two[30] = "II", three[30] = "III", invalid[30] = "A";

TEST (romanNumberConversion, I) {

    EXPECT_EQ ((romanNumberConversion(one) == 1), 1);

}

TEST (romanNumberConversion, II) {

    EXPECT_EQ ((romanNumberConversion(two) == 2), 1);

}

TEST (romanNumberConversion, III) {

    EXPECT_EQ ((romanNumberConversion(three) == 3), 1);

}

TEST (romanNumberConversion, invalidArgument) {

    EXPECT_EQ ((romanNumberConversion(invalid) == -1), 1);

}

int main(int argc, char **argv) {

::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();

}
