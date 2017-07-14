
#ifndef RESULTS_OEFJPQWOEJFPQOWJFE
#define RESULTS_OEFJPQWOEJFPQOWJFE

#include <vector>
#include <utility>
#include <string>

class Results {
    public:
        Results(const unsigned int times, const unsigned int parallel_requests);

        void add(const unsigned int time, std::pair<std::string, double> result);
        void show() const;

    private:
        std::vector<std::vector<std::pair<std::string, double>>> results;

};

#endif //RESULTS_OEFJPQWOEJFPQOWJFE
