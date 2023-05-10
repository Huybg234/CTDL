#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right; 
	int height; 
};

class AVL_Tree { 
public:
	node *root; 
	AVL_Tree(void){ 
		root = NULL;
	}
	int max(int a, int b); 
	node* newNode(int value); 
	int height(node *N); 
	node* search(node* root, int value);
	node * rightRotate(node *y); 
	node * leftRotate(node *x);
	int getBalance(node *N);
	node* insert(node* node, int data);
	node* deleteNode(node* root, int key);
	void preOrder(node *root);
	void inOrder(node *root);
	void postOrder(node *root); 
	node *minValueNode(node* root);
	void Function(void){ 
};

int AVL_Tree ::max(int a, int b){
	return (a > b)? a : b;
}

int AVL_Tree ::height(node *N){ 
	if (N == NULL)
	return 0;
	return N->height;
}

node* AVL_Tree ::newNode(int value){ 
	node* p = new node;
	p->data = value;
	p->left = NULL;
	p->right = NULL;
	p->height = 1;
	return(p);
}

node* AVL_Tree ::search(node* root, int value){
	if (root == NULL || root->data == value)
	return root;
	if (root->data < value)
	return search(root->right, value);
	return search(root->left, value);
}

node * AVL_Tree ::rightRotate(node *y){ 
	node *x = y->left; 
	node *T2 = x->right; 
	x->right = y; 
	y->left = T2; 
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	return x; 
}

node * AVL_Tree ::leftRotate(node *x){
	node *y = x->right; 
	node *T2 = y->left; 
	y->left = x; 
	x->right = T2; 
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;
	return y;
}

int AVL_Tree ::getBalance(node *N){
	if (N == NULL) 
	return 0; 
	return height(N->left) - height(N->right); 
}

node* AVL_Tree ::insert(node* node, int data){
	if (node == NULL)
		return(newNode(data));
	if (data < node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	node->height = max(height(node->left), height(node->right)) + 1;
	int balance = getBalance(node);
	if (balance > 1 && data < node->left->data) 
		return rightRotate(node);
	if (balance < -1 && data > node->right->data)
		return leftRotate(node);
	if (balance > 1 && data > node->left->data){
		node->left = leftRotate(node->left);
		return rightRotate(node); 
	}
	if (balance < -1 && data < node->right->data){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
} 


void AVL_Tree ::preOrder(node *root){
	if(root != NULL) {
		cout<<root->data<<endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}

void AVL_Tree ::inOrder(node *root){
	if(root != NULL) {
		inOrder(root->left);
		cout<<root->data<<endl;
		inOrder(root->right);
	}
}

void AVL_Tree ::postOrder(node *root){ 
	if(root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		inOrder(root->right);
	}
}

node * AVL_Tree ::minValueNode(node* root){
	node* current = root;
	while (current->left != NULL)
		current = current->left;
	return current;
}


node* AVL_Tree ::deleteNode(node* root, int key){
	if (root == NULL)
		return root;
	if ( key < root->data )
		root->left = deleteNode(root->left, key);
	else if( key > root->data )
		root->right = deleteNode(root->right, key);
	else { 
		if( (root->left == NULL) || (root->right == NULL) ){
			node *temp = root->left ? root->left : root->right;
			if(temp == NULL){ 
				temp = root;
				root = NULL;
			}
			else 
				*root = *temp;
			free(temp);
		}
		else { 
			node* temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	if (root == NULL)
		return root; 
	root->height = max(height(root->left), height(root->right)) + 1;
	int balance = getBalance(root);
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);
	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
	}
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root); 
	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root); 
	}
	return root;
}


void AVL_Tree ::Function(void){ 
	node *tmp;
	int data, choice;
	do {
		cout<<"\n1.Them node vao cay AVL";
		cout<<"\n2.Loai node tren cay AVL";
		cout<<"\n3.Tim node tren cay AVL";
		cout<<"\n4.Duyet theo thu tu truoc";
		cout<<"\n5.Duyet theo thu tu giua";
		cout<<"\n6.Duyet theo thu tu sau";
		cout<<"\n0.Thoat khoi chuong trinh";
		cin>>choice;
		switch(choice) {
			case 1:
				cout<<"\n Gia tri node can them:"; cin>>data;
				root = insert(root, data);break;
			case 2:
				cout<<"\n Gia tri node can loai:"; cin>>data;
				root = deleteNode(root, data);break;
			case 3:
				cout<<"\n Gia tri node can tim:"; cin>>data;
				tmp = search(root, data);
				if (tmp==NULL) cout<<"\n Node khong co tren cay";
				else cout<<"\n Node "<<tmp->data<<" Ton Tai";
				break;
			case 4:
				preOrder(root); break;
			case 5:
				inOrder(root); break;
			case 6:
				postOrder(root); break;
			default:
				if(choice!=0) cout<<"\n Lua chon sai";
				break;
		}
		cout<<"\nDuyet truoc:"; preOrder(root);
		cout<<"\nDuyet giua:"; inOrder(root);
		cout<<"\nDuyet sau:"; postOrder(root);
	} while(choice!=0);
} 

int main(){
	AVL_Tree X;
	X.Function();
	return 0;
}
