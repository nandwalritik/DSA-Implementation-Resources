#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &v, int start, int end)
{
	if (start < end)
	{
		int i = start - 1, j, pi = v[end];
		for (j = start; j < end; j++)
		{
			if (v[j] <= pi)
			{
				i++;
				swap(v[i], v[j]);
			}
		}
		swap(v[i + 1], v[end]);
		return i + 1;
	}
	return -1;
}
int kthSmallest(vector<int> &v, int start, int end, int k)
{
	if (start > end)
	{
		return INT_MAX;
	}
	int pos = partition(v, start, end);
	if(pos == -1)
		return INT_MAX;	
	if (pos - start == k - 1)
	{
		return v[pos];
	}
	else if (pos - start < k-1)
		return kthSmallest(v, pos + 1, end, k-(pos-start+1));
	return kthSmallest(v, start, pos - 1, k);
}
int main()
{
	vector<int> v{6, 5, 1, 0, 3, 2};
	int ind = kthSmallest(v,0,5,4);
	cout<<v[ind]<<"\n";
	// sort(v.begin(),v.end());
	// for(auto x:v)
	// 	cout<<x<<" ";
	// cout<<endl;
	return 0;
}