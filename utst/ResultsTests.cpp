
#include "Results.hpp"

#include <gtest/gtest.h>

#include <chrono>

using namespace std;

TEST(ResultsTests, construction) {
    
    const unsigned int SOME_NUMBER_OF_RESULTS = 5;
    const unsigned int SOME_PARALEL_NUMBER_OF_REQUESTS = 1;

    Results res(SOME_NUMBER_OF_RESULTS, SOME_PARALEL_NUMBER_OF_REQUESTS);


    EXPECT_EQ(SOME_NUMBER_OF_RESULTS, res.number());
}

TEST(ResultsTests, add) {
    
    const unsigned int SOME_NUMBER_OF_RESULTS = 5;
    const unsigned int SOME_PARALEL_NUMBER_OF_REQUESTS = 1;

    Results res(SOME_NUMBER_OF_RESULTS, SOME_PARALEL_NUMBER_OF_REQUESTS);

    chrono::duration<double> time(5.5);
    res.add(time);


    EXPECT_EQ(5.5, res.total_time());
}
