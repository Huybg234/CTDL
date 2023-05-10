#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

struct Node * head = NULL;

void insert(int new_data){
	Node *new_node = new Node;
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
}

void insert_position(int pos, int value){
	Node *pre = new Node;
	Node *cur = new Node;
	Node *temp = new Node;
	cur = head;
	for(int i=1; i<pos; i++){
		pre=cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur; 
}

void delete_position(int pos){
	if(pos==1){
		head = head->next;
		return;
	}
	Node *cur = new Node;
	Node *pre = new Node;
	cur = head;
	for(int i=1; i<pos; i++){
		pre = cur;
		cur = cur->next;
	}
	pre->next = cur->next;
}

void edit_position(int pos, int value){
	Node *cur = new Node;
	cur = head;
	for(int i=1; i<pos; i++){
		cur = cur->next;
	}
	cur->data = value;
}

void display(){
	struct Node *ptr;
	ptr = head;
	while(ptr != NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

int main(){
	int n, x, k;
	cout<<"Nhap so phan tu: ";
	cin>>n;
	cout<<"Nhap gia tri: ";
	for(int i=0; i<n; i++){
		cin>>x;
		insert(x);
	}
	cout<<"The linked list is: ";
	display();
	
	cout<<"Nhap vi tri can chen: ";	cin>>k;
	cout<<"Nhap gia tri can chen: "; cin>>x;
	insert_position(k, x);
	cout<<"The linked list is after insert: "; 
	display();
	
	cout<<"Nhap vi tri can xoa: "; cin>>k;
	delete_position(k);
	cout<<"The linked list is after delete: ";
	display();
	
	cout<<"Nhap vi tri can sua: "; cin>>k;
	cout<<"Nhap gia tri moi: "; cin>>x;
	edit_position(k, x);
	cout<<"The linked list is after edit: ";
	display();
	
	return 0;
}

