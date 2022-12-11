# FlightGrapher

CS 225 Final Project

## Introduction

Our final project utilizes the airports and routes data to construct maps and matrixes.
We implement Dijkstra to find the shortest path between airports depending on the 
distance. We also implment pagerank algorithm to find the most pupular airports.

## Github Organization
These files contain different functions for different implementations. Function descriptions
can be found in the individual files.

Parser: Constructing a graph given the airport and routes data
BFS: Implementation of BFS traversal on the graph
Pagerank: Implementation of pagerank algorithm to find the most popular airports
Dijkstra: Implementation of diskstra algorithm to find the shortest path between airports
Main: Multiple test cases for bfs, dijkstra's and pagerank algorithm
routes*.dat: Data holding routes between airports
airports*.dat: Data holding airports and coordinates

## Running Instructions
This program can be compiled using (g++ -o main \*.cpp) in the terminal.
This program can be run by using (./main) or (./main.exe) in the terminal.

=The output data is output to the console.
Various test cases descirptions are in the main.cpp file
