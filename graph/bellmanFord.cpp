#include<bits/stdc++.h>
using namespace std;
int main(){
	
	/*index 0 : source
	  index 1 : destination
	  index 3 : distance from source to destination
	*/
	
	vector<vector<int>> v{{2,1,1},{2,3,1},{3,4,1}};
	int N = 4;	/*number of nodes*/
	int K = 2;	/*starting vertex*/
	
	/*Bellmanford simple implementation*/
	/*time complexity O(|N||Edges|)*/
	/*DrawBack : If there is a negative weight cycle then it will loop throughout infinitely and optimal solution could not be found for it*/
	
	vector<int> dist(N+1,INT_MAX);
	dist[K]=0;
	for(int i=0;i<N;i++){
		for(vector<int> e:v){
			int u=e[0],v=e[1],cost_u_v = e[2];
			if(dist[u]!=INT_MAX && dist[u]+cost_u_v < dist[v]){
				dist[v] = dist[u] + cost_u_v;
			}
		}
	}
	cout<<"vertex"<<" "<<"distance from source"<<endl;
	for(int i=1;i<=N;i++){
		cout<<i<<" "<<dist[i]<<endl;
	}


	return 0;
}