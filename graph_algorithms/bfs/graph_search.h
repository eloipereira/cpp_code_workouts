#ifndef GRAPH_SEARCH_H
#define GRAPH_SEARCH_H

#include <iostream>
#include "graph.h"

using namespace std;

template<typename T>
map<T,T> bfs(const Graph<T>& g, const T& s, bool print = false){

  map<T,T> reached_from;
  map<T,bool> visited;

  queue<T> q;
  q.push(s);
  visited[s] = true;

  while(!q.empty()){
    int current = q.front();
    q.pop();
    vector<T>& neighbours = g.at(current);
    for(auto n: neighbours){
      if(!visited[n]){
        q.push(n);
        visited[n] = true;
        if(print)
          cout << n << " visited!" << endl;
        reached_from[n] = current;
      }
    }
  }
  return reached_from;
}

template<typename T>
stack<T> shortest_path(const Graph<T>& g, const T& s, const T& d){
  map<T,T> b = bfs(g,s);
  stack<T> path;
  if (b.find(d) != b.end()){
    T prev = b[d];
    path.push(d);
    while(prev != s){
      path.push(prev);
      prev = b[prev];
    }
    path.push(s);
  }
  return path;
}


template<typename T>
map<T,T> dfs(const Graph<T>& g, const T& s, bool print = false){
  map<T,T> reached_from;
  map<T,bool> visited;

  for(auto v: g.getVertices()){
    visited[v] = false;
  }

  stack<T> st;
  st.push(s);

  while(!st.empty()){
    int current = st.top();
    st.pop();

    if(!visited[current]){
      if(print)
        cout<< current << " visited!"<<endl;
      visited[current] = true;
    }

    vector<T>& neighbours = g.at(current);
    for(auto n: neighbours){
      if(!visited[n]){
        st.push(n);
        reached_from[n] = current;
      }
    }
  }
  return reached_from;
}



#endif
