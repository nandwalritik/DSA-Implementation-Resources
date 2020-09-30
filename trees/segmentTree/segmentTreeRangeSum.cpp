#include<bits/stdc++.h>
using namespace std;
/*
https://codeforces.com/contest/339/status/D?friends=on -------------- for this question
	a little bit simpler implementation
vector<ll> segment_tree(4*(1<<17)+1),arr((1<<17)+1);
void build(ll parent,ll start,ll end,ll level){
	if(start>end)
		return;
	if(start == end){
		segment_tree[parent] = arr[start];
		return;
	}
	ll mid = (start+end)/2;
	build(2*parent+1,start,mid,level-1);
	build(2*parent+2,mid+1,end,level-1);
	if(!(level&1)){
		segment_tree[parent] = segment_tree[2*parent+1]|segment_tree[2*parent+2];
	}
	else{
		segment_tree[parent] = segment_tree[2*parent+1]^segment_tree[2*parent+2]; 
	}
	return;
}	
void update(ll parent,ll start,ll end,ll pos,ll val,ll level){
	if(start > end)
		return;
	if(start == end && start == pos){
		segment_tree[parent] = val;
		return;
	}	
	ll mid = (start+end)/2;
	if(pos>=start && pos<=mid){
		update(2*parent+1,start,mid,pos,val,level-1);
	}else{
		update(2*parent+2,mid+1,end,pos,val,level-1);
	}	
	if(!(level&1))
		segment_tree[parent] = segment_tree[2*parent+1] | segment_tree[2*parent+2];
	else
		segment_tree[parent] = segment_tree[2*parent+1]^segment_tree[2*parent+2];	 
	return;
}

*/
struct SegmentTree{
	/*Using one based indexing*/
	vector<int> tree;
	int sizeOfSegmentTree;
	int n;
	SegmentTree(int n,vector<int> &temp){
		int p 			= (int)(ceil(log2(n)));
		this->sizeOfSegmentTree = 2*(int)pow(2,p) - 1;
		this->n                 = (int)pow(2,p);
		tree.resize(sizeOfSegmentTree+1,0);
		build(temp,1,1,n);
	}
	void build(vector<int> &temp,int parent,int l,int r){
		//cout<<"hi";
		if(l>r)
			return;
		if(l==r){
			tree[parent] = temp[l];
			//cout<<parent<<" "<<l<<endl;
		}else{
			int mid = (l+r)/2;
			//cout<<parent<<" "<<2*parent<<" "<<2*parent+1<<endl;
			build(temp,2*parent+1,mid+1,r);
			build(temp,2*parent,l,mid);
			tree[parent] = tree[2*parent] + tree[2*parent+1];
		}
	}
	void Display(){
		queue<int> q;
		q.push(1);
		while(!q.empty()){
			int nodeSize = q.size();
			for(int j=0;j<nodeSize;j++){
				int top = q.front();
				q.pop();
				if(2*top <= this->sizeOfSegmentTree)
					q.push(2*top);
				if(2*top+1 <= this->sizeOfSegmentTree){
					q.push(2*top+1);
				}
				cout<<tree[top]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<endl;
	}
	/* considering one based index this function return sum in range[l,r] inclusive*/
	/*
		tl -> treeLeft Index
		tr -> treeRight Index

	*/
	int sum(int vertex,int tl,int tr,int l,int r){
		if(l>r)
			return 0;
		if(l == tl && r == tr)
			return tree[vertex];
		int tm = (tl+tr)/2;
		return sum(2*vertex,tl,tm,l,min(r,tm))+sum(2*vertex+1,tm+1,tr,max(l,tm+1),r);
	}
	/*update value at index i*/
	/*to add specific value at index i update value by valueAtIndex + valueToBeAdded */
	void update(int vertex,int tl,int tr,int i,int new_val){
		if(tl == tr)
			tree[i]=new_val;
		else{
			int tm = (tl+tr)/2;
			if(i <= tm)
				update(2*vertex,tl,tm,i,new_val);
			else
				update(2*vertex+1,tm+1,tr,i,new_val);
			tree[vertex]=tree[2*vertex]+tree[2*vertex+1];
		}
	}
	
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif  
	int n,q,t;
	cin>>t;
	while(t--){
		vector<int> tree;
		cin>>n>>q;
		tree.resize(n+1);
		for(int i=1;i<=n;i++){
			cin>>tree[i];
			if(tree[i]%5)
				tree[i] = 0;
			else
				tree[i] = 1;
		}
		SegmentTree st(n,tree);
		//st.Display();
		for(int i=0;i<q;i++){
			int l,r;
			cin>>l>>r;

			cout<<st.sum(1,1,n,l,r)<<" ";
		}
		cout<<endl;
	} 	
	
	
	

	return 0;
}