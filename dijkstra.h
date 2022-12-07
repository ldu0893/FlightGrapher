#include <queue>
#include <vector>
#include <map>
#include "globals.h"

class Dijkstra {
    public:
        Dijkstra();
        Dijkstra(int airport_num, std::vector<std::priority_queue<psd , std::vector<psd>, std::greater<psd>>>* routes);
        std::vector<int> run();
        void reset();
    private:
        void remove(int t, std::queue<int>& q);
        int findmin(std::vector<long double> v, std::queue<int> q);

        int airport_num;
        std::vector<std::priority_queue<psd, std::vector<psd>, std::greater<psd>>>* routes;
        std::vector<bool> visited;
        std::vector<long double> distance;
        std::vector<int> parent;
        std::queue<int> candidate;
};