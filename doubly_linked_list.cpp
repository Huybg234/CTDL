#include<bits/stdc++.h>
using namespace std;

struct Node {
	struct Node *pre;
	int data;
	struct Node *next;
};

void insert_front(struct Node** head, int new_data){
	
	struct Node *new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head);
	new_node->pre = NULL;
	
	if((*head) != NULL) {
		(*head)->pre = new_node;
	}
	
	(*head) = new_node;
}

void insert_end(struct Node** head, int data) {
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = *head;
    if (*head == NULL) {
        newNode->pre = NULL;
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->pre = temp;
}


void displayList(struct Node *node){
	while(node != NULL){
		cout<<node->data<<" <=> ";
		node = node->next;
	}
	if(node==NULL){
		cout<<"NULL";
	}
	cout<<endl;
}

int main(){
	struct Node *head = NULL;
	insert_front(&head, 40);
	insert_front(&head, 50);
	insert_end(&head, 20);
	insert_front(&head, 30);
	insert_front(&head, 10);
	cout<<"Doubly linked list is as follows: "<<endl;
	displayList(head);	
	return 0;
}

