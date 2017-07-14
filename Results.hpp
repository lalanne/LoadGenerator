
#ifndef RESULTS_OEFJPQWOEJFPQOWJFE
#define RESULTS_OEFJPQWOEJFPQOWJFE

#include <vector>
#include <utility>
#include <string>

class Results {
    public:
        Results(const int times, const int parallel_request);

        void add(const int time, std::pair<std::string, double> result);
        void show() const;

    private:
        std::vector<std::vector<std::pair<std::string, double>>> results;

};

#endif //RESULTS_OEFJPQWOEJFPQOWJFE
