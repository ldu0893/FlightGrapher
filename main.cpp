#include "parser.h"
#include <iostream>

#include <windows.h>
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

map <int, vector<pair<string,pair<double,double>>>>mp;
int main() {
    //map <string, vector<pair<string, double> > > mp;
  // map <int, vector<pair<int, double> > > mp;
  SetConsoleOutputCP(CP_UTF8);

    ifstream input_file;
    input_file.open("airports.dat");
    if (input_file.good()) {
        string input;
        char cur;
        string stringz;
        bool isQuote = false;
        vector<string> outputStrings;
        string builtStr = "";
        // while(input_file >> input){



      // for(int i = 0; i<20; i++){
      //   input_file >> input;
      int counter=0;

      while(getline(input_file,input)){
        counter++;
        // stringz='αβγδεζηθιξλμνξοπρστυφχψω';
        //cout<<counter<<endl;
        //cout<<"ð"<<endl;
        //stringz="ð";
        //cout<<"ð"<<endl;
        // cout<<stringz<<endl;
        for(size_t i = 0; i < input.size(); i++){
          cur = input[i];


          if(!isQuote){
            if(cur == ','){
              //if(builtStr != ""){
                outputStrings.push_back(builtStr);
              //}
              builtStr = string();
            }
            else if(cur == '"'){
              isQuote = true;

            }
            else if(cur != ','){
              builtStr += cur;
            }
          }
          else{
            if(cur == '"'&& i +1 <input.size() ){
              if(input[i+1]=='"'){
                builtStr += '"';
                ++i;
              }
              else{
                isQuote = false;
              }
            }
            else{
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
        string index = outputStrings[0];
        string airport= outputStrings[1];
        string latitude = outputStrings[6];
        string longitude=outputStrings[7];
        int index_id = isNumber(index);
        double latitude_id = stod(latitude);
        double longitude_id = stod(longitude);

         // mp[depart].push_back({destination, 0});
        if(index_id != -1){
    //mp[index_id].push_back({airport,latitude_id,longlitude_id});
    mp[index_id].push_back(pair(airport, pair(latitude_id, longitude_id)));
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
    
     for(auto p:mp[12]){
       cout<<p.first << "," << p.second.first <<","<<p.second.second<< endl;
     }   
          
        
    } 
    else {
        cout << "error filename" << endl;
    }
    input_file.close();
    return 0;
}