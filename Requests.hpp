#ifndef REQUESTS_LFSOPFJSFOJSPFJ908
#define REQUESTS_LFSOPFJSFOJSPFJ908

#include <string>
#include <vector>

class Requests {
    public:
        Requests(const std::string& requests_file);

        void load();
        std::string request();

    private:
        const std::string& requests_file;
        std::vector<std::string> requests;

};

#endif //REQUESTS_LFSOPFJSFOJSPFJ908
