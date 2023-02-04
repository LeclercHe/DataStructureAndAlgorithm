#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode {
	int data;
	struct BSTNode* left;
	struct BSTNode* right;
}BSTNode,*PBSTNode;

PBSTNode GetNewNode(int data) {
	PBSTNode ptemp = (PBSTNode)malloc(sizeof(BSTNode));
	ptemp->data = data;
	ptemp->left = NULL;
	ptemp->right = NULL;
	return ptemp;
}
PBSTNode Insert(PBSTNode root,int data) {
	if (root == NULL) {
		root = GetNewNode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else if (data > root->data) {
		root->right = Insert(root->right, data);
	}
	return root;
}
bool Serach(PBSTNode root,int data)
{
	if (root == NULL) {
		return false;
	}
	else if (data == root->data) {
		return true;
	}
	else if(data < root->data){
		return Serach(root->left, data);
	}
	else {
		return Serach(root->right, data);
	}
}
int main()
{
	PBSTNode proot = NULL;
	proot = Insert(proot,100);
	proot = Insert(proot,50);
	proot = Insert(proot,200);
	proot = Insert(proot, 60);
	if(Serach(proot, 50) == 1){
		printf("found\n");
	}
	else{
		printf("no found\n");
	}
	
	return 0;
}