#include <bits/stdc++.h>
using namespace std;
class Heap
{
private:
	int capacity, heapType;
	int size = -1;
	int *heap;

public:
	// type -> 0 -> minHeap
	// type -> 1 -> maxHeap
	// considering 0 based indexing
	Heap(int heapsize)
	{
		capacity = heapsize;
		heap = new int[capacity];
		// heapType = type;
	}
	bool empty()
	{
		return size == -1;
	}
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	int leftChild(int i)
	{
		return 2 * i + 1;
	}
	int rightChild(int i)
	{
		return 2 * i + 2;
	}
	void siftUp(int i)
	{
		while (i > 0 && heap[parent(i)] < heap[i])
		{
			swap(heap[parent(i)], heap[i]);
			i = parent(i);
		}
	}
	void siftDown(int i)
	{
		int maxIndex = i;
		int l = leftChild(i);
		if (l <= size && heap[l] > heap[maxIndex])
		{
			maxIndex = l;
		}
		int r = rightChild(i);
		if (r <= size && heap[r] > heap[maxIndex])
		{
			maxIndex = r;
		}
		if (i != maxIndex)
		{
			swap(heap[i], heap[maxIndex]);
			siftDown(maxIndex);
		}
	}
	void insert(int element)
	{
		if (size == capacity - 1)
		{
			cout << "Heap is full\n";
			return;
		}
		size += 1;
		heap[size] = element;
		siftUp(size);
	}
	void remove(int i)
	{
		if (size == -1)
		{
			cout << "Heap is empty\n";
			return;
		}
		else if (i > size - 1)
		{
			cout << "Index out of bound\n";
			return;
		}
		heap[i] = INT_MAX;
		siftUp(i);
		extractMax();
	}
	int extractMax()
	{
		int res = heap[0];
		heap[0] = heap[size];
		size -= 1;
		siftDown(0);
		return res;
	}
	int heapSize()
	{
		return size + 1;
	}

	// int extractMin(){}
};
int main()
{
	Heap p(4);
	p.insert(10);
	p.insert(20);
	p.insert(30);
	p.insert(2);
	p.insert(29);
	// cout<<p.heapSize()<<" \n";
	while (!p.empty())
	{
		cout << p.extractMax() << " ";
	}
	return 0;
}

/*
#include<bits/stdc++.h>
#define INF INT_MAX;
#define maxSize 1000;
using namespace std;

struct Heap{
	int maxSize;
	int size;	
	int H[maxSize];
	int parent(int i)
	{
		return i/2;
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
*/