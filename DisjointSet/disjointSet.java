import java.util.*;
public class disjointSet{
	private Map<Long,Node> map = new HashMap();
	class Node{
		long data;
		Node parent;
		int rank;
	}
	/*
		for	creating set with only 1 element 
	*/
	public void makeSet(long data){
		Node node 	= new Node();
		node.data 	= data;
		node.parent = node;
		node.rank	= 0;
		map.put(data,node);
	}
	/*
		combines two sets together to one.
		Union by rank
	*/
	public void union(long data1,long data2){
		Node node1 = map.get(data1);
		Node node2 = map.get(data2);

		Node parent1 = findSet(node1);
		Node parent2 = findSet(node2);

		//if they are part of same set do nothing
		if(parent1.data == parent2.data){
			return;
		}
		//else whoever's rank is higher becomes parent of other
		if(parent1.rank >= parent2.rank){
			//increment rank only if both sets have same rank
			parent1.rank = (parent1.rank == parent2.rank) ? parent1.rank+1 : parent1.rank;
			parent2.parent = parent1;
		}else{
			parent1.parent = parent2;
		}
	}
	/*
		finds and returns representative of this set
	*/
	public long findSet(long data){
		return findSet(map.get(data)).data;
	}	
	/*
		Find the representative recurssively and does path
		compression too!
	*/
	private Node findSet(Node node){
		Node parent = node.parent;
		if(parent == node){
			return parent;
		}
		node.parent = findSet(node.parent);
		return node.parent;
	}	
	public static void main(String args[]){
		disjointSet  ds = new disjointSet();
		ds.makeSet(1);
		ds.makeSet(2);
		ds.makeSet(3);
		ds.makeSet(4);
		ds.makeSet(5);
		ds.makeSet(6);
		ds.makeSet(7);
		
		ds.union(1,2);
		ds.union(2,3);
		ds.union(4,5);
		ds.union(6,7);
		ds.union(5,6);
		ds.union(3,7);

		System.out.println(ds.findSet(1));
		System.out.println(ds.findSet(2));
		System.out.println(ds.findSet(3));
		System.out.println(ds.findSet(4));
		System.out.println(ds.findSet(5));
		System.out.println(ds.findSet(6));
		System.out.println(ds.findSet(7));

	}
}
/*
C++ implementation for Codeforces Question:A https://codeforces.com/contest/277
#include<bits/stdc++.h>
using namespace std;
int parent[105];
int rank[1015];
void make_set(){
	for(int i = 0 ; i < 105 ; i++){
		parent[i] = i;
	}
	for(int i = 0 ; i < 105 ; i++){
		rank[i] = 0;
	}
}
int find_parent(int u){
	if(u == parent[u])
		return u;
	else 
		return parent[u] = find_parent(parent[u]);	
}
void union_sets(int u,int v){
	int par_u = find_parent(u);
	int par_v = find_parent(v);
	if(par_u != par_v){
		// jiski rank greater h voh parent banega
		// if rank of both parents is equal then increase the rank of one , which we are making parent
		if(rank[par_u] > rank[par_v]){
			parent[par_v] = par_u;
		}else{
			parent[par_u] = par_v;
			if(rank[par_u] == rank[par_v])
				rank[par_v]++;
		}
	}
}
int main(){
	int n,m,i,j,k,cnt;
	cin>>n>>m;
	int q1 = q;
	make_set();
	set<int> there;
	set<int> ans;
	int cnt = 0 ;
	while(n--){
		int a;
		cin>>a;
		if(!a){
			cnt++;
			continue;
		}
		vector<int> v(a);
		for(int i = 0 ; i < a ; i++)
			cin>>v[i];
		if(a)
			there.insert(v[0]);
		for(int i = 1 ; i < a ; i++){
			union_sets(v[i-1],v[i]);
			there.insert(v[i]);
		}
		for(int i = 1 ; i <= q1 ; i++){
			if(there.find(i) != there.end()){
				ans.insert(find_parent(i));
			}
		}	
		if(cnt)
			cout<< cnt+max(0,(int)ans.size()-1)<<endl;
		else
			cout<<max(0,(int)ans.size-1)<<endl;		
	}
	retrun 0;
}
// but if we also want to find the number of elements in each set
// then we can initialize size(n,1) and then add size of element with lesser rank to size of element with larger rank
// in case of equal rank add size of one being added to another set
// https://www.hackerrank.com/challenges/journey-to-the-moon/problem ----> practice this to get an intuition
#include<bits/stdc++.h>
using namespace std;
long long int find(vector<long long int> &parent,long long int i)
{
    return  i == parent[i] ? i : parent[i] = find(parent,parent[i]); 
}
void Union(vector<long long int> &parent,vector<long long int> &rank,vector<long long int> &sz,long long int i,long long int j){
    long long int x = find(parent,i);
    long long int y = find(parent,j);
    if(x == y)
        return;
    else{
        if(rank[x] > rank[y]){
            parent[y]=x;
            sz[x]+=sz[y];
        }else if(rank[y] > rank[x]){
            parent[x]=y;
            sz[y]+=sz[x];
        }else{
            parent[x] = y;
            // rank[y]++;
            rank[y]++;
            sz[y]+=sz[x];
            // rank[y]+=rank[x];
        }
    }
}
int main(){
    long long int n,k;
    cin>>n>>k;
    vector<long long int> parent(n),rank(n,1),sz(n,1);
    for(long long int i=0;i<n;i++)
        parent[i]=i;
    for(long long int i=0;i<k;i++){
        long long int u,v;
        cin>>u>>v;
        Union(parent,rank,sz,u,v);
    }
    set<long long int> vis;
    vector<long long int > temp;
    long long int ans=0,res=0;
    for(int i=0;i<n;i++){
        int temp = find(parent,i);
        // cout<<i<<" "<<temp<<" "<<sz[temp]<<endl;
        if(vis.find(temp) == vis.end()){
            // temp.push_back(rank[parent[i]]);
            res+=ans*sz[temp];
            ans+=sz[temp];
            
            vis.insert(temp);
        }
    }
    
    cout<<res<<endl;
        
    return 0;
}


*/
