#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	void dfsUtil(int v,bool visited[]);
public:
	Graph(int V);
	void addEdge(int v,int w);
	void DFS(int v);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];

}

void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}
//iterative approach for dfs
void Graph::DFS(int s){
	vector<bool> visited(V,false);
	stack<int> stack;
	stack.push(s);
	while(!stack.empty()){
		s = stack.top();
		stack.pop();
		if(!visited[s]){
			cout<<s<<" ";
			visited[s] = true;
		}
		for(auto i = adj[s].begin() ; i != adj[s].end() ; i++){
			if(!visited[*i])
				stack.push(*i);
		}
	}
}

//Uncomment this section to run recurssive solution for 
/*void Graph::dfsUtil(int v,bool visited[]){
	visited[v] = true;
	cout<<v<<" ";

	list<int> :: iterator itr;
	for(itr = adj[v].begin() ; itr != adj[v].end() ; itr++){
		if( !visited[*itr] )
			dfsUtil(*itr,visited);
	}
}
void Graph::DFS(int v){
	bool *visited = new bool[V];
	//for(int i = 0 ; i < V ; i++)
	//	visited[i] = false;
	memset(visited,false,sizeof(visited));
	dfsUtil(v,visited);
}*/
int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	cout<<"Depth First Traversal(starting vertex(2))\n";
	g.DFS(2);
	cout<<endl;
	return 0;
}
