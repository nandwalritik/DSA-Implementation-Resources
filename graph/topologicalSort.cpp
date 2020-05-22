#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;//number of vertices
	list<int> *adj;
	void topologicalSortUtil(int v,bool visited[],stack<int> &Stack){
		visited[v] = true;
		list<int>::iterator itr;
		for(itr = adj[v].begin() ; itr != adj[v].end() ; itr++){
			if(!visited[*itr]){
				topologicalSortUtil(*itr,visited,Stack);
			}
		}
		Stack.push(v);
	}
public:
	Graph(int V){
		this->V = V;
		adj = new list<int>[V];
	}
	void addEdge(int v,int w){
		adj[v].push_back(w);
	}
	void displayTopSort(){
		stack<int> Stack;
		bool* visited = new bool[V];
		for(int i = 0 ; i < V ; i++){
			visited[i] = false;
		} 
		for(int i = 0 ; i < V ; i++){
			if(visited[i] == false)
				topologicalSortUtil(i,visited,Stack);
		}
		while(Stack.empty() == false){
			cout<<Stack.top()<<" ";
			Stack.pop();
		}
	}
};

int main(){
	Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph n"; 
    g.displayTopSort(); 
	return 0;
}