#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include<map>

#include "dijkstra.h"

Dijkstra::Dijkstra(int airport_num) : airport_num(airport_num) {

    mp[3].push({2, 1});
    mp[3].push({6, 2});
    mp[1].push({5, 0});
    mp[1].push({9, 2});
    mp[2].push({8, 0});
    mp[0].push({});
    cout << "map_size : " << mp.size() << endl;    //input map
    
    

   int start, end;
   
  cout << "select start from 0 ~ " << mp.size() -1 << endl;
   cin >> start;
   while(start < 0 || start >= mp.size()){
     cout << "incorrect input for start" << endl;
     cout << "select start from 0 ~ " << mp.size() -1 << endl;
     cin >> start;
   }     //select start point
   
  
  cout << "select end from 0 ~ " << mp.size() -1 << endl;
   cin >> end;
   while(end < 0 || end >= mp.size()){
     cout << "incorrect input for end" << endl;
     cout << "select end from 0 ~ " << mp.size() -1 << endl;
     cin >> end;
    }    //select end point

  
    vector <bool> vistied(mp.size(), false);
    vector <double> distance(mp.size(), 1e10);
    vector <int> parent(mp.size());
    queue <int> candidate;
    queue <int> tmp;
    
    //initialize
  
    vistied[start] = true;
    distance[start] = 0;
    parent[start] = -1;
    candidate.push(start);
    //initialize start 
    
     while (!candidate.empty()) {
        // int now = candidate.front();
        // candidate.pop();
       int now = findmin(distance, candidate);
       remove(now,candidate);
        vistied[now] = true;
        bool first = true;
        while (!mp[now].empty()) {
            auto p = mp[now].top();
            if (!vistied[p.second]) {
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
            mp[now].pop();
        }
    }
    if(distance[end] == 1e10){
      cout << "cannot reach " << end <<" from " << start << endl;
    }
   else{
    printf("start from %d to %d, distance %g\n", start, end, distance[end]);
    printf("Path :  ");
    while (parent[end] != -1) {
        cout << end << " <-- ";
        end = parent[end];
    }
    cout << start;
     }

}

void Dijkstra::remove(int t, queue<int>& q)
{
 
    // Helper queue to store the elements
    // temporarily.
    queue<int> ref;
    int s = q.size();
    int cnt = 0;
 
    // Finding the value to be removed
    while (q.front() != t and !q.empty()) {
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

int Dijkstra::findmin(vector<double> v, queue<int> q ){
    queue<int> qtmp = q;
    vector<double> vtmp = v;
    double min_val = 1e10;
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

int main()
{
    }