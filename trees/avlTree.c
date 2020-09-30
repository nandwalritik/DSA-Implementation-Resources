#include<stdio.h>
#include<stdlib.h>


struct Node{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

int height(struct Node *N){
	if(N == NULL)
		return 0;
	return N->height;
}

int max(int a,int b){
	return (a > b) ? a : b ;
}

struct Node* newNode(int key){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));

	node->key 	=	key;
	node->left 	=	NULL;
	node->right	=	NULL;
	node->height=	1;
	return node; 
}

struct Node *rightRotate(struct Node *y){
	struct Node *x 	= y->left;
	struct Node *T2	= x->right;

	x->right = y;
	y->left	 = T2;

	x->height = max(height(x->left),height(x->right))+1;
	y->height = max(height(y->left),height(y->right))+1;

	return y;
}

struct Node *leftRotate(struct Node *y){ 
	struct Node *x 	= y->right;
	struct Node *T2	= x->left; 

	x->left  = y;
	y->right = T2;

	y->height = max(height(x->left),height(x->right))+1;
	x->height = max(height(y->left),height(y->right))+1;

	return y;
}

int getBalance(struct Node *N){
	if(N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node,int key){
	/*1. Normal BST Insertion	*/
	if(node == NULL)
		return(newNode(key));
	if(key < node->key)
		node->left = insert(node->left,key);
	else if(key > node->key)
		node->right=insert(node->right,key);
	else
		return node;
	/*2. Updating height*/
	node->height = 1 + max(height(node->left),height(node->right));
	int balance  = getBalance(node);
	//left left case
	if(balance  > 1 && key < node->left->key)
		return rightRotate(node);
	//right right case
	if(balance < -1 && key > node->right->key)
		return leftRotate(node);
	//left right case
	if(balance > 1 && key > node->left->key){
		node->left  =  leftRotate(node->left);
		return rightRotate(node);
	}
	//right left case
	if(balance < -1 && key < node->right->key){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}