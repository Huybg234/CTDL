#include<bits/stdc++.h>
using namespace std;

struct node{
	int info;
	struct node *link;
}*Stack;

class stack_list{ 
	 public:
	 node *push(node *, int); 
	 node *pop(node *);
	 void traverse(node *); 
	 stack_list(){
	 	Stack = NULL; 
	 }
};

node *stack_list::push(node *Stack, int item){
	node *tmp; 
	tmp = new (struct node);
	tmp->info = item; 
	tmp->link = Stack;
	Stack = tmp; 
	return Stack;
}

node *stack_list::pop(node *Stack){
	 node *tmp;
	 if (Stack == NULL) 
	 	cout<<"Empty stack!"<<endl;
	 else {
		 tmp = Stack; 
		 cout<<"Element has been deleted: "<<tmp->info<<endl;
		 Stack = Stack->link;
		 free(tmp);
	 }
	 return Stack;
}

void stack_list::traverse(node *Stack){
	 node *ptr; ptr = Stack;
	 if (Stack == NULL) 
		 cout<<"Empty Stack!"<<endl;
	 else {
		 cout<<"Stack: ";
		 while (ptr != NULL) {
			 cout<<ptr->info<<" ";
			 ptr = ptr->link;
		 }
	 }
	 cout<<endl;
}

int main(){
	int choice, item;
	stack_list X;
	do {
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"3. TRAVERSE"<<endl;
		cout<<"0. EXIT"<<endl;
		cin>>choice;
		switch(choice) {
			case 1:
				cout<<"ENTER VALUE: "; cin>>item;
				Stack = X.push(Stack, item);break;
			case 2:
				Stack = X.pop(Stack);break;
			case 3:
				X.traverse(Stack);break;
			default:
				cout<<"WRONG CHOICE"<<endl;break;
		}
	} while(choice!=0);
	return 0;
}
