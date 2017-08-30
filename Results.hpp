
#ifndef RESULTS_OEFJPQWOEJFPQOWJFE
#define RESULTS_OEFJPQWOEJFPQOWJFE

#include <vector>
#include <utility>
#include <string>
#include <chrono>

class Results {
    public:
        Results(const unsigned int times, const unsigned int parallel_requests);

        void add(const unsigned int time, std::pair<std::string, double> result);
        void add(std::chrono::duration<double> time);
        void show() const;
        unsigned int number() const;
        unsigned int parallel(const unsigned int execution) const;
        double total_time() const;

    private:
        std::vector<std::vector<std::pair<std::string, double>>> results;
        double total_time_of_execution;
};

#endif //RESULTS_OEFJPQWOEJFPQOWJFE
