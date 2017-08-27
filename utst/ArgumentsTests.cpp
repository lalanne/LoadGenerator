
#include "Arguments.hpp"

#include <gtest/gtest.h>

TEST(ArgumentsTests, constructor) {
    const int SOME_NUMBER_OF_ARGUMENTS = 3;

    Arguments args(SOME_NUMBER_OF_ARGUMENTS, nullptr);

    const int EXPECTED_NUMBER_OF_REQUESTS_IN_PARALLEL = 0;
    const int EXPECTED_NUMBER_OF_TIMES = 0;

    EXPECT_EQ(EXPECTED_NUMBER_OF_REQUESTS_IN_PARALLEL, args.NUMBER_OF_REQUESTS_IN_PARALLEL);
    EXPECT_EQ(EXPECTED_NUMBER_OF_TIMES, args.NUMBER_OF_TIMES);
}
