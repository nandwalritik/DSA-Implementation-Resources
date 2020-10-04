/*
NAME :- ASHUTOSH SAHOO
ROLL NO.:- CS190081
REG. NO. :- 1901227249
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int info;
	struct node *next;
};
struct node *front=0;
struct node *rear=0;
void enqueue()
{
	int x;
	printf("Enter a Number : ");
	scanf("%d",&x);
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=x;
	newnode->next=0;
	if(front==0&&rear==0)
		front=rear=newnode;
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void dequeue()
{
	struct node *temp;
	temp=front;
	if(front==rear)
	{
		printf("Queue Is Empty");
	}
	else
	{
		printf("%d",front->info);
		front=front->next;
		free(temp);
	}
}
void display()
{
	struct node *temp;
	if(front==rear)
	{
		printf("Queue Is Empty");
	}
	else
	{
		temp=front;
		while(temp!=0)
		{
			printf("%d",temp->info);
			temp=temp->next;
		}
	}
}
int menu()
{
	int y;
	printf("Enter Your Choice :");
	printf("\n1. Enqueue");
	printf("\n2. Dequeue");
	printf("\n3. View List");
	printf("\n4. Exit");
	scanf("%d",&y);
	return(y);
}
int main()
{
	while(1)
	{
		switch(menu())
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid Choice"); 
				break;
		}
	getch();
	}
} 
