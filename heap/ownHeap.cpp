#include<bits/stdc++.h>
#define INF INT_MAX;
#define maxSize 1000;
using namespace std;
struct Heap{
	int maxSize;
	int size;	/*size of the heap*/
	int H[maxSize];
	int parent(int i)
	{
		return i/2;/*one based indexing*/
	}
	int leftChild(int i)
		return 2*i;
	int rightChild(int i)
		return 2*i+1;
	void SiftUp(int i){
		while(i>1 && H[parent(i)] < H[i]){
			swap(H[parent[i]],H[i]);
			i=parent(i);
		}
	}	
	void SiftDown(int i){
		int maxIndex = i;
		int l = leftChild(i);
		if( l <= this->size && H[l] > H[maxIndex])
			maxIndex=l;
		int r = rightChild(i);
		if( r <= this->size && H[r] > H[maxIndex])
			maxIndex=r;
		if(i != maxIndex)
		{
			swap(H[i],H[maxIndex]);
			SiftDown(maxIndex);
		}
	}
	void insert(int p){
		if(size == maxSize)
			return ;
		size = size + 1;
		H[size] = p;
		SiftUp(size);
	}
	int ExtractMax(){
		int result = H[1];
		H[1]=H[this->size];
		size-=1;
		SiftDown(1);
		return result;
	}
	void remove(int i){
		H[i] = INF;
		SiftUp(i);
		ExtractMax();
	}
	void ChangePriority(int i,int p){
		int oldp = H[i];
		H[i]	   = p;
		if(p > oldp)
			SiftUp(i);
		else
			SiftDown(i);	 	
	}
};