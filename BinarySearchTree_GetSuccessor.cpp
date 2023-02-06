#include<iostream>
using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};

BSTNode* Find(BSTNode* root, int data) {
	if (root == NULL) return NULL;
	if (root->data == data) {
		return root;
	}
	else if(data < root->data){
		return Find(root->left, data);
	}
	else {
		return Find(root->right, data);
	}
}
BSTNode* FindMin(BSTNode* root) {
	if (root == NULL) return root;
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}
BSTNode* GetSuccessor(BSTNode* root, int data){
	BSTNode* current = Find(root, data);
	if (root == NULL)
		return root;
	//Node have right subtree
	if (current->right != NULL) {
		return FindMin(current->right);
	}
	else {//Node not right subtree
		BSTNode* successor = NULL;
		BSTNode* ancestor = root;
		while (ancestor != current) {
			if(current->data < ancestor->data){
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}

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
	printf("%d",*GetSuccessor(proot, 50));
	return 0;
}