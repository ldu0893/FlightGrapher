#pragma once

#include <vector>
using namespace std;


//pagerank class
class PageRank
{
  public:
    PageRank();

    //adjust adj matrix
    void makeA(int num, double damping);

    //print adjmatrix
    void print_adjmatrix();

    //the adj matrix variable, for pagerank
    vector<vector<double>> A; 

    //the namelist of the airport. contains the airport id
    vector<int> name_list; 

    //dimension of the adj matrix, namelist, initial vector and result vector
    int num;
};