#include<stdio.h>
void swap(int*,int*);
void selectionSort(int A[],int size);
void bubbleSort(int A[],int size);
void insertionSort(int A[],int size);
void mergeSort(int A[],int l,int r);
void merge(int A[],int l,int m,int r);
void quickSort(int A[],int l,int end);
int partition(int A[],int start,int end);

int main(){
	int size,switchCase;
	printf("Enter size of the array\n");
	scanf("%d",&size);
	int ar[size];
	printf("\nEnter the elements of the array\n");
	for(int i=0;i<size;i++){
		scanf("%d",&ar[i]);
	}
	printf("\nSelect an appropriate algo for sorting:-\n");
	printf("\n1.Selection Sort\n");
	printf("\n2.Bubble Sort\n");
	printf("\n3.Insertion Sort\n");
	printf("\n4.Merge Sort\n");
	printf("\n5.Quick Sort\n");

	scanf("%d",&switchCase);
	switch(switchCase){
		case 1:
			selectionSort(ar,size);
			break;
		case 2:
			bubbleSort(ar,size);
			break;
		case 3:
			insertionSort(ar,size);
			break;	
		case 4:
			mergeSort(ar,0,size-1);
			break;	
		case 5:
			quickSort(ar,0,size-1);
			break;	
		default:
			printf("\nInvalid option\n");
			break;	
	}

	printf("\nYour Final Array\n");

	for(int i=0;i<size;i++)
		printf("%d ",ar[i]);
	printf("\n");

}


/*
	SELECTION SORT 
	(Selection sort since it repeatedly selects the smallest element.)
	1.Find min in the list
	2.Swap it with the value in the current position
	3.Repeat this for all elements util entire array is sorted
*/

void selectionSort(int A[],int size)
{
	int i,j;
	for (i = 0; i < size-1; i++){
		int mini = i;
		for(j=i+1;j<size;j++){
			if(A[j]<A[mini])
				mini=j;
		}
		swap(&A[i],&A[mini]);
	}			
		printf("\n");
}

/*
	bubbleSort Algorithm
	1.Iterate from first to last 
	2.Compare each pair of elements,Swap them if necessary
	3.INSERTION SORT has better performance than BUBBLE
	4.OPTIMIZATION (Important)
	improve it by using one extra flag. No more
	swaps indicate the completion of sorting. If the list is already sorted, we can use this flag to skip
	the remaining passes

*/
void bubbleSort(int A[],int size){
	int i,j;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if(A[j]>A[j+1])
				swap(&A[j],&A[j+1]);
		}
	}
}

/*
	INSERTION SORT
	1.Each iteration removes an element from input data and inserts it into the correct position in the list being sorted.
	2.The choice of the element being removed from the input is random and this process is repeated until
      all input elements have gone through.
      

*/

void insertionSort(int A[],int size){
	int i,j,key;
	for (i = 1; i < size; i++)
	{
		key = A[i];
		j=i-1;
		while(j >= 0 && A[j] > key){
			A[j+1]=A[j];
			j--;
		}
		// for (int j=0; j < i && A[j]>key; j++)
		// {
		// 	A[j+1]= A[j];
		// }
		A[j+1]=key;
	}
}

void mergeSort(int A[],int l,int r){
	if(l < r){

	int m = (l+r)/2;
	mergeSort(A,l,m);
	mergeSort(A,m+1,r);
	merge(A,l,m,r);

	}
	
}

void merge(int A[],int l,int m,int r){
	int lengthLeft,lengthRight;
	lengthLeft 	= m-l+1;
	lengthRight = r-(m+1)+1;
	int i,j,k;
	//making temporary arrays
	int L[lengthLeft],R[lengthRight];

	for(i=0;i<lengthLeft;i++)
		L[i] = A[l+i];

	for(i=0;i<lengthRight;i++)
		R[i] = A[m+1+i];

	i = 0;
	j = 0;
	k = l;

	while(i<lengthLeft && j<lengthRight){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	//Copying remaining elements of subarrays into original arrays

	while(i < lengthLeft){
		A[k] = L[i];
		i++;
		k++;
	}

	while(j < lengthRight){
		A[k] = R[j];
		j++;
		k++;
	}
}

void quickSort(int A[],int start,int end){
	if(start>=end)
		return;
	else{
		int partitionIndex = partition(A,start,end);
		quickSort(A,start,partitionIndex-1);
		quickSort(A,partitionIndex+1,end);
	}

}
int partition(int A[],int start,int end){
	int partitionIndex = start;
	int pivotElement = A[end];

	int i;
	for(i=start;i<end;i++){
		if(A[i] <= pivotElement)
		{
			swap(&A[i],&A[partitionIndex]);
			partitionIndex++;
		}
	}
	swap(&A[partitionIndex],&A[end]);
	return partitionIndex;
}


void swap(int *x,int *y){
	int t;
	t=*x;
	*x=*y;
	*y=t;
}