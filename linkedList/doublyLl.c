#include<stdio.h>

void insertAtHead(int);
void insetAtTail(int);
void print();
void reversePrint();
struct node* getNewNode(int);
void formList(int);



struct node{
	int data;
	struct node* prev;
	struct node* next;
};
struct node* head;


int main(){
			int length,switchCase;
			printf("\nEnter the length of the list which you want to form :- \n");
			scanf("%d",&length);
			formList(length);
			int data;
			
			printf("\nEnter data to be inserted to list\n");
			scanf("%d",&data);
			
			printf("\nSelect an option\n");
			printf("\n1.Insert at head\n");
			printf("\n2.Insert at tail\n");
			printf("\n3.Print the list\n");
			scanf("%d",&switchCase);
			switch(switchCase){
				case 1:
					insertAtHead(data);
					print();
					break;
				case 2:
					insertAtTail(data);
					print();
					break;
				default:
					printf("\nInvalid option\n");
					break;	
			
			
		
	}
	return 0;
}

struct node* getNewNode(int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;	
}
void formList(int length){
	head = (struct node *)malloc(sizeof(struct node));
	struct node* newNode;
	if(head == NULL){
		printf("\nCannot form linked list\n");
		return ; 
	}
	int data;
	int i=1;
	while(length--){
		printf("Enter data at node %d :- \n",i);
		i++;
		scanf("%d",&data);
		insertAtTail(data);
		

	}
}


void insertAtHead(int data){
	struct node* newNode = getNewNode(data);
	if(head == NULL){
		head = newNode;
		return;
	}
	head->prev 	  = newNode;
	newNode->next =	head;
	head 		  = newNode;

}
void insertAtTail(int data){
	 struct node* newNode = getNewNode(data);
	 struct node* temp = head;
	 while(temp->next!=NULL){
	 	temp=temp->next;
	 }
	 temp->next = newNode;
	 newNode->prev = temp;
}
void print(){
	struct node* temp = head;
	int i=1;
	while(temp != NULL){
		printf("\nData at node %d :- %d\n",i,temp->data);
		i++;
		temp = temp->next;
	}
}