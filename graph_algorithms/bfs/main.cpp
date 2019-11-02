#include <iostream>
#include <fstream>
#include "graph.h"
#include "graph_search.h"

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

  return 0;
}
