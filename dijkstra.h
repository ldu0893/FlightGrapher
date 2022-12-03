#include <queue>
#include <vector>
#include <map>

typedef std::pair<double, int> psd;

class Dijkstra {
    public:
        Dijkstra();
    private:
        void remove(int t, std::queue<int>& q);
        int findmin(std::vector<double> v, std::queue<int> q);

        int airport_num;
        std::map <int, std::priority_queue<psd , vector<psd>, std::greater<psd>> > mp;
};