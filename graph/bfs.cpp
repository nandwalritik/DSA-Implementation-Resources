#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;//number of vertices;
	list<int> *adj;
public:
	Graph(int V);//Constructor to initialize size of adjacency list
	void addEdge(int v,int w);//edge from node v to node w
	void BFS(int v);//Breadth first search starting at node v
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}

void Graph::BFS(int s){
	bool *visited = new bool[V];
	for(int i = 0 ; i < V ; i++){
		visited[i] = false;
	}
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	list<int>::iterator itr;
	while(!queue.empty()){
		s = queue.front();
		cout<<s<<" ";
		queue.pop_front();

		for(itr = adj[s].begin() ; itr != adj[s].end() ; itr++){
			if(!visited[*itr]){
				visited[*itr] = true;
				queue.push_back(*itr);
			}
		}
	}

}
int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,2)
;	g.addEdge(3,3);
	cout<<"Breadth first search (starting at vertex 2)\n";
	g.BFS(2);
	cout<<endl;
	return 0;
}