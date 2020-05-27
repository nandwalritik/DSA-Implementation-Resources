#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;//number of vertices;
	list<int> *adj;
public:
	Graph(int V);//Constructor to initialize size of adjacency list
	void addEdge(int v,int w);//edge from node v to node w
	int minEdgeBfs(int src,int 
	dest);//Breadth first search starting at node v
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}

int Graph::minEdgeBfs(int s,int dest){
	bool *visited = new bool[V];
	int distance[V]={0};
	for(int i = 0 ; i < V ; i++){
		visited[i] = false;
	}
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	distance[s]=0;
	list<int>::iterator itr;
	while(!queue.empty()){
		s = queue.front();
		//cout<<s<<" ";
		queue.pop_front();

		for(itr = adj[s].begin() ; itr != adj[s].end() ; itr++){
			if(!visited[*itr]){
				visited[*itr] = true;
				distance[*itr] = distance[s]+1;
				queue.push_back(*itr);
			}
		}
	}
	return distance[dest];

}
int main(){
    int t;
    cin>>t;
    while(t--){
            int n,m;
            cin>>n>>m;
            Graph g(n);
            while(m--){
                int x,y;//considering indexes to start from 1.
                cin>>x>>y;
                x--;y--;
                g.addEdge(x,y);
                g.addEdge(y,x);//considering undirected graph
            }
            cout<<g.minEdgeBfs(0,n-1)<<endl;
    }
	
	
	return 0;
}