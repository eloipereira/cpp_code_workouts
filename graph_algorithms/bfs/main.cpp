#include <iostream>
#include <fstream>
#include "graph.h"
#include "graph_search.h"
#include "weighted_graph.h"

using namespace std;

int main(){

  std::ifstream file0("graph0.txt");

  int s,d;
  Graph<int> graph0;
  while (file0 >> s >> d)
    graph0.add_edge(s,d);

  graph0.printGraph();
  map<int,int> result_bfs = bfs(graph0,0, true);

  stack<int> path =  shortest_path(graph0,0,5);
  while (path.size() > 0){
    cout << path.top() << " ";
    path.pop();
  }
  cout << endl;

  std::ifstream file1("graph1.txt");
  Graph<int> graph1;
  while (file1 >> s >> d)
    graph1.add_edge(s,d);
  graph1.printGraph();
  map<int,int> result_dfs = dfs(graph1,0, true);


  std::ifstream file2("graph2.txt");
  float w;
  WGraph<int,float> wgraph0;
  while (file2 >> s >> d >> w)
    wgraph0.add_edge(s,d,w);

  wgraph0.printGraph();

  int start = 0;
  auto result0 = dijkstra_shortest_path(wgraph0,start);
  std::cout << "starting at node " << start << '\n';
  for(auto p: result0.reached_from){
    std::cout << p.first << " reached from " << p.second << " with total distance of " << result0.dist[p.first] <<'\n';
  }


  WGraph<int,int> wgraph1;
  wgraph1.add_edge(0, 1, 4);
  wgraph1.add_edge(0, 7, 8);
  wgraph1.add_edge(1, 2, 8);
  wgraph1.add_edge(1, 7, 11);
  wgraph1.add_edge(2, 3, 7);
  wgraph1.add_edge(2, 8, 2);
  wgraph1.add_edge(2, 5, 4);
  wgraph1.add_edge(3, 4, 9);
  wgraph1.add_edge(3, 5, 14);
  wgraph1.add_edge(4, 5, 10);
  wgraph1.add_edge(5, 6, 2);
  wgraph1.add_edge(6, 7, 1);
  wgraph1.add_edge(6, 8, 6);
  wgraph1.add_edge(7, 8, 7);

  start = 0;
  auto result1 = dijkstra_shortest_path(wgraph1,start);
  std::cout << "starting at node " << start << '\n';
  for(auto p: result1.reached_from){
    std::cout << p.first << " reached from " << p.second << " with total distance of " << result1.dist[p.first] <<'\n';
  }

  return 0;
}
