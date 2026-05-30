#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1000
int top = -1;
char stack[MAX_SIZE];
void push(char);
void pop();
int isEmpty();
int isFull();
char peek();
void displayStack();
int unpair(char,char);


int main(){
	char s[20];
	printf("Enter enter string to be checked for balanced bracket\n");
	scanf("%s",s);
	

	int flag=1;
	for(int i=0;i<strlen(s);i++){
			if(s[i]=='(' || s[i]=='{' || s[i]=='[')
				push(s[i]);
			else if(s[i]==')' || s[i]=='}' || s[i]==']'){
				if(!unpair(peek(),s[i])){
					flag=0;
					break;
				}
				else{
					pop();
					// printf("After operation\n");
					// displayStack(); 
				}
				
			if(!isEmpty() && i == strlen(s)-1){
				flag = 0;
			}		
		}
	}
	if(flag){
		printf("balanced brackets\n");
	}else{
		printf("Unbalanced brackets\n");
	}
}

void push(char data){
	if(isFull()){
		printf("StackOverflow\n");
		return;
	}
	stack[++top] = data;
}
void pop(){

	top--;
}
int isEmpty(){
	return top == -1;
}
int isFull(){
	return top == MAX_SIZE-1;
}
char peek(){
	if(isEmpty()){
		printf("Stack is Empty\n");
		return -1;
	}

	return stack[top];
}
void displayStack(){
	for(int i=top;i>=0;i--)
		printf("%c->",stack[i]);
	printf("\n");
}

int unpair(char a,char b){
	return (a == '(' && b == ')')
			||(a == '{' && b == '}')
			||(a == '[' && b == ']');
}