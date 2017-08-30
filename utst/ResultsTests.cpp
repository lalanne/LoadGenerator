
#include "Results.hpp"

#include <gtest/gtest.h>

#include <chrono>
#include <utility>

using namespace std;

TEST(ResultsTests, construction) {
    
    const unsigned int SOME_NUMBER_OF_RESULTS = 5;
    const unsigned int SOME_PARALEL_NUMBER_OF_REQUESTS = 1;

    Results res(SOME_NUMBER_OF_RESULTS, SOME_PARALEL_NUMBER_OF_REQUESTS);


    EXPECT_EQ(SOME_NUMBER_OF_RESULTS, res.number());
}

TEST(ResultsTests, add_time) {
    
    const unsigned int SOME_NUMBER_OF_RESULTS = 5;
    const unsigned int SOME_PARALEL_NUMBER_OF_REQUESTS = 1;
    const double SOME_TOTAL_TIME = 5.55;

    Results res(SOME_NUMBER_OF_RESULTS, SOME_PARALEL_NUMBER_OF_REQUESTS);

    chrono::duration<double> time(SOME_TOTAL_TIME);
    res.add(time);


    EXPECT_EQ(SOME_TOTAL_TIME, res.total_time());
}

TEST(ResultsTests, add_result) {
    const unsigned int SOME_NUMBER_OF_RESULTS = 5;
    const unsigned int SOME_PARALEL_NUMBER_OF_REQUESTS = 5;
    const unsigned int TARGET_EXECUTION = 3;
    const unsigned int EXPECTED_PARALLEL_SIZE = 4;
    const unsigned int SOME_VALUE = 9;
    const string SOME_NAME = "";

    Results res(SOME_NUMBER_OF_RESULTS, SOME_PARALEL_NUMBER_OF_REQUESTS);

    res.add(TARGET_EXECUTION, make_pair(SOME_NAME, SOME_VALUE));
    res.add(TARGET_EXECUTION, make_pair(SOME_NAME, SOME_VALUE));
    res.add(TARGET_EXECUTION, make_pair(SOME_NAME, SOME_VALUE));
    res.add(TARGET_EXECUTION, make_pair(SOME_NAME, SOME_VALUE));


    EXPECT_EQ(EXPECTED_PARALLEL_SIZE, res.parallel(TARGET_EXECUTION));
}


