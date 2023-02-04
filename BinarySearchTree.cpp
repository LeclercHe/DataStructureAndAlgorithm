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
int FindMin(PBSTNode root){
	if (root == NULL) {
		printf("tree is empty!\n");
		return -1;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;
}
int FindMinByRecursion(PBSTNode root){
	if (root == NULL) {
		printf("tree is empty!\n");
		return -1;
	}
	else if (root->left == NULL) {
		return root->data;
	}
	return FindMinByRecursion(root->left);
}
int FindMaxByRecursion(PBSTNode root) {
	if (root == NULL) {
		printf("tree is empty!\n");
		return -1;
	}
	else if (root->right == NULL) {
		return root->data;
	}
	return FindMinByRecursion(root->right);
}
int FindMax(PBSTNode root) {
	if (root == NULL) {
		printf("tree is empty!\n");
		return -1;
	}
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
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
	
	printf("min = %d, max = %d", FindMinByRecursion(proot), FindMaxByRecursion(proot));
	return 0;
}