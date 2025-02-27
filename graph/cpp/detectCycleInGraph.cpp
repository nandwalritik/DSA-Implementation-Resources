#include<bits/stdc++.>
using namespace std;
class Graph{
	int V;//number of vertices;
	list<int> *adj;
public:
	Graph(int V){
		this->V = V;
		adj		= new list<int>[V]; 
	}
	void addEdge(int u,int v)// edge from vertex u to v ;
	{
		adj[u].push_back(v);
	}
	void dfs(int x)//dfs starting at node with value x
	{
		bool visited[V];
		memset(visited,false,sizeof(visited));
		stack<int> s;
		s.push(x);
		while(!s.empty()){
			int p = s.top();
			s.pop();
			if(!visited[s]){
				cout<<s<<" ";
				visited[s]=true;
			}
			for(auto it = adj[p].begin() ; it != adj[p].end() ; it++){
				if(!visited[*it])
					s.push(*it);
			}
		}

	}
};
/*CODE FOR TOPOLOGICAL SORT OF GRAPH*/
/*
	int n;	//number of vertices 
	vector<vector<int>> adj; // adjacency list of graph
	vector<bool> visited;
	vector<int> ans;
	void dfs(int v) // dfs starting at vertex v
	{
		visited[v] = true;
		for(int u:adj[v]){
			if(!visited[u])
				dfs(u);
		}
		ans.push_back(v);
	}
	void topologicalSort(){
		visited.assign(n,false);
		ans.clear();
		for(int i = 0 ; i < n ; i++){
			if(!visited[i]){
				dfs(i);
			}
		}
		reverse(ans.begin(),ans.end());
	}




*/