#include<iostream>
#include<queue>
using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};
/******************************Method 1**********************************/
bool IsSubtreeLesser(BSTNode* root,int data){
	if (root == NULL) return true;
	if (   root->data <= data
		&& IsSubtreeLesser(root->left, data)
		&& IsSubtreeLesser(root->right, data))
		return true;
	else
		return false;
}
bool IsSubtreeGreater(BSTNode* root, int data){
	if (root == NULL) return true;
	if (   root->data > data
		&& IsSubtreeGreater(root->left, data)
		&& IsSubtreeGreater(root->right, data))
		return true;
	else
		return false;
}
bool IsBinarySearchTree1(BSTNode* root) {
	if (root == NULL) return true;
	if (   IsSubtreeLesser(root->left, root->data)
		&& IsSubtreeGreater(root->right, root->data)
		&& IsBinarySearchTree1(root->left)
		&& IsBinarySearchTree1(root->right))
		return true;
	else
		return false;
}
/*************************************************************************/
/*******************************Method 2**********************************/
bool IsBinarySearchTreeUnit(BSTNode* root,int min ,int max) {
	if (root == NULL) return true;
	if (   root->data > min
		&& root->data <= max
		&& IsBinarySearchTreeUnit(root->left,min,root->data)
		&& IsBinarySearchTreeUnit(root->right,root->data,max))
		return true;
	else
		return false;
}
bool IsBinarySearchTree2(BSTNode* root) {
	return IsBinarySearchTreeUnit(root, INT_MIN, INT_MAX);
}
/*************************************************************************/
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

	if (IsBinarySearchTree1(proot))
		printf("is BinarySearchTree\n");
	else
		printf("is not BinarySearchTree\n");

	if (IsBinarySearchTree2(proot))
		printf("is BinarySearchTree\n");
	else
		printf("is not BinarySearchTree\n");
	return 0;
}