#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
}Node,*PNode;
PNode top = NULL;

void Push(int x)
{
	PNode ptmp = (PNode)malloc(sizeof(Node));
	ptmp->data = x;
	ptmp->next = top;
	top = ptmp;
}
void Pop()
{
	PNode ptmp;
	if (top == NULL) return;
	ptmp = top;
	top = top->next;
	free(ptmp);
}
int Top()
{
	return top->data;
}
bool IsEmpty()
{
	if (top == NULL)
	{
		printf("stack empty!\n");
		return true;
	}
	else
	{
		return false;
	}
}
void Print()
{
	PNode ptmp = top;
	while (ptmp)
	{
		printf("%d ", ptmp->data);
		ptmp = ptmp->next;
	}
	printf("\n");
}
int main()
{
	Push(1); Print();
	Push(5); Print(); 
	Push(9); Print();
	Pop(); Print();

}