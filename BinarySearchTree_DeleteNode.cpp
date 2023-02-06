#include<iostream>
#include<queue>
using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};

BSTNode* FindMin(BSTNode* root){
	while (root->left != NULL)
		root = root->left;
	return root;
}
BSTNode* DeleteNode(BSTNode* root, int data){
	if (root == NULL) 
		return root;
	else if (data < root->data) {
		root->left = DeleteNode(root->left, data);
	}
	else if (data > root->data) {
		root->right = DeleteNode(root->right, data);
	}
	else {//found delete node
		//case 1 : no child
		if (root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
		}
		//case 2 : one child
		else if (root->left == NULL) {
			BSTNode* ptemp = root;
			root = root->right;
			free(ptemp);
		}
		else if (root->right == NULL) {
			BSTNode* ptemp = root;
			root = root->left;
			free(ptemp);
		}
		// two child
		else {  
			BSTNode* ptemp = FindMin(root->right);
			root->data = ptemp->data;
			root->right = DeleteNode(root->right, ptemp->data);
		}
	}
	return root;
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


void Inorder(BSTNode* root) {
	if (root == NULL) {
		return;
	}
	Inorder(root->left);
	printf("%d ", root->data);
	Inorder(root->right);
}
int main()
{
	BSTNode* proot = NULL;
	proot = Insert(proot, 100);
	proot = Insert(proot, 50);
	proot = Insert(proot, 200);
	proot = Insert(proot, 60);
	proot = Insert(proot, 550);
	proot = Insert(proot, 33);
	proot = Insert(proot, 1000);
	Inorder(proot);
	printf("\n");
	proot = DeleteNode(proot, 60);
	Inorder(proot);
	return 0;
}