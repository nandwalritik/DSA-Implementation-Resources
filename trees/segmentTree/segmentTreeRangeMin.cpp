#include<bits/stdc++.h>
using namespace std;
struct SegmentTree{
	vector<int> tree;
	int sizeOfSegmentTree;
	int n;
	SegmentTree(int n,vector<int> &temp){
		int p 			= (int)(ceil(log2(n)));
		this->sizeOfSegmentTree = 2*(int)pow(2,p) - 1;
		this->n                 = (int)pow(2,p);
		tree.resize(sizeOfSegmentTree+1,INT_MAX);
		build(temp,1,1,n);
	}
	void build(vector<int> &temp,int parent,int l,int r){
		if(l>r)
			return ;
		if(l == r){
			tree[parent] = temp[l];
		}
		else{
			int mid = (l+r)/2;
			build(temp,2*parent,mid+1,r);
			build(temp,2*parent+1,l,mid);
			tree[parent] = min(tree[2*parent],tree[2*parent+1]);
		}
	}
	void display(){
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
	}
	/*update this function*/
	/*int rangeMin(int parent,int tl,int tr,int l,int r){
		if(l<=tl && r>=tr){
			return tree[parent];
		}
		if( r > tr || l < tl)
			return INT_MAX;
		int mid = (tl+tr)/2;
		return min(rangeMin(2*parent,tl,mid,l,r),rangeMin(2*parent+1,mid+1,tr,l,r));
	}*/
};
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
	int n;
	cin>>n;
	vector<int> v(n+1);
	for(int i=1;i<=n;i++)
		cin>>v[i];
	SegmentTree st(n,v);
	st.display();
	// st.display();
	// cout<<st.rangeMin(1,1,n,3,4)<<endl;
	// cout<<st.rangeMin(1,1,n,2,3)<<endl;

	return 0;
}