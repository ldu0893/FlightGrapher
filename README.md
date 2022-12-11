# FlightGrapher

CS 225 Final Project

## Introduction

Our final project utilizes the airports and routes data to construct maps and matrixes
We implement Dijkstra to find the shortest path between airports depending on the 
distance. Besides, we also implment pagerank algorithmto find the most pupular airports.

File desciption(code and data):
These files contain different functions for different implementations. Function descriptions
can be found in the individual files.

Parser: Constructing a graph given the airport and routes data
BFS: Implementation of BFS traversal on the graph
Pagerank: Implementation of pagerank algorithm to find the most popular airport
Dijkstra: Implementation of diskstra algorithm to find the shortest path between airports
Main: Multiple test cases for bfs,dijstra and pagerank algorithm
Routes--: A smaller size of routes that is used for smalleer test cases
Airports: A smaller size of aiports that is used for smaller test cases

Reports

Presentation video

Running Instructions:
This program can be build by using (g++ -o main *.cpp) in the main.cpp terminal.
This program can be run by using (./main) in the main.cpp terminal.

Input data are predetermined and can be accessed when running the program. 
The output data is output to the console.
Various test cases descirptions are in the main.cpp file