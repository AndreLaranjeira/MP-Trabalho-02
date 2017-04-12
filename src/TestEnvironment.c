// Ambiente de testes.

#include "gtest/gtest.h"
#include "RomanNumberConversion.h"

char one[30] = "I", two[30] = "II";

TEST (romanNumberConversion, I) {

    EXPECT_EQ ((romanNumberConversion(one) == 1), 1);

}

TEST (romanNumberConversion, II) {

    EXPECT_EQ ((romanNumberConversion(two) == 2), 1);

}

int main(int argc, char **argv) {

::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();

}
