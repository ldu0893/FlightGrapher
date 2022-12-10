#include "parser.h"
#include "globals.h"
#include "BFS.h"
#include "dijkstra.h"
#include "PageRank.h"
#include <iostream>


#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int isNumber(string s)
{
    for (size_t i = 0; i < s.length(); i++){
        if (isdigit(s[i]) == false)
            return -1;
      }
    int num = stoi(s);
  return num;
}

long double toRadians(const long double degree)
{
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}
 
long double distance(long double lat1, long double long1,
                     long double lat2, long double long2)
{
    // Convert the latitudes
    // and longitudes
    // from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
     
    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
 
    long double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
 
    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 6371;
     
    // Calculate the result
    ans = ans * R;
 
    return ans;
}

void normMatrixCols(std::vector<std::vector<double>>& matrix) {
  for (size_t j=0;j<matrix[0].size();j++) {
    int sum=0;
    for (size_t i=0;i<matrix.size();i++) {
      sum+=matrix[i][j];
    }
    for (size_t i=0;i<matrix.size();i++) {
      matrix[i][j]/=sum;
    }
  }
}


//std::vector<std::vector<double>> createAdjMatrix(std::>* routes, std::map<int, std::pair<long double, long double>>* airports) {
std::vector<std::vector<double>> createAdjMatrix(std::vector <priority_queue<psd, vector<psd>, greater<psd>>>* routes, std::vector<std::pair<long double, long double>>* airports) {
  std::vector<std::vector<double>> matrix = std::vector<std::vector<double>>(airports->size(), std::vector<double>(airports->size()));
  for (int i=0;i<routes->size();i++) {
    std::priority_queue<psd, std::vector<psd>, std::greater<psd>> queue = (*routes)[i];
    while (!queue.empty()) {
      psd p = queue.top();
      queue.pop();

      matrix[p.second][i] = (double) p.first;
    }
  }
  return matrix;
}
std::vector <priority_queue<psd, vector<psd>, greater<psd>>> routes;
std::vector<std::pair<long double, long double>> airports;
std::vector<int> airport_ids;

int main() {
  std::cout << "main" << std::endl;
  Parser p;
  p.runParse();
  routes = p.getRoutes();
  airports = p.getAirports();
  airport_ids = p.getAirportIds();
  std::cout << "end" << std::endl;
  //for (std::pair<double, double> q : airports) {
    //std::cout << q.first << " " << q.second << std::endl;
  //}
  std::cout << std::endl << "Parse testing" << std::endl;
  //std::cout << airports[7].first << " " << airports[7].second << std::endl;
  //std::cout << routes[1].top().first << " " << routes[1].top().second << std::endl;
  //std::cout << airport_ids[2965] << " " << routes[2965].top().first << " " << airport_ids[routes[2965].top().second] << std::endl;
  //std::cout << routes[3077].size() << std::endl;
  std::cout << std::endl;



  std::cout << "BFS testing" << std::endl;
  //BFS testing
  BFS bfs(300, 600, routes.size(), &routes);
  std::cout << airport_ids[300] << " " << airport_ids[600] << std::endl;
  std::cout << "inited bfs" << std::endl;
  std::vector<int> path = bfs.run();
  for (int q : path) std::cout << airport_ids[q] << " ";
  std::cout << std::endl << std::endl;


  std::cout << "Dijkstras testing" << std::endl;
  std::cout << airport_ids[1] << std::endl;
  Dijkstra dijkstra(routes.size(), routes);
  std::vector<int> pat = dijkstra.run();
  for (int q : pat) {
    std::cout << airport_ids[q] << " ";
  }
  std::cout << std::endl << std::endl << std::endl;



  std::cout << "num out from 0 " << routes[0].size() << std::endl;
  std::cout << "num out fro 1 " << routes[1].size() << std::endl;

  std::cout << "PageRank testing" << std::endl;
  std::vector<std::vector<double>> adj = createAdjMatrix(&routes, &airports);
  //for (int i=0;i<adj.size();i++) {
  //  for (int j=0;j<adj.size();j++) {
  //    std::cout << adj[i][j] << " ";
  //  }
  //  std::cout << std::endl;
  //}
  PageRank pagerank(adj);
  pagerank.matrix(adj.size(), 0.85);
  vector<double> ranks;

  cout << "gen rank" << endl;
  vector<double> re = pagerank.rank(ranks, 100);

  cout << re[0] << endl;

  int count=0;
  double dmax = DBL_MAX;
  priority_queue<psd> pqueue;

  for (int i=0;i<re.size();i++) {
    pqueue.push({re[i], i});
  }

  std::cout << "print airport" << std::endl;
  int cut = 0;
  while (!pqueue.empty() && cut < 30) {
    cut++;
    psd p = pqueue.top();
    pqueue.pop();
    std::cout << airport_ids[p.second] << "      " << p.first << std::endl;
  }



  
}