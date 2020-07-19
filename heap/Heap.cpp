#include<bits/stdc++.h>
using namespace std;

struct Heap
{
	int *array;
	int count;		/*Num of elements in Heap*/
	int capacity;	/*size of Heap*/
	int heap_type;	/*
					0 for min_heap 
					1 for max_heap
				*/
};

struct Heap* makeHeap(int capacity,int heap_type){
	struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
	if(h == NULL)
	{
		printf("Memory Error\n");
		return;
	}
	h->heap_type	= 	heap_type	;
	h->count	= 	0		;
	h->capacity 	= 	capacity	;
	h->array 	=	(int*)malloc(sizeof(int)*h->capacity);
	if(h->array == NULL)
	{
		printf("Memory Error");
		return;
	}
	return h;
}

void swap(int *p,int *q)
{
	int t = *p;
	*p=*q;
	*q=t;
}

int Parent(struct Heap *h,int i)
{
	if(i <= 0 || i>= h->count)
		return -1;
	return (i-1)/2;
}

int leftChild(struct Heap *h,int i)
{
	int left = 2*i+1;
	if(left >= h->count)
		return -1;
	return left;
}

int rightChild(struct Heap *h,int i)
{
	int right = 2*i+2;
	if(right >= h->count)
		return -1;
	return right; 	
}

int getMaximum(Heap *h)
{
	if(h->count == 0)
		return -1;
	return h->array[0];
}

void percolateDown(struct Heap *h,int i)
{
	int l,r,max,temp;
	l = leftChild(h,i);
	r = rightChild(h,i);
	if(l != -1 && h->array[l] > h->array[i])
	{
		max=l;
	}
	else
	{
		max = i;
	}
	if(r != -1 && h->array[r] >h->array[max])
	{
		max = r;
	}
	if(max != i)
	{
		swap(&h->array[i],&h->array[max]);
	}
	percolateDown(h,max);
}


void percolateUp(struct Heap *h,int &i)
{
	while(i > 1 && h->array[Parent(i)] < h->array[i])
	{
		swap(&h->array[Parent(i)],&h->array[i]);
		i = Parent(i);
	}
}

/*
	• Copy the first element into some variable
	• Copy the last element into first element location
	• PercolateDown the first element
*/

int deleteMax(struct Heap *h)
{
	int data;
	if(h->count == 0)
		return -1;
	data = h->array[0];
	h->array[0] = h->array[h->count-1];
	h->count--; // reducing heapSize
	percolateDown(h,0);
	return data;
}

/*
	• Increase the heap size
	• Keep the new element at the end of the heap (tree)
	• Heapify the element from bottom to top (root)
*/

int Insert(struct Heap *h,int data)
{
	int i;
	if(h->count == h->capacity)
		resizeHeap(h);
	h->count++;
	i=h->count-1;
	percolateUp(h,i);
	h->array[i]=data;

}

void resizeHeap(struct Heap *h)
{
	int *array_old = h->array;
	h->array = (int*)malloc(sizeof(int)*h->capacity*2);
	if(h->array == NULL)
	{
		printf("Memory Error\n");
		return;
	}
	for(int i=0;i < h->capacity ; i++)
	{
		h->array[i] = array_old[i];
	}
	h->capacity*=2;
	free(array_old);
}

void destroyHeap(struct Heap *h)
{
	if(h==NULL)
		return;
	free(h->array);
	free(h);
	h = NULL;
}

/*Heapifuing the array*/

void buildHeap(struct Heap *h,int A[],int n)
{
	if(h == NULL)
		return;
	while(n > h->capacity)
		resizeHeap(h)
	for(int i=0;i<n;i++)
		h->array[i]=A[i];
	h->count=n;
	for(int i=(n-1)/2;i>=0;i--)
		percolateDown(h,i);
}

/*Performing Heap Sort*/
void HeapSort(int A[],int n)
{
	struct Heap *h = makeHeap(n);
	int old_size,i,temp;
	buildHeap(h,A,n);
	old_size = h->count;
	for(i=n-1;i>=0;i--){
		/*h->array[0] is the largest element*/
		temp = h->array[0];
		h->array[0]=h->array[h->count-1];
		h->array[0]=temp;
		h->count--;
		percolateDown(h,0);
	}  
	h->count = old_size;
}
