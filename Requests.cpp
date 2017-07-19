
#include "Requests.hpp"

#include <iostream>

using namespace std;

Requests::Requests(const std::string& requests_file) : requests_file(requests_file) {}

void Requests::load() {
    cout << "loading requests from file: " << requests_file << endl; 

    const string request = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>"
                            "<msg>"
                                "<header id_trans=\"1111\" app=\"xml\" user=\"ussd\" passw=\"ussd\" action=\"1\"/>"
                                "<req>"
                                    "<op>req_comp_promo</op>"
                                    "<msisdn>56999694444</msisdn>"
                                    "<idPromo>BO_80MB_2D</idPromo>"
                                "</req>"
                            "</msg>";

    requests.push_back(request);
}

string Requests::request() {
    return requests[0];
}
