#include <map>
#include <vector>
#include <string>

class Parser {
    public:
        Parser();
        void runParse();
        std::map<int, std::vector<std::pair<int, long double>>> getRoutes();
        std::map<int, std::pair<long double, long double>> getAirports();
    private:
        int isNumber(std::string s);
        long double toRadians(const long double degree);
        long double distance(long double lat1, long double long1, long double lat2, long double long2);
        std::map<int, std::vector<std::pair<int, long double>>> routes;
        std::map<int, std::pair<long double, long double>> airports;
};