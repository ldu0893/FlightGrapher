#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include<map>
#include <float.h>
#include "globals.h"

#include "dijkstra.h"

Dijkstra::Dijkstra(int airport_num, std::vector<std::priority_queue<psd, vector<psd>, std::greater<psd>>> routes) :
    airport_num(airport_num),
    visited(airport_num, false),
    distance(airport_num, DBL_MAX),
    parent(airport_num)
{
    legacy = routes;
    this->routes = &legacy;
}
Dijkstra::Dijkstra(int start, int end, int airport_num, std::vector<std::priority_queue<psd, vector<psd>, std::greater<psd>>> routes) :
    start(start),
    end(end),
    airport_num(airport_num),
    visited(airport_num, false),
    distance(airport_num, DBL_MAX),
    parent(airport_num)
{
    legacy = routes;
    this->routes = &legacy;
}
void Dijkstra::reset() {
    visited = std::vector<bool>(airport_num, false);
    distance = std::vector<long double>(airport_num, DBL_MAX);
    parent = std::vector<int>(airport_num);
    candidate = std::priority_queue<psd, vector<psd>, greater<psd>>();
}


std::vector<int> Dijkstra::run() {
    visited[start] = true;
    distance[start] = 0;
    parent[start] = -1;
    for (int i=0;i<airport_num;i++) {
        candidate.push({distance[i], i});
    }
    candidate.push({0, start});
    //initialize start 


    
    while (!candidate.empty()) {
        std::priority_queue<psd, vector<psd>, greater<psd>> tmp = candidate;
        //std::cout << "Current queue: ";
        //while (!tmp.empty()) {
        //    psd q = tmp.top();
        //    std::cout << q.second << " ";
        //    tmp.pop();
        //}
        //std::cout << std::endl;
        // int now = candidate.front();
        // candidate.pop();
        int now = candidate.top().second;
        if (now == end) break;
        candidate.pop();
        visited[now] = true;
        while (!(*routes)[now].empty()) {
            auto p = (*routes)[now].top();
            if (!visited[p.second]) {
                long double alt = distance[now] + p.first;
                if (alt < distance[p.second]) {
                    distance[p.second] = alt;
                    parent[p.second] = now;
                    update(p.second, alt);
                }
                //cout << now << " : " << p.first << ", " << p.second << endl;
            }
            (*routes)[now].pop();
        }
    }
    if (distance[end] == DBL_MAX) {
        return {-1};
        cout << "cannot reach " << end <<" from " << start << endl;
    } else {
        std::vector<int> path;
        printf("Total distance: %Lg\n", distance[end]);
        //printf("start from %zu to %zu, distance %Lg\n", start, end, distance[end]);
        //printf("Path :  ");
        while (parent[end] != -1) {
            path.push_back((int)end);
            //cout << end << " <-- ";
            end = parent[end];
        }
        path.push_back(start);
        //cout << start;
        return path;
    }
    return {-1};

}

void Dijkstra::update(int a, long double alt) {
    priority_queue<psd, vector<psd>, greater<psd>> tmp;
    while (!candidate.empty()) {
        psd q = candidate.top();
        candidate.pop();
        if (q.second == a) tmp.push({alt, a});
        else tmp.push(q);
    }
    
    candidate = tmp;
}

int Dijkstra::findmin(vector<long double> v, queue<int> q ){
    queue<int> qtmp = q;
    vector<long double> vtmp = v;
    double min_val = DBL_MAX;
    int min_idx = -1;
    
    while(!qtmp.empty()){
        int idx = qtmp.front();
        if(min_val > vtmp[idx]){
            min_val = vtmp[idx];
            min_idx = idx;
        }
        qtmp.pop();
    }
    
    return min_idx;
}