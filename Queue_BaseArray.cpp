#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int arr[MAX];
int front = -1;
int rear = -1;

bool IsEmpty(){
	if (front == -1 && rear == -1)
		return true;
	return false;
}
bool IsFull(){
	if ((rear+1)%MAX == front)
		return true;
	return false;
}
void EnQueue(int x){
	if (IsFull()){
		printf("error: queue full!\n");
		return;
	}
	if (IsEmpty()) {
		front = rear = 0;
		
	}
	else {
		rear = (rear + 1) % MAX;
		
	}
	arr[rear] = x;
}
void DeQueue(){
	if (IsEmpty()) {
		printf("error: queue empty!\n");
		return;
	}
	else if(front == rear){
		front = rear = -1;
	}
	else {
		front = (front + 1) % MAX;
	}
}
int Front(){
	if(front == -1)
	{
		printf("error: queue empty!\n");
			return -1;
	}
	return arr[front];
}
void Print(){
	int i;
	int len = (rear - front + MAX) % MAX + 1;
	for (i = 0; i < len; i++) 
	{
		printf("%d ", arr[(front + i) % MAX]);
	}
	printf("\n");
}

int main()
{
	EnQueue(1); Print();
	EnQueue(5); Print();
	EnQueue(6); Print();
	DeQueue(); Print();
	EnQueue(10); Print();
	return 0;
}