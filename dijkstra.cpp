#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include<map>
#include <float.h>
#include "globals.h"

#include "dijkstra.h"

Dijkstra::Dijkstra(int airport_num, std::vector<std::priority_queue<psd, vector<psd>, std::greater<psd>>>* routes) :
    airport_num(airport_num),
    routes(routes),
    visited(airport_num, false),
    distance(airport_num, DBL_MAX),
    parent(airport_num)
{

}

void Dijkstra::reset() {
    visited = std::vector<bool>(airport_num, false);
    distance = std::vector<long double>(airport_num, DBL_MAX);
    parent = std::vector<int>(airport_num);
    candidate = std::queue<int>();
}


std::vector<int> Dijkstra::run() {
    cout << "map_size : " << (*routes).size() << endl;    //input map
    size_t start, end;
   
    cout << "select start from 0 ~ " << (*routes).size() -1 << endl;
    cin >> start;
    while(start < 0 || start >= (*routes).size()){
        cout << "incorrect input for start" << endl;
        cout << "select start from 0 ~ " << (*routes).size() -1 << endl;
        cin >> start;
    }     //select start point
   
  
    cout << "select end from 0 ~ " << (*routes).size() -1 << endl;
    cin >> end;
    while(end < 0 || end >= (*routes).size()){
        cout << "incorrect input for end" << endl;
        cout << "select end from 0 ~ " << (*routes).size() -1 << endl;
        cin >> end;
    }    //select end point

    visited[start] = true;
    distance[start] = 0;
    parent[start] = -1;
    candidate.push(start);
    //initialize start 
    
    while (!candidate.empty()) {
        std::queue<int> tmp = candidate;
        std::cout << "Current queue: ";
        while (!tmp.empty()) {
            std::cout << tmp.front() << " ";
            tmp.pop();
        }
        std::cout << std::endl;
        // int now = candidate.front();
        // candidate.pop();
        int now = findmin(distance, candidate);
        remove(now,candidate);
        visited[now] = true;
        bool first = true;
        while (!(*routes)[now].empty()) {
            auto p = (*routes)[now].top();
            if (!visited[p.second]) {
                if (first) {
                    candidate.push(p.second);
                    first = false;
                } 
                cout << now << " : " << p.first << ", " << p.second << endl;
                int now_d = p.first + distance[now];
                if (distance[p.second] > now_d) { // relax
                    parent[p.second] = now;
                    distance[p.second] = now_d;
                }
            }
            (*routes)[now].pop();
        }
    }
    if (distance[end] == DBL_MAX) {
        cout << "cannot reach " << end <<" from " << start << endl;
    } else {
        std::vector<int> path;
        printf("start from %zu to %zu, distance %Lg\n", start, end, distance[end]);
        printf("Path :  ");
        while (parent[end] != -1) {
            path.push_back((int)end);
            cout << end << " <-- ";
            end = parent[end];
        }
        cout << start;
        return path;
    }
    return {-1};

}

void Dijkstra::remove(int t, queue<int>& q)
{
 
    // Helper queue to store the elements
    // temporarily.
    queue<int> ref;
    int s = q.size();
    int cnt = 0;
 
    // Finding the value to be removed
    while (q.front() != t && !q.empty()) {
        ref.push(q.front());
        q.pop();
        cnt++;
    }
 
    // If element is not found
    if (q.empty()) {
        cout << "element not found!!" << endl;
        while (!ref.empty()) {
 
            // Pushing all the elements back into q
            q.push(ref.front());
            ref.pop();
        }
    }
 
    // If element is found
    else {
        q.pop();
        while (!ref.empty()) {
 
            // Pushing all the elements back into q
            q.push(ref.front());
            ref.pop();
        }
        int k = s - cnt - 1;
        while (k--) {
 
            // Pushing elements from front of q to its back
            int p = q.front();
            q.pop();
            q.push(p);
        }
    }
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