#include<bits/stdc++.h>
using namespace std;
int timer=0;
void dfs(int node,int par,vector<int> &in,vector<int> &low,vector<bool> &vis,vector<int> adj[]){
    vis[node]=true;
    in[node]=low[node]=timer;
    timer++;
    int children=0;
    for(auto child:adj[node]){
        if(child == par)
            continue;
        else if(vis[child]){
            // the edge node-child is a back edge
            low[node]=min(low[node],in[child]);
        }
        else{
            dfs(child,node,in,low,vis,adj);
            if(low[child] >= in[node] && par != -1){
                // for 1 based numbering
                cout<<node+1<<" is a Articulation Point\n";
            }
            low[node]=min(low[node],low[child]);
            children++;
        }
    }
    if(children > 1 && par == -1){
        cout<<node+1<<" is a Articulation Point\n";
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    vector<int> in(n),low(n);
    vector<bool> vis(n,false);
    dfs(0,-1,in,low,vis,adj);
    return 0;
}
