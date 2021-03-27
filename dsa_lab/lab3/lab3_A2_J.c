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

int minCost(int src,int dest,int n,int d){
	if(src==dest){
		return d;
	}
	int min=MAX;
	int c;
	visited[src]=1;
	Node* ptr=(Node*)arr[src];
    for(;ptr!=NULL;ptr=ptr->next){
    	if(visited[ptr->data]==0){
    		c=minCost(ptr->data,dest,n,d+1);
    		if(c<min&&c>0){
    			min=c;
			}
		}
	}
	visited[src]=0;
	
	return min;
}

int main(){
	int n,m,s,t;
	
	scanf("%d %d %d %d",&n,&m,&s,&t);
	int q=m;
//	printf("%d",m);
    int i;
    initialise(n);
    int a,b;
	for(i=0;i<m;i++){
		
		scanf("%d %d",&a,&b);
		add(a,b);
		add(b,a);
	}
	int d=0;
	
	int cost=minCost(s,t,n,d);
	
	printf("%d",cost*100);
	
	return 0;
}
