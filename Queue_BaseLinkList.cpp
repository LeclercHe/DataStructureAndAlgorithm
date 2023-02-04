#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node,*PNode;
PNode front = NULL;
PNode rear  = NULL;

void EnQueue(int x){
	PNode ptemp = (PNode)malloc(sizeof(Node));
	ptemp->data = x;
	ptemp->next = NULL;
	if(front ==NULL && rear == NULL)
	{
		front = rear = ptemp;
		return;
	}
	rear->next = ptemp;
	rear = ptemp;
}
void DeQueue() {
	PNode ptemp = front;
	if (front == NULL)
		return;
	if (front == rear)
		front = rear = NULL;
	else 
		front = front->next;
	free(ptemp);
}
void Print()
{
	PNode ptemp = front;
	while (ptemp != NULL)
	{
		printf("%d ", ptemp->data);
		ptemp = ptemp->next;
	}
	printf("\n");
}

int main(){
	EnQueue(2); Print();
	EnQueue(6); Print();
	EnQueue(10); Print();
	DeQueue(); Print();
	EnQueue(0); Print();

	return 0;
}
