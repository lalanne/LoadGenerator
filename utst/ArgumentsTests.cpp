
#include "Arguments.hpp"

#include <gtest/gtest.h>

TEST(ArgumentsTests, construction) {
    const int SOME_NUMBER_OF_ARGUMENTS = 3;

    Arguments args(SOME_NUMBER_OF_ARGUMENTS, nullptr);

    const int EXPECTED_NUMBER_OF_REQUESTS_IN_PARALLEL = 0;
    const int EXPECTED_NUMBER_OF_TIMES = 0;

    EXPECT_EQ(EXPECTED_NUMBER_OF_REQUESTS_IN_PARALLEL, args.NUMBER_OF_REQUESTS_IN_PARALLEL);
    EXPECT_EQ(EXPECTED_NUMBER_OF_TIMES, args.NUMBER_OF_TIMES);
}

TEST(ArgumentsTests, are_valid) {
    const int CORRECT_NUMBER_OF_ARGUMENTS = 4;

    Arguments args(CORRECT_NUMBER_OF_ARGUMENTS, nullptr);

    EXPECT_TRUE(args.are_valid());
}

TEST(ArgumentsTests, are_not_valid) {
    const int INCORRECT_NUMBER_OF_ARGUMENTS = 3;

    Arguments args(INCORRECT_NUMBER_OF_ARGUMENTS, nullptr);

    EXPECT_FALSE(args.are_valid());
}
