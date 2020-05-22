//Implementing queue using linked list

#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int data;
	struct Queue *next;
};
struct Queue *front = NULL;
struct Queue *rear = NULL;


void enque(int);
void deque();
int isEmpty();
void display();
struct Queue *frontNode();
//front


int main(){

	enque(4);
	enque(5);
	enque(6);
	enque(7);
	display();
	deque();
	display();
	return 0;
}
void enque(int data){
	struct Queue *newNode = (struct Queue*)(malloc(sizeof(struct Queue)));
	newNode->data = data;
	newNode->next = NULL;
	if(frontNode() == NULL){
		front = newNode;
	}
	else{
		struct Queue *temp = front;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		rear = newNode;
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
		
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

struct Queue *frontNode(){
	return front;
}

