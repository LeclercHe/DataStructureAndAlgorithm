#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

void Reverse(char *C, int len)
{
	stack<char> S;
	for (int i = 0; i < len; i++)
	{
		S.push(C[i]);
	}
	for (int i = 0; i < len; i++)
	{
		C[i] = S.top();
		S.pop();
	}
}
int main()
{
	char C[51];
	printf("Enter a string: ");
	fgets(C,51,stdin);	
	Reverse(C, strlen(C));
	printf("Output: %s", C);
}