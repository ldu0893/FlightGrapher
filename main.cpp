#include "parser.h"
#include <iostream>


#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
// #include <bits/stdc++.h>
#include <cmath>
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


map <int, vector<pair<int, long double> > > mp;
vector<std::pair<double, double> > airports;
int main() {
    //map <string, vector<pair<string, double> > > mp;
  // map <int, vector<pair<int, double> > > mp;
    ifstream input_file;
    input_file.open("airports.dat");
    if (input_file.good()) {
        string input;
        char cur;
        bool isQuote = false;
        vector<string> outputStrings;
        string builtStr = "";
        // while(input_file >> input){



      // for(int i = 0; i<20; i++){
      //   input_file >> input;
      while(std::getline(input_file, input)){
        bool isNumber=true;
        for(size_t i = 0; i < input.size(); i++){
            cur = input[i];

            if(cur == ','){
              if(isNumber && builtStr != ""){
                outputStrings.push_back(builtStr);
              }
                isNumber=true;
              builtStr = string();
            }
            else {
                if(!isdigit(cur) && cur!='-' && cur!='.') isNumber=false;
              builtStr += cur;
            }
        }
      //testing 
      // for(size_t i = 0; i < outputStrings.size(); i++){
      //   cout << outputStrings[i] << endl;
      // }
        //testing
      // cout << "NEXT_LINE" << endl;
      if(!outputStrings.empty()){
        string id = outputStrings[0];
        string lat = outputStrings[1];
        string lon = outputStrings[2];
        
        cout << id << " " << lat << " " << lon <<endl;
        int id_id = std::stoi(id);
        double lat_id = std::stod(lat);
        double lon_id = std::stod(lon);
        airports.push_back(pair<double, double>(lat_id, lon_id));
        }
        
      
      outputStrings.clear();
      builtStr = "";

      //testing
    //string ss = "2965";
    // for(auto p:mp[ss]){
    //   cout<<p.first << "," << p.second << endl;
    // }
          
      }
    } 
    else {
        cout << "error filename" << endl;
    }

    for (int i=0;i<100;i++) {
        //cout << airports[i].first << " " << airports[i].second << endl;
    }
    input_file.close();
    return 0;
}