/*
	Space complexity : O(n)
	Time complexity for creation : O(nlogn)
	update query complexity : O(logn)
	search query complexity : O(logn)

	To find the parent of node in fenwick tree flip the rightmost bit in the binary representation of number.
			Node   Binary ParentBinary   parentDecimal
	Example 11 	-> 1011   1010 		  -> 10


	Every Number can be represented as sum of powers of 2.
	Fenwick tree uses this information to store numbers.

	GetParent									Time complexity : O(1)
	1.) Find 2's complement
	2.) AND it with original Number.
	3.) Substract From the original Number.

	GetNextMethod(while updating)
	1.) Find 2's complement
	2.) AND it with original Number.
	3.) Add to the original number.
	if greater than last index then stop the process

*/
#include<bits/stdc++.h>
using namespace std;

class FenwickTree{
	int N;
	vector<int> tree;
	void init(int n){
		N=n;
		tree.assign(n+1,0);
	}
	void update(int idx,int val){
		while(idx <= N){
			tree[idx]+=val;
			idx += idx & -idx;
		}
	}
	void updateMax(int idx,int val){
		while(idx <= N){
			tree[idx] = max(tree[idx],val);
			idx += idx & -idx;
		}
	}

	int pref(int idx){
		int ans = 0;
		while (idx > 0)
		{
			ans += tree[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r){
		return pref(r) - pref(l - 1);
	}

	int prefMax(int idx){
		int ans = -2e9;
		while (idx > 0)
		{
			ans = max(ans, tree[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};
int main(){
	return 0;
}