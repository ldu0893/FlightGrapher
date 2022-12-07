#include "BFS.h"
#include <map>
#include <vector>
#include <utility>
#include <iostream>

#include "globals.h"

BFS::BFS() {

}

BFS::BFS(int start, int end, int size, std::vector<std::priority_queue<psd, std::vector<psd>, std::greater<psd>>>* routes) : start(start), end(end), size(size), routes(routes) {
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
        int last = curr.back();
        if (last == end) return curr;
        queue.pop();
        std::priority_queue<psd, std::vector<psd>, std::greater<psd>> q = (*routes)[last];
        while (!q.empty()) {
            psd p = q.top();
            q.pop();
            if (visited[p.second]) continue;
            visited[p.second]=1;
            std::vector<int> tmp = curr;
            tmp.push_back(p.second);
            queue.push(tmp);
        }
    }
    return {-1};
}