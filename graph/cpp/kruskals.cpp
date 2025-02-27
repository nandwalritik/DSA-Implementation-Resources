#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
    node(int first,int second,int weight){
        u=first;
        v=second;
        w=weight;
    }
};
bool comp(node a,node b){
    return a.w < b.w;
}
int findPar(int u,vector<int> &parent){
    if(u == parent[u])
        return u;
    return parent[u] = findPar(parent[u],parent);
}
void Union(int u,int v,vector<int> &parent,vector<int> &size){
    u = findPar(u,parent);
    v = findPar(v,parent);
    if(size[u] < size[v]){
        parent[u] = v;
        size[v] += size[u];
    }else{
        parent[v]=u;
        size[u]+=size[v];
    }
}
int main(){
    int N,m;
    cin>>N>>m;
    vector<node> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(node(u,v,w));
    }
    /*
        sample testcase for trying
        N=4,m=5
        0 1 10
        0 2 6
        0 3 5
        1 3 15
        2 3 4
    */
    sort(edges.begin(),edges.end(),comp);
    vector<int> parent(N);
    for(int i=0;i<N;i++)
        parent[i] = i;
    vector<int> size(N,0);
    int cost=0;
    vector<pair<int,int>> mst;
    for(auto it:edges){
        if(findPar(it.v,parent) != findPar(it.u,parent)){
            cost+=it.w;
            mst.push_back({it.u,it.v});
            Union(it.u,it.v,parent,size);
        }
    }
    cout<<cost<<endl;
    for(auto it:mst){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}
