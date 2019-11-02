#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

template<typename T0, typename T1>
std::vector<T0> get_keys(const std::map<T0,T1> & m);

template<typename T>
class Graph{

public:
  struct Edge {
    T src, dest;
  };
  Graph();
  Graph(std::vector<Edge> const &edges);
  ~Graph();
  int size;
  void add_edge(T s, T d);
  void printGraph();
  int getNumVertices() const;
  std::vector<T> getVertices() const;
  std::vector<T> & at(T n) const;
private:
  std::map<T,std::vector<T>>* adjList;
};

template<typename T0, typename T1>
std::vector<T0> get_keys(const std::map<T0,T1> & m){
  std::vector<T0> result;
  typename std::map<T0,T1>::iterator it;
  for(auto const& e: m){
    result.push_back(e.first);
  }
  return result;
};


template<typename T>
Graph<T>::Graph(){
  adjList = new std::map<T,std::vector<T>>();
  size = 0;
};

template<typename T>
Graph<T>::Graph(std::vector<Edge> const &edges){
  adjList = new std::map<T,std::vector<T>>();
  for (auto edge: edges){
    (*adjList)[edge.src].push_back(edge.dest);
    size = size + 1;
    // Uncomment below line for undirected graph
    // adjList[edge.dest].push_back(edge.src);
  }
};

template<typename T>
Graph<T>::~Graph(){
  //std::cout << "Deleting graph..." << std::endl;
  delete adjList;
};

template<typename T>
void Graph<T>::add_edge(T s, T d){
  (*adjList)[s].push_back(d);
};

template<typename T>
int Graph<T>::getNumVertices() const{
  return size;
};

template<typename T>
std::vector<T> Graph<T>::getVertices() const{
  return get_keys(*adjList);
};

template<typename T>
std::vector<T> & Graph<T>::at(T n) const{
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
