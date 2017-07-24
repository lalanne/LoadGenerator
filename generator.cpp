

#include "Results.hpp"
#include "policies.hpp"
#include "Arguments.hpp"
#include "Requests.hpp"

#include <future>
#include <chrono>
#include <utility>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const int SUCCESS   = 0;
const int FAIL      = -1;

int main(int argc, char *argv[]) {
    Arguments arguments(argc, argv);
    if(arguments.are_valid()) {
        arguments.save();
        Results results(arguments.NUMBER_OF_TIMES, arguments.NUMBER_OF_REQUESTS_IN_PARALLEL);
        Requests requests(arguments.REQUESTS_FILE);
        requests.load();

        try {
            auto start = chrono::steady_clock::now();
            for(int time=0; time<arguments.NUMBER_OF_TIMES; ++time) {

                vector<future<pair<string, double>>> futures;
                for(int j=0; j<arguments.NUMBER_OF_REQUESTS_IN_PARALLEL; ++j) { 
                    futures.push_back(async(launch::async, request_response, j, std::ref(requests))); 
                }

                for (auto& ft : futures) { results.add(time, ft.get()); }

            }
            auto end = chrono::steady_clock::now();
            auto diff = end-start;
            results.add(diff.count());
            results.show();
        }
        catch(std::exception& e){
            std::cerr << "Exception: " << e.what() << "\n";
        }

        return SUCCESS;
    }
    else {
        arguments.print_help();

        return FAIL;
    }
}


