#include <map>
#include <vector>
#include <string>
#include <queue>

#include "globals.h"

class Parser {
    public:
        Parser();
        void runParse();
        std::vector<std::priority_queue<psd, std::vector<psd>, std::greater<psd>>> getRoutes();
        std::vector<std::pair<long double, long double>> getAirports();
        std::vector<int> getAirportIds();
    private:
        int isNumber(std::string s);
        long double toRadians(const long double degree);
        long double distance(long double lat1, long double long1, long double lat2, long double long2);
        std::vector<std::priority_queue<psd, std::vector<psd>, std::greater<psd>>> routes;
        std::vector<std::pair<long double, long double>> airports;
        std::vector<int> airport_ids;
        std::map<int, int> id_to_index;
};