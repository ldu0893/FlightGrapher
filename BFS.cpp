#include "BFS.h"

BFS::BFS() {

}

BFS::BFS(int start, int end, int size, std::map<int, std::vector<std::pair<int, long double>>* mp) : start(start), end(end), size(size), mp(mp) {
    visited = std::vector<int>(size);
    queue.push(start);
    visited[start]=1;
}

BFS::clear() {
    queue.clear();
    visited.clear();
    dist = 0;
    size = 0;
    mp = NULL;
}

BFS::run() {
    while (!queue.empty()) {
        int curr = queue.top();
        queue.pop();
        for (std::pair<int, long double> p : *mp[curr]) {
            if (visited[p.first]) continue;
            visited[p.first]=1;
        }
    }
}