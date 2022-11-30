#include "BFS.h"
#include <map>
#include <vector>
#include <utility>
#include <iostream>

#include "globals.h"

BFS::BFS() {

}

BFS::BFS(int start, int end, int size, std::map<int, std::vector<std::pair<int, long double>>>* routes) : start(start), end(end), size(size), routes(routes) {
    visited = std::vector<int>(size);
    queue.push({start});
    visited[start]=1;
}

void BFS::clear() {
    queue = std::queue<std::vector<int>>();
    visited.clear();
    dist = 0;
    size = 0;
    start = 0;
    end = 0;
    routes = NULL;
}

std::vector<int> BFS::run() {
    while (!queue.empty()) {
        std::vector<int> curr = queue.front();
        if (DEBUG) for (int q : curr) std::cout << q << " ";
        if (DEBUG) std::cout << std::endl;
        int last = curr.back();
        if (last == end) return curr;
        queue.pop();
        for (std::pair<int, long double> p : (*routes)[last]) {
            if (visited[p.first]) continue;
            visited[p.first]=1;
            std::vector<int> tmp = curr;
            tmp.push_back(p.first);
            queue.push(tmp);
        }
    }
    return std::vector<int>();
}