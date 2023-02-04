#include<iostream>
#include<queue>
using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};

void Preorder(BSTNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}
void Inorder(BSTNode* root) {
	if (root == NULL) {
		return;
	}
	Inorder(root->left);
	printf("%d ", root->data);
	Inorder(root->right);
}
void Postorder(BSTNode* root) {
	if (root == NULL) {
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ", root->data);
}
BSTNode* GetNewNode(int data) {
	BSTNode* ptemp = (BSTNode*)malloc(sizeof(BSTNode));
	ptemp->data = data;
	ptemp->left = NULL;
	ptemp->right = NULL;
	return ptemp;
}

BSTNode* Insert(BSTNode* root, int data) {
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

int main()
{
	BSTNode* proot = NULL;
	proot = Insert(proot, 100);
	proot = Insert(proot, 50);
	proot = Insert(proot, 200);
	proot = Insert(proot, 60);
	proot = Insert(proot, 51);
	proot = Insert(proot, 33);
	proot = Insert(proot, 1000);
	Preorder(proot);
	printf("\n");
	Inorder(proot);
	printf("\n");
	Postorder(proot);
	return 0;
}