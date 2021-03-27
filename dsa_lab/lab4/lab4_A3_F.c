#include<stdio.h>
#include<stdlib.h>
#define N 10000
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
int dfs(int i){
  int c=1;
  visited[i]=1;
  Node* ptr=(Node*)arr[i];
  while(ptr!=NULL){
  	
  	if(visited[ptr->data]!=1){
  		c+=dfs(ptr->data);
	  }
  	ptr=ptr->next;
  }
  
  return c;
   	
}


int main(){
	int n,m;
	
	scanf("%d%d",&n,&m);
	int q=m;

    int i;
    initialise(n);
    int a,b;
	for(i=0;i<m;i++){
		
		scanf("%d %d",&a,&b);
		add(a,b);
		add(b,a);
		visited[a]=-1;
		visited[b]=-1;
	}
	
	int c=0,val=0;
	int per80 =(int)(0.8*n);
	for(i=0;i<n;i++){
		
		if(visited[i]==-1){
			val+=dfs(i);
//			printf("%d ",i);
			c++;
			if(val>per80){
				
				break;
			}
			
			
		}
		
	}
	
	printf("%d",c);
	
	
	
	
	return 0;
}
