#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<bool> &visited,vector<int> adj[],vector<pair<int,int>> &time,int &temp){
	if(visited[node])
		return;
	time[node].first = temp;
	visited[node]=true;
	temp++;
	for(auto x:adj[node])
	{
		if(!visited[x]){
			
			dfs(x,visited,adj,time,temp);
			
		}
	}

	time[node].second = temp;
	temp++;
}
int main(){
	int n = 6;
	vector<pair<int,int>> time(6,{0,0});
	// for(auto x:time)
		// cout<<x.first<<" "<<x.second<<endl;
	vector<int> adj[6];
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(3);
	adj[2].push_back(4);
	adj[4].push_back(5);

	adj[1].push_back(0);
	adj[2].push_back(0);
	adj[3].push_back(1);
	adj[3].push_back(2);
	adj[4].push_back(2);
	adj[5].push_back(4);
	int temp=1;
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			dfs(i,visited,adj,time,temp);
		}
	}
	for(auto x:time)
		cout<<x.first<<" "<<x.second<<endl;

	return 0;

}