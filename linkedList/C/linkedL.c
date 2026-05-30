#include<stdio.h>
struct node{
	int data;
	struct node* next;
};
struct node* head;


void createList(int);
void addNodeAtHead(int);
void addNodeAtEnd(int);
void addNodeNthPos(int,int);
void deleteNodeAtHead();
void deleteNodeAtEnd();
void deleteNthNode(int);
// void nthElementfromLast(int);
void traverseList();
void reverseList();



int main(){

	int size;
	printf("\nEnter the total Nodes :-\n");
	scanf("%d",&size);
	createList(size);
	printf("\nData in the list\n");
	traverseList();
	//Further functions for implementations 
	int switchCase;
	printf("Select the operation to be performed\n");
	printf("\n--------------------------Press---------------------------\n");
	printf("1. Adding node at head\n");
	printf("2. Adding node at end\n");
	printf("3. Adding node at nth\n");
	printf("4. Delete node at head\n");
	printf("5. Delete node at end\n");
	printf("6. Delete node at nthPos\n");	
	printf("7. Reverse linked list\n");	

	scanf("%d",&switchCase);
	
	
	int data,pos;
	

	// printf("head original %d\n", head);
	switch(switchCase){
		case 1:
			printf("Enter data : \n");
			scanf("%d",&data);
			addNodeAtHead(data);
			traverseList();
			break;
		case 2:
			printf("Enter data : \n");
			scanf("%d",&data);
			addNodeAtEnd(data);
			traverseList();
			break;
		case 3:
			printf("Enter data : \n");
			scanf("%d",&data);
			printf("Enter position for node :-\n");
			scanf("%d",&pos);
			addNodeNthPos(pos,data);
			traverseList();
			break;
		case 4:
			deleteNodeAtHead();
			traverseList();
			break;

		case 5:
			deleteNodeAtEnd();
			traverseList();
			break;
		case 6:
			printf("Enter position of node to be deleted");
			scanf("%d",&pos);
			deleteNthNode(pos);
			traverseList();
		case 7:
			reverseList();
			printf("\nLinked list after reversing\n");
			traverseList();
			break;	
		// case 8;
		// 	printf("Enter position from last\n");
		// 	scanf("%d",&pos);
		// 	nthElementfromLast(pos);
		// 	break;	
		default:
			printf("Invalid case:/\n");
			break;		
	}
	return 0;
}


void createList(int n){
	struct node *newNode,*temp;
	int data,i;
	head = (struct node *)malloc(sizeof(struct node));

	//Terminate if memory is not allocated
	if(head == NULL){
		printf("Unable to allocate memory\n");
		exit(0);
	}

	//Input data of node from user
	printf("Enter data for node 1: ");
	scanf("%d",&data);
	head->data = data;
	head->next = NULL;

	//creating n-1 nodes and adding them to list
	temp = head;
	for(i=2;i<=n;i++){
		newNode = (struct node *)malloc(sizeof(struct node));
		// if unable to allocate memory
		if(newNode == NULL){
			printf("Unable to allocate memory");
			break;
		}
		printf("Enter data for node %d: ",i);
		scanf("%d",&data);

		newNode->data = data;
		newNode->next = NULL;

		temp->next = newNode;
		temp 	   = temp->next;
	}
}

void addNodeAtHead(int data){
	struct node* temp;
	temp->data = data;
	temp->next = NULL;
	if(head != NULL)
		temp->next = head;
	head = temp;
}

void addNodeAtEnd(int data){
	struct node *newNode,*temp;
	newNode = (struct node*)(malloc(sizeof(struct node)));
	if(newNode == NULL){
		printf("Unable to allocate memory");
	}else{
		newNode->data = data;
		newNode->next = NULL;
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		temp->next = newNode;
	}
}

void addNodeNthPos(int pos,int data){
	struct node *newNode,*prev,*next;
	newNode = (struct node*)(malloc(sizeof(struct node)));
	if(newNode == NULL){
		printf("Unable to allocate memory");
	}else{
		newNode->data = data;
		newNode->next = NULL;
		prev = head;
		int count=0;
		while(count!=pos-2){
			prev=prev->next;
			count++;
		}
		newNode->next = prev->next;
		prev->next = newNode;
	}
}
void deleteNodeAtHead(){
	head=head->next;
}

void deleteNodeAtEnd(){
	struct node *prev,*current;
	if(head == NULL){
		printf("Given operation cannot be performed");
	}else{
		current=head;
		prev=head;
		while(current->next!=NULL)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
	}
}

void deleteNthNode(int pos){
	struct node *temp,*prev;
	temp = head;
	prev = head;
	while(pos != 1){
		prev = temp;
		temp=temp->next;
		pos--;
	}
	prev->next=prev->next->next;
}

void reverseList(){
	struct node *current,*prev,*next;
	current = head;
	prev = NULL;
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}


void traverseList(){
	struct node *temp;

	if(head == NULL){
		printf("List is empty\n");
		return;
	}

	temp = head;
	while(temp !=  NULL){
		printf("Data = %d\n",temp->data);
		temp = temp->next;
	}
}
// void nthElementfromLast(){
// 	int count=0;
// 	struct node *current;
// 	current = head;
// 	while(current->next != NULL){
// 		count++;
// 		current = current->next;
// 	}

// }