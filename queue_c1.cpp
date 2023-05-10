#include<bits/stdc++.h>
using namespace std;
#define MAX 100

struct Queue{
	int inp;
	int out;
	int node[MAX];
};

void Push(Queue *q, int x){
	if(q->inp == MAX-1){
		cout<<"Tran Queue!"<<endl;
	} else {
		if(q->out==-1) q->out = 0;
		q->inp = q->inp + 1;
		q->node[q->inp] = x;
	}
}

void Pop(Queue *q){
	if(q->out==-1 || q->out>q->inp){
		cout<<"Empty Queue!"<<endl;
		return;
	}
	cout<<"Element has been deleted:"<<q->node[q->out]<<endl;
	q->out = q->out+1;
}

void Display(Queue *q){
	if(q->out==-1){
		cout<<"Queue Empty!"<<endl;
	} else {
		cout<<"Queue: ";
		for(int i=q->out; i<= q->inp; i++){
			cout<<q->node[i]<<" ";
		}
	}
	cout<<endl;
}

int main(){
	struct Queue q;
	q.inp = -1;
	q.out = -1;
	int choice, x;
	do{
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"0. EXIT"<<endl;
		cin>>choice;
		switch(choice){
			case 1: 
				cout<<"Enter Value: ";
				cin>>x;
				Push(&q, x);
				break;
			case 2:
				Pop(&q);
				break;
			case 3:
				Display(&q);
				break;
			default: 
				cout<<"Wrong choice!"<<endl; break;
		}
	} while(choice != 0);
	return 0;
}
