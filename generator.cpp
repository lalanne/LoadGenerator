

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

void print_help() {
    cerr << "usage:\tload_generator <n> <t>" << endl;
    cerr << "n\tNumber of requests in parallel" << endl;
    cerr << "t\tNumber of times <n> will be executed" << endl;
}

struct Arguments {
    Arguments(const int argc, char** argv) : NUMBER_OF_REQUESTS_IN_PARALLEL(0), 
                                            NUMBER_OF_TIMES(0),
                                            number_of_arguments(argc),
                                            arguments(argv){}

    bool are_valid() {
        if(number_of_arguments != 3) { return false; }
        else { return true; }
    }

    void save() {
        NUMBER_OF_REQUESTS_IN_PARALLEL = stoi(arguments[1]);
        NUMBER_OF_TIMES = stoi(arguments[2]);
    }

    unsigned int NUMBER_OF_REQUESTS_IN_PARALLEL;
    unsigned int NUMBER_OF_TIMES;

    private:
        const unsigned number_of_arguments;
        char** arguments;
};

int main(int argc, char *argv[]) {
    Arguments arguments(argc, argv);
    if(arguments.are_valid()) {
        arguments.save();
        Results results(arguments.NUMBER_OF_TIMES, arguments.NUMBER_OF_REQUESTS_IN_PARALLEL);

        try {
            for(int time=0; time<arguments.NUMBER_OF_TIMES; ++time) {

                vector<future<pair<string, double>>> futures;
                for(int j=0; j<arguments.NUMBER_OF_REQUESTS_IN_PARALLEL; ++j) { 
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
    else {
        print_help();
        return FAIL;
    }
}
