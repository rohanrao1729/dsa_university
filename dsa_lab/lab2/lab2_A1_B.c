#include<stdio.h>
typedef struct node{
	struct node* prev;
	char data;
	struct node* next;
}Node;

Node* head=NULL;

Node* createNewNode(int data){
	struct node* n=(struct node*)malloc(sizeof(struct Node));
	n->data=data;
	n->next=NULL;
	return n;
}
void add(int data){
	Node* newNode=createNewNode(data);
	if(head==NULL){
		head=newNode;
	    return;
	}
	
	
	
	
}


int main(){
	int n;
	scanf("%d",&n);
	char ch;
	while(n--){
		scanf("%c",&ch);
//		add(ch);
        
	}
//	checkPalindrome();
}
