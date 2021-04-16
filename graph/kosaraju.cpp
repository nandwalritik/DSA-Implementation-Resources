#include<bits/stdc++.h>
using namespace std;

void dfs1(vector<int> &order,vector<bool> &visited,vector<vector<int>> &adj,int u){
	visited[u] = true;
	for(auto x:adj[u])
	{
		if(!visited[x])
			dfs1(order,visited,adj,x);
	}
	order.push_back(u);
}
void dfs2(vector<int> &component,vector<bool> &visited,vector<vector<int>> &gr,int u){
	visited[u] = true;
	component.push_back(u);
	for(auto x:gr[u])
	{
		if(!visited[x])
			dfs2(component,visited,gr,x);
	}
}
int main(){
	int n,i,j;
	cin>>n;
	vector<vector<int>> g(n),gr(n);
	for(i=0;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		gr[v].push_back(u);
	}
	vector<int> order,component;
	vector<bool> visited(n,false);
	for(i=0;i<n;i++)
	{
		if(!visited[i])
			dfs1(order,visited,g,i);
	}
	visited.assign(n,false);
	for(i=0;i<n;i++)
	{
		int v = order[n-i-1];
		if(!visited[v])
			dfs2(component,visited,gr,v);
		for(auto x:component)
		{
			cout<<x<<" ";
		}
		cout<<endl;
		component.clear();
	}



	return 0;
}