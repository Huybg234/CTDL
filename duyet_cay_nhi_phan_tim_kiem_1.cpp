#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data = data;
		this->left = this->right = NULL;
	}
};

static Node* node;
Node* createNode(Node* node, int data)
{
	if (node == NULL)
		node = new Node(data);
	if (node->data > data)
		node->left = createNode(node->left, data);
	if (node->data < data)
		node->right = createNode(node->right, data);
	return node;
}

void create(int data) { node = createNode(node, data); }

void inorderRec(Node* root)
{
	if (root != NULL) {
		inorderRec(root->left);
		cout << root->data << " ";
		inorderRec(root->right);
	}
}


int main()
{
	int n; 
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	for (int i = 0; i<n; i++) {
		create(a[i]);
	}
	inorderRec(node);
}


