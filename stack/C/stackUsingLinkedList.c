#include<stdio.h>
struct Node{
	int data;
	struct Node *next;
};
//head becomes top in case of linked list implementation of stack and insertion and deletion takes place at head

struct Node *top = NULL;
void push(int);
void pop();
int peek();
int isEmpty();
void displayStack();


int main(){
	printf("check %d\n",isEmpty());
	push(1);
	push(2);
	push(3);
	printf("check %d\n",isEmpty());

	displayStack();
	pop();
	displayStack();


	return 0;
}

void push(int data){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
	temp->data = data;
	temp->next = top;
	top = temp;
}
void pop(){
	struct Node *temp;
	if(top == NULL)
		return;
	temp = top;
	top = top->next;
	free(temp);
}
int peek(){
	if(top == NULL)
		return;
	return top->data;
}
int isEmpty(){
	return top == NULL;
}
void displayStack(){
	struct Node* temp;
	temp = top;
	if(isEmpty())
		return;
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next; 
	}
}
