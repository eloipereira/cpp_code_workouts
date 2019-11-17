#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include "utils.h"

template<typename T>
class Graph{
public:
  Graph();
  ~Graph();
  int size;
  void add_edge(T s, T d);
  void printGraph();
  int getNumVertices() const;
  std::vector<T>& getVertices() const;
  std::vector<T>& at(T n) const;
private:
  std::map<T,std::vector<T>>* adjList;
  std::vector<T>* vertices;
};


template<typename T>
Graph<T>::Graph(){
  adjList = new std::map<T,std::vector<T>>();
  vertices = new std::vector<T>();
  size = 0;
};


template<typename T>
Graph<T>::~Graph(){
  //std::cout << "Deleting graph..." << std::endl;
  delete adjList;
  delete vertices;
};

template<typename T>
void Graph<T>::add_edge(T s, T d){
  if (std::find(vertices->begin(), vertices->end(), s) == vertices->end()){
    vertices->push_back(s);
    size = size + 1;
  }
  if (std::find(vertices->begin(), vertices->end(), d) == vertices->end()){
    vertices->push_back(d);
    size = size + 1;
  }
  (*adjList)[s].push_back(d);
};

template<typename T>
int Graph<T>::getNumVertices() const{
  return size;
};

template<typename T>
std::vector<T>& Graph<T>::getVertices() const{
  return (*vertices);
};

template<typename T>
std::vector<T>& Graph<T>::at(T n) const{
  return (*adjList)[n];
}

template<typename T>
void Graph<T>::printGraph(){
  int N = getNumVertices();
  for (auto i: *adjList){
    std::cout << i.first << " --> ";
    for (auto v : i.second)
      std::cout << v << " ";
    std::cout << std::endl;
  }
};


#endif
