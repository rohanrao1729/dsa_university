#include<stdio.h>
#include<stdlib.h>
#define N 5000
#define MAX 1000000

typedef struct node{
	int data;
	struct node* next;
}Node;

Node* arr[N];
int visited[N];
void initialise(int n){
	int i;
	for(i=0;i<n;i++){
		arr[i]=NULL;
	}
	return;
}
Node* createNewNode(int dat){
	Node* ptr=(Node*)malloc(sizeof(struct node));
	ptr->data=dat;
	ptr->next=NULL;
	
	return ptr;
}
void add(int a,int b){
	Node* ptr=createNewNode(b);
	if(arr[a]==NULL){
		arr[a]=ptr;
		return;
	}
	Node* temp=(Node*)arr[a];
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=ptr;
	
	return;
}

void dfs(int s){
	visited[s]=1;
	Node* np=arr[s];
	printf("%d ",s);
	while(np!=NULL){
		if(visited[np->data]!=1){
			dfs(np->data);
		}
		np=np->next;
	}
	
	return;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	
	int sr,de;
	int i;
	for(i=0;i<m;i++){
		scanf("%d %d",&sr,&de);
		add(sr,de);
		add(de,sr);
	}
	dfs(1);
	
	
	return 0;
}
