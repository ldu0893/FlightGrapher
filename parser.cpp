#include "parser.h"
#include <iostream>


#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

Parser::Parser() {

}
int Parser::isNumber(string s)
{
    for (int i = 0; i < s.length(); i++){
        if (isdigit(s[i]) == false)
            return -1;
      }
    int num = stoi(s);
  return num;
}

long double Parser::toRadians(const long double degree)
{
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}
 
long double Parser::distance(long double lat1, long double long1,
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


std::map<int, std::vector<std::pair<int, long double>>> Parser::getRoutes() {
    return routes;
}

std::map<int, std::pair<long double, long double>> Parser::getAirports() {
    return airports;
}

void Parser::runParse() {


    ifstream input_file;
    input_file.open("airports.dat");
    if (input_file.good()) {
        string input;
        char cur;
        vector<string> outputStrings;
        string builtStr = "";
        while(std::getline(input_file, input)){
            int numNums=0;
            bool isNumber=true;
            for(size_t i = 0; i < input.size(); i++) {
                cur = input[i];

                if(cur == ','){
                    if(isNumber && builtStr != ""){
                        numNums++;
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

            if(!outputStrings.empty() && outputStrings.size() >= 3){
              string id = outputStrings[0];
              string lat = outputStrings[1];
              string lon = outputStrings[2];
              
              int id_id = std::stoi(id);
              double lat_id = std::stod(lat);
              double lon_id = std::stod(lon);
              airports[id_id] = pair<double, double>(lat_id, lon_id);
            }
              
      
            outputStrings.clear();
            builtStr = "";
        }
    } else {
        cout << "error filename" << endl;
    }

    input_file.close();


    //routes
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
        int numNums=0;
        for(size_t i = 0; i < input.size(); i++) {
          cur = input[i];


          if(!isQuote){
            if(cur == ','){
              if(builtStr != "") {
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
      if(!outputStrings.empty() && outputStrings.size() >= 6){
        string depart = outputStrings[3];
        string destination = outputStrings[5];
        
        int depart_id = isNumber(depart);
        int destination_id = isNumber(destination);
         // mp[depart].push_back({destination, 0});
        if(depart_id != -1 && destination_id != -1){
            //routes[depart_id].push_back({destination_id, distance(0, 0, 0, 0)});
            routes[depart_id].push_back({destination_id,distance(airports[depart_id].first,airports[depart_id].second,airports[destination_id].first,airports[destination_id].second)});
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
    } 
    else {
        cout << "error filename" << endl;
    }
    input_file.close();

    std::cout << "done parsing" << std::endl;
}

