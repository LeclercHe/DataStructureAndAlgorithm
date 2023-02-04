#include<iostream>
#include<queue>
using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};
void LevelOrder(BSTNode* root) {
	if (root == NULL) {
		return;
	}
	queue<BSTNode*> Q;
	Q.push(root);
	while(!Q.empty()){
		BSTNode* tmp = Q.front();
		cout << tmp->data << " ";
		if (tmp->left != NULL) { 
			Q.push(tmp->left);
		}
		if (tmp->right != NULL) {
			Q.push(tmp->right);
		}
		Q.pop();
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
	LevelOrder(proot);
	return 0;
}