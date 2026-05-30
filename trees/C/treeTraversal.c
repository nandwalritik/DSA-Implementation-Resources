#include<stdio.h>
#include<stdlib.h>

struct Queue{
	struct Node *data;
	struct Queue *next;
};
struct Queue *front = NULL;
struct Queue *rear = NULL;


void enque(struct Node*);
void deque();
int isEmpty();
void display();
struct Queue *frontNode();


void levelOrderTraversal(struct Node *node){
	if(node == NULL) return ;
	enque(node);
	while(front != NULL){
		struct Queue *current = frontNode();
		struct Node *temp = current->data;
		// printf("hello\n");
		printf("%d\n",temp->data);
		printf("%d\n",node->data);

		// printf("%d ",current->data->data);
		// if(current->data->left != NULL) enque(current->data->left);
		// if(current->data->right != NULL) enque(current->data->right);
		deque();
	}

}

struct Node{
	int data;
	struct Node* left;
	struct Node* right;

};

struct Node* newNode(int data){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));

	node->data 	= data;
	node->left 	= NULL;
	node->right = NULL;
	return node;
}

void printPostOrder(struct Node* node){
	if( node == NULL)
		return;

	printPostOrder(node->left);
	printPostOrder(node->right);

	printf("%d ",node->data);
}

void printInOrder(struct Node* node){
	if(node == NULL)
		return;

	printInOrder(node->left);
	printf("%d ",node->data);
	printInOrder(node->right);

}	

void printPreOrder(struct Node* node){
	if(node == NULL)
		return;

	printf("%d ",node->data);
	printPreOrder(node->left);
	printPostOrder(node->right);

}
void printLevelOrder(struct Node* node){
	if(node == NULL)
		return ; 
	struct Node* temp = node;
	

}

int main(){
	struct Node *root = newNode(1);
	root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5);

    printf("\nPreorder traversal of binary tree is \n");  
    printPreOrder(root);
    printf("\nInorder traversal of binary tree is \n");  
    printInOrder(root);
    printf("\nPostorder traversal of binary tree is \n");  
    printPostOrder(root);
    printf("\nLevel order traversal of binary tree\n");
    levelOrderTraversal(root);

    printf("\n\n");

    return 0;
}



/* Queue helper functions used for implementing queue which is inturn used for levelOrderTraversal */
void enque(struct Node *data){
	struct Queue *newNode = (struct Queue*)(malloc(sizeof(struct Queue)));
	newNode->data = data;
	newNode->next = NULL;
	if(front == NULL){
		front = newNode;
	}
	else{
		struct Queue *temp = front;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		rear = newNode->next;
	}
}
void deque(){
	if(isEmpty()){
		return ;
	}else{
		front = front->next;
	}
}
int isEmpty(){
	return front == rear;
}

void display(){
	struct Queue *temp;
	temp = front;
	while(temp != NULL){
		
		printf("%d ",temp->data->data);
		temp = temp->next;
	}
	printf("\n");
}
struct Queue *frontNode(){
	return front;
}

