#include<stdio.h>
struct Node{
	int data;
	struct Node *next;
};

struct Node *head,*temp;

void diaplayList();
void addNodeAtLast(int);
struct Node* lastPointer();


int main(){

	addNodeAtLast(4);
	addNodeAtLast(2);
	addNodeAtLast(1);
	addNodeAtFront(3);	
	displayList();


	return 0;
}

void addNodeAtLast(int data){
	struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));

	newNode->data = data;
	newNode->next = newNode;


	if(head == NULL){
		head = newNode;
	}else{

		struct Node *check;
		check = lastPointer();

		check->next = newNode;
		newNode->next = head;

	}	
}
void addNodeAtFront(int data){
	struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));
	
	newNode->data = data;
	newNode->next = newNode;

	if(head == NULL)
		head = newNode;
	else{
		struct Node* check;
		check = lastPointer();
		newNode->next = head;
		head = newNode;
		check->next = head;
	}


}

void displayList(){
	struct Node* current = head;
	if(head == NULL){
		return ; 
	}else{
		int count = 1;
		do{
			printf("Node %d :- %d\n",count,current->data);
			count++;
			current = current->next;
		}while(current != head);
	}
}
struct Node* lastPointer(){
	temp = head;

	do{
		temp = temp->next;
	}while(temp->next != head);


	return temp;
}
