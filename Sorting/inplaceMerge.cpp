#include<bits/stdc++.h>
using namespace std;
int nextGap(int gap){
	if(gap <= 1)
		return 0;
	return int(ceil(gap/2.0));
}
void inPlacemerge(vector<int> &nums,int start,int end)
{
	int gap = end-start+1;
	for(gap=nextGap(gap) ; gap > 0 ; gap = nextGap(gap)){
		for(int i = start ; i+gap <= end ; i++)
		{
			int j=i+gap;
			if(nums[i] > nums[j])
				swap(nums[i],nums[j]);
		}
	}
}
void mergeSort(vector<int>&nums,int start,int end)
{
	if(start >= end)
		return;
	int mid = start+(end-start)/2;
	mergeSort(nums,start,mid);
	mergeSort(nums,mid+1,end);
	inPlacemerge(nums,start,end);
}
int main(){
	vector<int> nums{2,3,5,12,54,12,67,11,78,1};
	int n = nums.size();
	int start=0,end=n-1;
	mergeSort(nums,start,end);
	for(auto x:nums)
		cout<<x<<" ";
	cout<<"\n";
	return 0;
}