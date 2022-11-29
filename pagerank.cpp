#include <iostream>
#include "PageRank.h"
#include <vector>
#include <numeric>
#include <math.h>


void PageRank::makeA(int num, double damping) {
    this->num = num;//store num
    //resize adj matrix
    //A.resize(num,vector<double>(num));

    //use damping factor to generate the require extra factor
    double d_factor = (1-damping)/num;

    //adjust adj matrix according to pagerank alg
    for(int i = 0; i < num; i++){
        double sum = 0;
        for(int j = 0; j < num; j++){
            sum += A[j][i];
        }     
        if(sum == 0){
            //double z = 1/this->num;
            for(int j = 0; j < num; j++){
                A[j][i] = 1/(double)num;
            }              
        } else {
            for(int j = 0; j < num; j++){
                A[j][i] = (A[j][i]/sum)*damping+d_factor;
            }             
        }
    }
}

 
//effect: print the adj matrix. column and row are labeled

void PageRank::print_adjmatrix(){
    cout<<"adj matrix"<<endl;
    cout<<"      ";
    for(int i = 0; i < this->num; i++){
        cout<<this->name_list[i];
        cout<<"           ";
    }
    cout<<"\n";
    for(int i = 0; i < this->num; i++){
        cout<<this->name_list[i];
        cout<<"  ";
        for(int j = 0; j < this->num; j++){
            cout<<this->A[i][j];
            cout<<"  ";
        } 
        cout<<"\n";
    }
    cout<<"\n";
}