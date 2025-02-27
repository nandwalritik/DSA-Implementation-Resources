#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	void dfsUtil(int v,bool visited[]);
public:
	Graph(int V);
	void addEdge(int v,int w);
	void DFS(int v);
    int NumConn();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];

}

void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}
//Uncomment this section to run recurssive solution for 
void Graph::dfsUtil(int v,bool visited[]){
	visited[v] = true;
	//cout<<v<<" ";

	list<int> :: iterator itr;
	for(itr = adj[v].begin() ; itr != adj[v].end() ; itr++){
		if( !visited[*itr] )
			dfsUtil(*itr,visited);
	}
}
void Graph::DFS(int v){
	bool *visited = new bool[V];
	memset(visited,false,sizeof(visited));
	dfsUtil(v,visited);
}
int Graph::NumConn(){
    bool* visited = new bool[V];
    memset(visited,false,sizeof(visited));
    int cnt=0;
    for(int i = 0; i < V ; i++){
        if(!visited[i]){
            dfsUtil(i,visited);
            cnt++;
        }
    }
    return cnt;
} 
int main(){
	int n,m,k,i,j;
    cin>>n>>m>>k;
    Graph g(n);
    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        addEdge(a,b);
    }
    cout<<NumConn()<<endl;
	return 0;
}