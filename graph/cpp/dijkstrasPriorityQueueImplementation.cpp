/*Priority queue implementation of Dijkstras Algorithm*/
#include<bits/stdc++.h>
#define pii pair<int,int>
#define INF INT_MAX
using namespace std;
void dijkstraFunc(int src,vector<vector<pii>> &adj){
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	int n = adj.size();
	vector<int> dist(n,INF);
	pq.push({0,src});
	dist[src] = 0;
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for(auto x:adj[u]){
			int v 		= x.first;
			int weight 	= x.second;
			if(dist[u]+weight < dist[v]){
				dist[v] = dist[u] + weight;
				pq.push({dist[v],v});
			}
		}
	}
	cout<<"Vertex distance from source"<<endl;
	for(int i = 0 ; i < n ; i++){
		cout<<i<<" "<<dist[i]<<endl;
	}

}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif


	int n,m;
	cin>>n>>m;
	vector<vector<pii>> adj(n,vector<pii>());
	for(int i = 0 ; i < m ; i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	dijkstraFunc(0,adj);
	return 0;
}