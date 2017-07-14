
#include "policies.hpp"

#include <boost/asio.hpp>

#include <chrono>

using namespace std;
using boost::asio::ip::tcp;

const string SERVER_HOST = "127.0.0.1";
const string SERVER_PORT = "4040";

const int RESPONSE_MAX_LENGTH = 215;

const string request = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?><msg><header id_trans=\"1111\" app=\"xml\" user=\"ussd\" passw=\"ussd\" action=\"1\"/><req><op>req_comp_promo</op><msisdn>56999694444</msisdn><idPromo>BO_80MB_2D</idPromo></req></msg>";

pair<string, double> request_response(const unsigned int index) {
    auto start = chrono::steady_clock::now();

    boost::asio::io_service io_service;

    tcp::socket s(io_service);
    tcp::resolver resolver(io_service);
    boost::asio::connect(s, resolver.resolve({SERVER_HOST, SERVER_PORT}));

    boost::asio::write(s, boost::asio::buffer(request, request.size()));

    char response[RESPONSE_MAX_LENGTH];
    size_t response_length = boost::asio::read(s, boost::asio::buffer(response, RESPONSE_MAX_LENGTH));

    auto end = chrono::steady_clock::now();
    auto diff = end-start;

    return make_pair(string(response), chrono::duration <double, milli> (diff).count());
}