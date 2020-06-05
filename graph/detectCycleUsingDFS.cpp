#include<bits/stdc++.h>
using namespace std;

enum Color {WHITE , GRAY , BLACK};

class Graph{
	int V;
	list<int>* adj;
	bool DFSUtil(int v,int color[]);
public:
	Graph(int V);
	void addEdge(int v,int w);
	bool isCyclic();
};
Graph :: Graph(int V){
	this->V = V;
	adj = new list<int>[V];
} 
void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}
bool Graph::DFSUtil(int u,int color[]){
	color[u] = GRAY;
	list<int>::iterator i;
	for(i = adj[u].begin();i!=adj[u].end();i++){
		int v = *i;
		if(color[v] == GRAY)
			return true;
		if(color[v] == WHITE && DFSUtil(v,color))
			return true;
	}
	color[u] = BLACK;
	return false;
}

bool Graph::isCyclic(){
	int *color = new int[V];
	for(int i = 0 ; i < V ; i++)
		color[i] = WHITE;
	for(int i = 0 ; i < V ; i++){
		if(color[i] == WHITE)
			if(DFSUtil(i,color) == true)
				return true;
	}
	return false;
}
int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);

	if(g.isCyclic())
		cout<<"Graph contains cycle";
	else
		cout<<"Graph doesn't contain cycle";
	return 0;
}