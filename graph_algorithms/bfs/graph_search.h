#ifndef GRAPH_SEARCH_H
#define GRAPH_SEARCH_H

#include <iostream>
#include <limits>
#include "graph.h"
#include "weighted_graph.h"

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

template<typename T, typename W>
struct dijkstra_result{
  map<T,T> reached_from;
  map<T,W> dist;
};

template<typename T, typename W>
dijkstra_result<T,W> dijkstra_shortest_path(const WGraph<T,W>& wg, T s){
  W max_val = std::numeric_limits<W>::max();
  map<T,T> reached_from;
  priority_queue<pair<T,T>, vector<pair<T,T>>, greater<pair<T,T>>> pq;
  pq.push(make_pair(0,s));
  map<T,W> dist;
  dist[s] = 0;
  for(auto v: wg.getVertices()){
    if (v != s)
      dist[v] = max_val;
    pq.push(make_pair(dist[v],v));
  }

  while (!pq.empty()) {
    T u = pq.top().second;
    pq.pop();
    for(auto v: wg.at(u)){
      W alt = dist[u] + wg.getWeight(u,v);
      if (alt < dist[v]){
        dist[v] = alt;
        reached_from[v] = u;
        pq.push(make_pair(dist[v],v));
      }
    }
  }

  return {reached_from,dist};
}

#endif
