#include<bits/stdc++.h>
using namespace std;
bool isSafe(int i,int j,int N,int M){
	if(i < 0 || i >= N)
		return false;
	if(j < 0 || j >= M)
		return false;
	return true;
}
void bfs(vector<vector<int>> &v){
	
	int n=v.size(),m=v[0].size();
	vector<vector<bool>> visited(n,vector<bool>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visited[i][j]=false;
		}
	}
	queue<pair<int,int>> q;
	q.push({0,0});
	cout<<"Breadth First Traversal "<<endl;
	while(!q.empty()){
		auto temp = q.front();
		q.pop();
		int r=temp.first,c=temp.second;
		if(!isSafe(r,c,n,m) || visited[r][c]){
			continue;
		}
		visited[r][c]=true;
		cout<<v[r][c]<<" ";
		q.push({r,c-1});
		q.push({r,c+1});
		q.push({r-1,c});
		q.push({r+1,c});
	}
}
int main(){
	vector<vector<int>>v{{1, 2, 3,  4  },
                		{5, 6, 7, 8    },
                		{9, 10, 11, 12 },
                		{13, 14, 15, 16}};
    bfs(v);            		
	return 0;
}