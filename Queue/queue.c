//implementing using circular array
#include<stdio.h>

struct arrayQueue{
	int front,rear;
	int capacity;
	int *array;
};


struct arrayQueue *Queue(int size){
	struct arrayQueue *Q = (struct arrayQueue*)malloc(sizeof(struct arrayQueue));
	// if(!Q)
	// 	return NULL;
	Q->capacity = size;
	Q->front	= Q->rear = -1;
	Q->array 	= malloc(Q->capacity*sizeof(int));
	// if(!Q->array)
	// 	return NULL;
	return Q;
};

int isEmpty(struct arrayQueue* Q){
	return (Q->front == -1);
}

int isFull(struct arrayQueue* Q){
	return ((Q->rear+1)%(Q->capacity) == Q->front);
}

// int queueSize(){

// }

void enQueue(struct arrayQueue *Q,int data){
	if(isFull(Q)){
		printf("Queue overflow\n");
	}else{
		Q->rear = (Q->rear + 1)%(Q->capacity);
		Q->array[Q->rear] = data;
		if(Q->front == -1)
			Q->front = Q->rear;
	}
}

int deQueue(struct arrayQueue *Q){
	int data;
	if(isEmpty()){
		printf("Queue is Empty\n");
		return 0;
	}else{
		data = Q->array[Q->front];
		if(Q->front == Q->rear)
			Q->front = Q->rear = -1;
		else Q->front = (Q->front+1)%(Q->capacity);
	}
	return data;
}

void deleteQueue(struct arrayQueue *Q){
	if(Q){
		if(Q->array)
			free(Q->array);
		free(Q);
	}
}





int main(){

	struct arrayQueue* queue = Queue(5);
	


	return 0;
}