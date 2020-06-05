#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool isSafe(int N,int M,int i,int j){
	if(i < 0 || i >= N )
		return false;
	if(j < 0 || j >= M)
		return false;
	return true;
}

//this function does the DFS for every new one 1 found and assign every connected one to zero.
/*Considering 8 directional connection*/


void delIsland(vector<vector<ll>> &v,ll N,ll M,ll i, ll j){
	if(isSafe(N,M,i,j) && v[i][j] == 1){
		v[i][j]=0;
		delIsland(v,N,M,i-1,j-1);
		delIsland(v,N,M,i-1,j);
		delIsland(v,N,M,i-1,j+1);
		delIsland(v,N,M,i,j-1);
		delIsland(v,N,M,i,j+1);
		delIsland(v,N,M,i+1,j-1);
		delIsland(v,N,M,i+1,j);
		delIsland(v,N,M,i+1,j+1);
	}
}

ll TotalIslands(vector<vector<ll>> &v,ll N,ll M){
	ll count = 0;
	for(ll i = 0 ; i < N ; i++){
		for(ll j = 0 ; j < M ; j++){
			if(v[i][j] == 1){
				count++;
				delIsland(v,N,M,i,j);
			}
		}
	}
	return count;
}

int main(){
	ll N,M;
	vector<vector<ll>> v;
	cin>>N>>M;
	for(ll i=0;i<N;i++){
		vector<ll> p;
		for(ll j=0;j<M;j++){
			ll temp;
			cin>>temp;
			p.push_back(temp);
		}
		v.push_back(p);
	}
	cout<<"Total Number of islands : "<<TotalIslands(v,v.size(),v[0].size())<<endl;
	return 0;
}