#include "parser.h"
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


map <int, vector<pair<int, long double> > > mp;
int main() {
    //map <string, vector<pair<string, double> > > mp;
  // map <int, vector<pair<int, double> > > mp;
    ifstream input_file;
    input_file.open("routes.dat");
    if (input_file.good()) {
        string input;
        char cur;
        bool isQuote = false;
        vector<string> outputStrings;
        string builtStr = "";
        // while(input_file >> input){



      // for(int i = 0; i<20; i++){
      //   input_file >> input;
      while(input_file >> input){
        for(size_t i = 0; i < input.size(); i++){
          cur = input[i];


          if(!isQuote){
            if(cur == ','){
              if(builtStr != ""){
                outputStrings.push_back(builtStr);
              }
              builtStr = string();
            }
            else if(cur == '"'){
              isQuote = true;
            }
            if(cur != ','){
              builtStr += cur;
            }
          } 
        }
      //testing 
      // for(size_t i = 0; i < outputStrings.size(); i++){
      //   cout << outputStrings[i] << endl;
      // }
        //testing
      // cout << "NEXT_LINE" << endl;
      if(!outputStrings.empty()){
        string depart = outputStrings[3];
        string destination = outputStrings[5];
        
        int depart_id = isNumber(depart);
        int destination_id = isNumber(destination);
         // mp[depart].push_back({destination, 0});
        if(depart_id != -1 && destination_id != -1){
    mp[depart_id].push_back({destination_id,distance(0,0,0,0)});
        }
        
      }
      
      outputStrings.clear();
      builtStr = "";
      isQuote = false;
    } 

      //testing
    //string ss = "2965";
    // for(auto p:mp[ss]){
    //   cout<<p.first << "," << p.second << endl;
    // }
     for(auto p:mp[2965]){
       cout<<p.first << "," << p.second << endl;
     }   
          
        
    } 
    else {
        cout << "error filename" << endl;
    }
    input_file.close();
    return 0;
}
