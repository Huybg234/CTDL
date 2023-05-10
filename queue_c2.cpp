#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *next;
};

class Queue{
	public:
		node *start;
		node *end;
		node *np ;
		
		void Push(void){
			int value;
			cout<<"Enter value:"; cin>>value;
			np = new node;
			np->data = value;
			np->next = NULL;
			if(start == NULL){
				start = end = np;
				end->next = NULL;
			}
			else {
				end->next = np;
				end = np;
				end->next = NULL;
	 		}
 		}	
 		
 		int Pop(){
			 int x;
			 if(start == NULL){
			 	cout<<"Empty queue!"<<endl;
			 }
			 else {
				 np = start;
				 x = np->data;
				 start = start->next;
				 delete(np);
				 return(x);
			 }
		}
		
		void Display(void){
			np = start;
			if(np==NULL)
				cout<<"Empty queue!"<<endl;
			else {
				cout<<"Queue:";
				while(np!=NULL){
					cout<<np->data<<setw(3);
					np=np->next;
				}
				cout<<endl;
			}
		}
		
		Queue(void){
			start = NULL;
			end = NULL;
			np = NULL;
		}
		
};

int main(){
	int choice; Queue X;
	do {
		cout<<"1.PUSH"<<endl;
		cout<<"2.POP"<<endl;
		cout<<"3.DISPLAY"<<endl;
		cout<<"0.EXIT "<<endl;
		cin>>choice;
		switch (choice){
			case 1: X.Push(); break;
			case 2: X.Pop(); break;
			case 3: X.Display();break;
			default: cout<<"Wrong choice!"<<endl; break;
		} 
	}while(choice!=0);
	
	return 0;
}
