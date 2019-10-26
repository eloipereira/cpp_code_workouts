#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>


using namespace std;


template<typename T>
class Graph{
public:
  struct Edge {
    T src, dest;
  };

  map<T,vector<T>> adjList;
  Graph(vector<Edge> const &edges, int N);
  void printGraph();
  int getNumVertices();
  map<T,T> bfs(T s);
  stack<T> shortest_path(T s,T d);
};

template<typename T>
Graph<T>::Graph(vector<Edge> const &edges, int N){		
  for (auto edge: edges){
    adjList[edge.src].push_back(edge.dest);
    // Uncomment below line for undirected graph
    // adjList[edge.dest].push_back(edge.src);
  }
}

template<typename T>
int Graph<T>::getNumVertices(){
  return adjList.size();
}

template<typename T>
void Graph<T>::printGraph(){
  int N = getNumVertices();
  for (auto i: adjList){
    cout << i.first << " --> ";
    for (auto v : i.second)
      cout << v << " ";
    cout << endl;
  }
}

template<typename T>
map<T,T> Graph<T>::bfs(T s){
  
  int N = getNumVertices();
  map<T,T> reached_from;
  map<T,bool> visited;

  queue<T> q;
  q.push(s);
  visited[s] = true;
  
  while(!q.empty()){
    int current = q.front();
    q.pop();
    vector<T> neighbours = adjList[current];
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

template<typename T>
stack<T> Graph<T>::shortest_path(T s, T d){
  map<T,T> b = bfs(s);
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

int main(){
  vector<Graph<int>::Edge> edges = {
			{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
			{ 3, 2 }, { 4, 5 }, { 5, 4 }
  };

  Graph<int> graph(edges, 6);
  graph.printGraph();

  map<int,int> result = graph.bfs(0);

  for (auto i: result){
    cout << i.first << " reached from " << i.second << endl;
  }

  stack<int> path =  graph.shortest_path(0,2);
  while (path.size() > 0){
    cout << path.top() << " ";
    path.pop();
  }
  cout << endl;
  return 0;
}
