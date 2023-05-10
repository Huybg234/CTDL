#include<bits/stdc++.h>
using namespace std;
#define Max 5
struct Stack{
	int top;
	int node[Max];
};

int Empty(struct Stack *s){
	if(s->top==-1){
		return 1;
	}
	return 0;
}

int Full(struct Stack *s){
	if(s->top==Max-1){
		return 1;
	}
	return 0;
}

void Push(Stack *s, int x){
	if(!Full(s)){
		s->top = (s->top) + 1;
		s->node[s->top] = x;
	}
	else{
		cout<<"tran stack"<<endl;
	}
}

int Pop(Stack *s){
	if(!Empty(s)){
		int x = s->node[s->top];
		s->top = (s->top)-1;
		return x;
	}
	else{
		cout<<" stack rong"<<endl;
		return -1;
	}
}

int main(){
	struct Stack s;
	s.top = -1;
	int n, x;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x;
		Push(&s, x);
	}
	cout<<Pop(&s)<<endl;
}
