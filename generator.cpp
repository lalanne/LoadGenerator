

#include "Results.hpp"
#include "policies.hpp"

#include <future>
#include <utility>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const int SUCCESS   = 0;
const int FAIL      = -1;

int main(int argc, char *argv[]) {
    unsigned int NUMBER_OF_REQUESTS_IN_PARALLEL = 0;
    unsigned int NUMBER_OF_TIMES = 0;

    if(argc != 3) {
        cerr << "load_generator <# requests in parallel> <# times>" << endl;
        return FAIL;
    }
    else {
        NUMBER_OF_REQUESTS_IN_PARALLEL = stoi(argv[1]);
        NUMBER_OF_TIMES = stoi(argv[2]);
    }

    Results results(NUMBER_OF_TIMES, NUMBER_OF_REQUESTS_IN_PARALLEL);

    try {
        for(int time=0; time<NUMBER_OF_TIMES; ++time) {

            vector<future<pair<string, double>>> futures;
            for(int j=0; j<NUMBER_OF_REQUESTS_IN_PARALLEL; ++j) { 
                futures.push_back(async(launch::async, request_response, j)); 
            }

            for (auto& ft : futures) { results.add(time, ft.get()); }

        }
       
        results.show();
    }
    catch(std::exception& e){
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return SUCCESS;
}
