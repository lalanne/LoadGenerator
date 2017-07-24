
#include "Requests.hpp"

#include <iostream>
#include <fstream>

using namespace std;

Requests::Requests(const std::string& requests_file) : requests_file(requests_file) {}

void Requests::load() {
    ifstream fin(requests_file);
    string content((istreambuf_iterator<char>(fin)), (istreambuf_iterator<char>()));

    content.pop_back();
    requests.push_back(content);
}

string Requests::request() {
    return requests[0];
}
