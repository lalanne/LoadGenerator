

#include <boost/asio.hpp>

#include <thread>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
using boost::asio::ip::tcp;

const int SUCCESS = 0;
const string SERVER_HOST = "127.0.0.1";
const string SERVER_PORT = "4040";
const int RESPONSE_MAX_LENGTH = 215;
const int NUMBER_OF_REQUESTS_IN_PARALLEL = 100;
const int NUMBER_OF_TIMES = 5;

const string request = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?><msg><header id_trans=\"1111\" app=\"xml\" user=\"ussd\" passw=\"ussd\" action=\"1\"/><req><op>req_comp_promo</op><msisdn>56999694444</msisdn><idPromo>BO_80MB_2D</idPromo></req></msg>";


void execute_request() {
    boost::asio::io_service io_service;

    tcp::socket s(io_service);
    tcp::resolver resolver(io_service);
    boost::asio::connect(s, resolver.resolve({SERVER_HOST, SERVER_PORT}));

    boost::asio::write(s, boost::asio::buffer(request, request.size()));

    char response[RESPONSE_MAX_LENGTH];
    size_t response_length = boost::asio::read(s, boost::asio::buffer(response, RESPONSE_MAX_LENGTH));

    cout << "Reply is: ";
    cout.write(response, response_length);
    cout << "\n";

}

int main() {
    cout << "Load generator initializing ..." << endl;

    try {
        for(int i=0; i<NUMBER_OF_TIMES; ++i) {
            vector<thread> v;
            for(int j=0; j<NUMBER_OF_REQUESTS_IN_PARALLEL; ++j) { v.emplace_back(execute_request); }
            for (auto& t : v) { t.join(); }
        }
    }
    catch(std::exception& e){
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return SUCCESS;
}
