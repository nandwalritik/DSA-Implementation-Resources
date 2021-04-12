#include<bits/stdc++.h>
using namespace std;
void topSort(vector<vector<int>> adj)
{
	int n = adj.size();
	vector<int> indegree(n,0);
	for(int i=0;i<n;i++)
	{
		for(auto x:adj[i])
			indegree[x]++;
	}
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		if(indegree[i] == 0)
			q.push(i);
	}
	int cnt=0;
	vector<int> top_sort;
	while(!q.empty())
	{
		int top = q.front();
		top_sort.push_back(top);
		q.pop();
		for(auto x:adj[top])
		{
			indegree[x]--;
			if(indegree[x] == 0)
				q.push(x);
		}
		cnt++;
	}
	if(cnt!=n){
		cout<<"No valid topological sort exist\n";
	}else{
		for(auto x:top_sort)
			cout<<x<<" ";
	}
}
void addEdge(vector<vector<int>> &adj,int u,int v)
{
	adj[u].push_back(v);
}
int main(){
	vector<vector<int>> adj(6);
	addEdge(adj,5,2);
    addEdge(adj,5,0);
    addEdge(adj,4,0);
    addEdge(adj,4,1);
    addEdge(adj,2,3);
    addEdge(adj,3,1);
    topSort(adj);
	return 0;
}