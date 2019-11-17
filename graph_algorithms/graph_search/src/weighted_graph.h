#ifndef WGRAPH_H
#define WGRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <type_traits>
#include "graph.h"
#include "utils.h"

template<typename T, typename W>
class WGraph: public Graph<T>{
  static_assert(std::is_arithmetic<W>::value, "Weights type must be numeric.");
public:
  WGraph();
  ~WGraph();
  int size;
  void add_edge(T s, T d, W w);
  void printGraph();
  int getNumVertices() const;
  std::vector<T>& getVertices() const;
  std::vector<T>& at(T n) const;
  W getWeight(T s, T d) const;
private:
  std::map<T,std::vector<T>>* adjList;
  std::map<std::pair<T,T>,W>* weights;
  std::vector<T>* vertices;
};

template<typename T, typename W>
WGraph<T,W>::WGraph(){
  adjList = new std::map<T,std::vector<T>>();
  weights = new std::map<std::pair<T,T>,W>();
  vertices = new std::vector<T>();
  size = 0;
};

template<typename T, typename W>
WGraph<T,W>::~WGraph(){
  delete adjList;
  delete weights;
  delete vertices;
};

template<typename T, typename W>
void WGraph<T,W>::add_edge(T s, T d, W w){
  if (std::find(vertices->begin(), vertices->end(), s) == vertices->end()){
    vertices->push_back(s);
    size = size + 1;
  }
  if (std::find(vertices->begin(), vertices->end(), d) == vertices->end()){
    vertices->push_back(d);
    size = size + 1;
  }
  (*adjList)[s].push_back(d);
  (*weights)[std::make_pair(s,d)]=w;
};

template<typename T, typename W>
int WGraph<T,W>::getNumVertices() const{
  return size;
};

template<typename T, typename W>
std::vector<T>& WGraph<T,W>::getVertices() const{
  return (*vertices);
};

template<typename T, typename W>
std::vector<T>& WGraph<T,W>::at(T n) const{
  return (*adjList)[n];
}

template<typename T, typename W>
void WGraph<T,W>::printGraph(){
  int N = getNumVertices();
  for (auto i: *adjList){
    for (auto v : i.second){
      std::cout << i.first << " --> " << v << ", (" << weights->at(std::make_pair(i.first,v)) << ")" << std::endl;
    }
  }
};

template<typename T,typename W>
W WGraph<T,W>::getWeight(T s, T d) const{
  return (*weights)[std::make_pair(s,d)];
};

#endif
