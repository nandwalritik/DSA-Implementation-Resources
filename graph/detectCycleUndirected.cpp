#include<bits/stdc++.h>
using namespace std;
/*Using Disjoint set union by rank method*/
int find(vector<int> &parent,int i)
{
	return i==parent[i] ? i : parent[i] = find(parent,parent[i]);
}
void Union(vector<int> &parent,vector<int> &rank,int x,int y){
	if(rank[x] > rank[y]){
		parent[y]=x;
	}else if(rank[y] > rank[x]){
		parent[x]=y;
	}else{
		parent[x]=y;
		rank[y]++;
	}
}
bool findCycle(vector<vector<int>> edges,int n)
{
	vector<int> parent(n);
	vector<int> rank(n,0);
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}
	for(int i=0;i<edges.size();i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		int x = find(parent,u);
		int y = find(parent,v);
		if(x == y)
			return true;
		Union(parent,rank,x,y);
	}
	return false;
}

/*Using color method*/
bool dfs(vector<vector<int>> adj,int u,vector<int> &color,int parent){
    color[u]=1;
    for(auto x:adj[u]){
        if(x == parent)
            continue;
        if(color[x] == 1)
            return true;
        else if(color[x] == 0 && dfs(adj,x,color,u))
            return true;
    }
    color[u]=2;
    return false;
}
bool isCycle(int V, vector<vector<int>> &adj){
    vector<int> color(V,0);
    bool ans;
 
    for(int i=0;i<V;i++)
    {
        if(color[i] == 0){
           int parent = -1;
           ans = dfs(adj,i,color,parent); 
        }
        if(ans)
            return true;
    }
    return false;
}
int main(){
	int n = 3;
	vector<vector<int>> edges{{0,1},{0,2},{1,2}};
	vector<vector<int>> adj(3);
	for(int i=0;i<edges.size();i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(isCycle(n,adj)){
		cout<<"Cycle detected\n";
	}
	if(findCycle(edges,n)){
		cout<<"Cycle detected\n";		
	}
	else{
		cout<<"No cycle\n";
	}

	return 0;
}