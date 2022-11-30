#include "parser.h"
#include "BFS.h"
#include <iostream>


#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int isNumber(string s)
{
    for (int i = 0; i < s.length(); i++){
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
#define SIZE 14110
std::vector<std::vector<int>> createAdjMatrix(std::map<int, std::vector<std::pair<int, long double>>>* routes, std::map<int, std::pair<long double, long double>>* airports) {
  std::vector<std::vector<int>> matrix = std::vector<std::vector<int>>(SIZE, std::vector<int>(SIZE));
  for (std::map<int, std::vector<pair<int, long double>>>::iterator it = routes->begin(); it!=routes->end();it++) {
    for  (std::pair<int, long double> p : it->second) {
      matrix[it->first][p.first] = 1;
    }
  }
  return matrix;
}


map <int, vector<pair<int, long double> > > routes;
std::map<int, std::pair<long double, long double>> airports;
int main() {
  std::cout << "main" << std::endl;
  Parser p;
  p.runParse();
  routes = p.getRoutes();
  airports = p.getAirports();
  std::cout << "end" << std::endl;
  //for (std::pair<double, double> q : airports) {
    //std::cout << q.first << " " << q.second << std::endl;
  //}
  std::cout << std::endl << "Parse testing" << std::endl;
  std::cout << airports[7].first << " " << airports[7].second << std::endl;
  std::cout << routes[1][0].first << " " << routes[1][0].second << std::endl;
  std::cout << routes[2965][0].first << " " << routes[2965][0].second << std::endl;
  std::cout << std::endl;



  std::cout << "BFS testing" << std::endl;
  //BFS testing
  BFS bfs(1, 11051, 14110, &routes);
  std::vector<int> path = bfs.run();
  for (int q : path) std::cout << q << " ";
  std::cout << std::endl << std::endl;


  std::cout << "PageRank testing" << std::endl;
  std::vector<std::vector<int>> adj = createAdjMatrix(&routes, &airports);
  std::cout << adj[2927][1] << std::endl;

}