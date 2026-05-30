#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root = NULL;
struct node* getNewNode(int data){
	struct node* newNode = (struct node*)(malloc(sizeof(struct node)));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
struct node* insertNodeInTree(struct node* node,int data){
	if(node == NULL)
		return getNewNode(data);
	if(data < node->data)
		node->left = insertNodeInTree(node->left,data);
	else if(data > node->data)
		node->right = insertNodeInTree(node->right,data);

	return node;
}

void inorder(struct node* node){
	if(node!=NULL){
			inorder(node->left);
			printf("%d ",node->data);
			inorder(node->right);
	}

}

void printMin(){
	struct node* node = root;
	while(node->left!=NULL){
		node=node->left;
	}
	printf("%d\n",node->data);

}


void printMax(){
	struct node* node = root;
	while(node->right!=NULL){
		node=node->right;
	}
	printf("%d\n",node->data);

}
int findHeight(struct node* node){
	if(node = NULL)
		return -1;
	return findHeight(node->left)>findHeight(node->right)?findHeight(node->left)+1:findHeight(node->right)+1;
}


int main(){
	root = insertNodeInTree(root,50);
	insertNodeInTree(root,30);
	insertNodeInTree(root,20);
	insertNodeInTree(root,40);
	insertNodeInTree(root,70);
	insertNodeInTree(root,60);
	insertNodeInTree(root,80);
	inorder(root);
	printf("\n");

	printMin();
	printMax(); 
	printf("Height of tree is = %d",findHeight(root));
	return 0;
}