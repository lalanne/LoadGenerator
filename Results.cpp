
#include "Results.hpp"

#include <iostream>

using namespace std;

Results::Results(const unsigned int times, const unsigned int parallel_request) : results(times) {}


void Results::add(const unsigned int time, pair<string, double> result) {
    results[time].push_back(result);
}


void Results::show() const {
    cout << "************************************** times[" << results.size() << "] **********************************" << endl;
    for (auto& time : results) { 
        cout << "************************************** results[" << time.size() << "] **********************************" << endl;
        for(auto& result : time) {
            cout << "result[" << get<0>(result) << "] latency[" << get<1>(result) << "]" << endl; 
        }
    }
}

