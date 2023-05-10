#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};

class BST {
public:
	node *root; //goc cua cay root
	BST(void){ 
		root = NULL; 
	}
	node *newNode(int value); 
	node* search(node* root, int value); //search node co gia tri data = value
	void preorder(node *root);//Duyet theo thu tu truoc
	void inorder(node *root); //Duyet theo thu tu giua
	void postorder(node *root); //Duyet theo thu tu sau
	node* insert(node* T, int value); //Them 1 node co gia tri value vao cay
	node * minValueNode(node* p); //tim node co gia tri nho nhat
	node* deleteNode(node* root, int data); //Loai bo 1 node tren cay
	void Function(void);
};

node *BST::newNode(int value){ 
	node *temp = new node;
	temp->data = value; 
	temp->left = NULL; 
	temp->right = NULL; 
	return temp; 
}

node*BST:: search(node* root, int value){ 
	if (root == NULL || root->data == value) 
	return root; 
	if (root->data < value)
	return search(root->right, value);
	return search(root->left, value);
}

void BST::preorder(node *root){ 
	if (root != NULL){ 
		cout<<root->data<<setw(3);
		preorder(root->left);
		preorder(root->right);
	}
}

void BST::inorder(node *root){ 
	if (root != NULL){
		inorder(root->left); 
		cout<< root->data<<setw(3);
		inorder(root->right); 
	}
}

void BST::postorder(node *root){ 
	if (root != NULL){ 
		postorder(root->left); 
		postorder(root->right);
		cout<< root->data<<setw(3);
	}
}

node* BST::insert(node* root, int value){
	if (root == NULL) 
		return newNode(value); 
	if (value < root ->data) 
		root ->left = insert(root ->left, value);
	else 
		root ->right = insert(root ->right, value);
	return root;
}

node *BST:: minValueNode(node* p){
	node *current = p;
	while (current->left != NULL)
	current = current->left;
	return current; 
}

node*BST:: deleteNode(node* root, int value){
	if (root == NULL) 
		return root;
	if (value < root->data)
		root->left = deleteNode(root->left, value); 
	else if (value > root->data)
		root->right = deleteNode(root->right, value); 
	else { 
		if (root->left == NULL){ 
			node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			node *temp = root->left;
			free(root);
			return temp;
		}
		node* temp = minValueNode(root->right);
		root->data = temp->data; 
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

void BST::Function(void) {
	node *tmp; int value, choice;
	do {
		cout<<"\nBINARY SEARCH TREE";
		cout<<"\n1. Them node vao cay BST";
		cout<<"\n2. Loai bo node tren cay BST ";
		cout<<"\n3. Tim Node tren cay BST ";
		cout<<"\n4. Duyet Theo thu tu truoc";
		cout<<"\n5. Duyet Theo thu tu giua ";
		cout<<"\n6. Duyet theo thu tu sau ";
		cout<<"\n0. EXIT "<<endl;
		cin>>choice;
		switch(choice) {
			case 1:
				cout<<"\nGia tri node can them:"; cin>> value;
				root = insert(root, value);break;
			case 2:
				cout<<"\nGia tri node can loai:"; cin>> value;
				root = deleteNode(root, value);break;
			case 3:
				cout<<"\nGia tri node can tim:"; cin>> value;
				tmp = search(root, value);
				if (tmp==NULL) cout<<"\nKhong tim thay node!";
				else cout<<"\nNode "<< tmp->data<<" Ton tai";
				break;
			case 4: preorder(root); break;
			case 5: inorder(root); break;
			case 6: postorder(root); break;
			default:
				if(choice!=0) cout<<"\nLua chon sai"; break;
		}
		cout<<"\nDuyet truoc:"; preorder(root);
		cout<<"\nDuyet giua:"; inorder(root);
		cout<<"\nDuyet sau:"; postorder(root);
	}while(choice!=0);
}


int main(){
	BST X; X.Function();
	return 0;
}
