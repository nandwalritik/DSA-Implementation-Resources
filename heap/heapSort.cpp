/*
	IMPLEMENTATION of heap using array
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
void swap(int *a,int *b){
	int t = *a;*a = *b;*b = t;

}
void heapify(int A[],int n,int i){

	int parent = (1.0*(i-1)/2);
	if(parent <= 0)
		return ;
	if(A[parent] > 0){
		if(A[i] > A[parent]){
			swap(&A[i],&A[parent]);
			heapify(A,n,parent);
		}
	}
}	

void insertNode(int A[],int& n,int key){
	n+=1;
	A[n-1] = key;
	heapify(A,n,n-1);
}
void printArray(int A[],int n){
	for(int i = 0 ; i < n ; i++){
		printf("%d \n",A[i]);
	}
}

int main(){
	int arr[MAX] = { 10, 5, 3, 2, 4 }; 
  
    int n = 5; 
	
  
    int key = 15; 
  
    insertNode(arr, n, key); 
  
    printArray(arr, n); 
	return 0;
}




























// #include<stdio.h>
// struct Tree{
// 	int data;
// 	struct Tree *left,*right;
// };
// struct Node* newNode(int key){
// 	struct Node* temp = (struct Node* )malloc(sizeof(struct Node));
// 	temp->key = key;
// 	temp->left=temp->right=NULL;
// 	return temp;

// };


// int main(){
// 	return 0;
// }
