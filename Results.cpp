
#include "Results.hpp"

#include <iostream>

using namespace std;

Results::Results(const unsigned int times, const unsigned int parallel_request) : 
                results(times), total_time_of_execution(0.0f) {}


void Results::add(const unsigned int time, pair<string, double> result) {
    results[time].push_back(result);
}

void Results::add(chrono::duration<double> time) {
    total_time_of_execution = time.count();
}

unsigned int Results::number() const {
    return results.size();
}

double Results::total_time() const {
    return total_time_of_execution;
}

void Results::show() const {
    cout << "************************************** times[" << results.size() << "] **********************************\n";
    for (auto& time : results) { 
        cout << "************************************** results[" << time.size() << "] **********************************\n";
        for(auto& result : time) {
            cout << "result\t[" << get<0>(result) << "] latency\t[" << get<1>(result) << "]\n"; 
        }
    }

    cout << "total time of execution [" << total_time_of_execution << "]s \n";
}

