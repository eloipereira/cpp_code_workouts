#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Edge {
  int src, dest;
};


class Graph{
public:
  vector<vector<int>> adjList;
  Graph(vector<Edge> const &edges, int N);
  void printGraph();
  int getNumVertices();
  vector<int> bfs(int s);
};


Graph::Graph(vector<Edge> const &edges, int N){		
  adjList.resize(N);
  for (auto edge: edges){
    adjList[edge.src].push_back(edge.dest);
    // Uncomment below line for undirected graph
    // adjList[edge.dest].push_back(edge.src);
  }
}

int Graph::getNumVertices(){
  return adjList.size();
}

void Graph::printGraph(){
  int N = getNumVertices();
  for (int i = 0; i < N; i++){
    cout << i << " --> ";
    for (int v : adjList[i])
      cout << v << " ";
    cout << endl;
  }
}

vector<int> Graph::bfs(int s){
  
  int N = getNumVertices();
  vector<int> reached_from(N,-1);
  vector<bool> visited(N,false);

  queue<int> q;
  q.push(s);
  visited[s] = true;
  
  while(!q.empty()){
    int current = q.front();
    q.pop();
    vector<int> neighbours = adjList[current];
    for(auto n: neighbours){
      if(!visited[n]){
	q.push(n);
	visited[n] = true;
	reached_from[n] = current;
      }
    }
  }
  return reached_from;
}


int main(){
  vector<Edge> edges = {
			{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
			{ 3, 2 }, { 4, 5 }, { 5, 4 }
  };

  Graph graph(edges, 6);
  graph.printGraph();

  vector<int> result = graph.bfs(0);

  for (int i = 0; i < result.size(); i++){
    cout << i;
    if (result[i]>=0)
      cout << " reached from " << result[i] << endl;
    else
      cout << " unreachable" << endl;
  }
  return 0;
}
