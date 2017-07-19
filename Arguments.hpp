
#ifndef ARGUMENTS_QKEFNEPFQPWOE3
#define ARGUMENTS_QKEFNEPFQPWOE3

#include <string>
#include <iostream>

struct Arguments {
    Arguments(const int argc, char** argv) : NUMBER_OF_REQUESTS_IN_PARALLEL(0), 
                                            NUMBER_OF_TIMES(0),
                                            number_of_arguments(argc),
                                            arguments(argv){}

    bool are_valid() {
        if(number_of_arguments != CORRECT_NUMBER_OF_ARGUMENTS) { return false; }
        else { return true; }
    }

    void save() {
        NUMBER_OF_REQUESTS_IN_PARALLEL = std::stoi(arguments[1]);
        NUMBER_OF_TIMES = std::stoi(arguments[2]);
        REQUESTS_FILE = arguments[3];
    }

    void print_help() const {
        std::cerr << "usage:\tload_generator <n> <t> <f>" << std::endl;
        std::cerr << "n\tNumber of requests in parallel" << std::endl;
        std::cerr << "t\tNumber of times <n> will be executed" << std::endl;
        std::cerr << "f\tFile with the requests to use by the generator" << std::endl;
    }

    unsigned int NUMBER_OF_REQUESTS_IN_PARALLEL;
    unsigned int NUMBER_OF_TIMES;
    std::string REQUESTS_FILE;

    private:
        const unsigned number_of_arguments;
        char** arguments;
        const unsigned int CORRECT_NUMBER_OF_ARGUMENTS = 4;
};

#endif //ARGUMENTS_QKEFNEPFQPWOE3
