
#include "Requests.hpp"

#include <gtest/gtest.h>

#include <string>

using namespace std;

const string EXPECTED_BASIC_REQUEST = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n\
<msg>\n\
    <header id_trans=\"1111\" app=\"xml\" user=\"ussd\" passw=\"ussd\" action=\"1\"/>\n\
    <req>\n\
        <op>req_comp_promo</op>\n\
        <msisdn>56999694444</msisdn>\n\
        <idPromo>BO_80MB_2D</idPromo>\n\
    </req>\n\
</msg>";

TEST(RequestsTests, basic_request) {
    
    Requests requests("test1.dat");
    requests.load();

    string request = requests.request();

    EXPECT_STREQ(EXPECTED_BASIC_REQUEST.c_str(), request.c_str());
}

