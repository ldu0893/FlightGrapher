#pragma once
#include <queue>
#include <string>
#include <map>

class BFS {
    public:
        BFS();
        BFS(int start, int end, int size, std::map<int, std::vector<std::pair<int, long double>>>* routes);
        void clear();
        std::vector<int> run();
    private:
        std::queue<std::vector<int>> queue;
        int start;
        int end;
        int size;
        int dist;
        std::vector<int> visited;
        std::map<int, std::vector<std::pair<int, long double>>>* routes;
};