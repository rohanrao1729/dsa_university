#include<stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNewNode(int data){
	struct Node* n=(struct Node*)malloc(sizeof(struct Node));
	n->data=data;
	n->next=NULL;
	return n;
}



void printList(struct Node** n){
	struct Node* p=*n;
	
	while(p!=NULL){
		printf("%d",p->data);
		p=p->next;
	}
	return;
	
}
void add(struct Node** head_ref,int data){
	struct Node* ptr=createNewNode(data);
	
	if(*head_ref==NULL){
		*head_ref=ptr;
//		printList(head_ref);
		return;
	}
//	printList(head_ref);
	struct Node* aux=*head_ref;
	while(aux->next!=NULL){
//		printf("%d ",aux->data);
		aux=aux->next;
	}
	aux->next=ptr;
//	printf("%d ",aux->next);
	
	
	return;
	
}

void reverse(struct Node** head_ref){
//	struct Node* temp,prev,nex;
	struct Node* prev=*head_ref;
	struct Node* temp=prev->next;
	struct Node* nex=NULL;
	if(temp!=NULL){
		nex=temp->next;
	}
	prev->next=NULL;
	while(temp!=NULL){
		temp->next=prev;
		prev=temp;
		*head_ref=prev;
		temp=nex;
		if(nex!=NULL){
		nex=nex->next;
		}
		
		
	}
	
	return;
}

int main(){
	int flag=1;
	int n=0;
	struct Node* head=NULL;
	struct Node* tail=NULL;
//	head=(struct Node*)malloc(sizeof(struct Node));
//	tail=(struct Node*)malloc(sizeof(struct Node));
	scanf("%d",&n);
//	head=createNewNode(n);
	while(n!=-1){
	
//		if(n==-1){
//			flag=0;
//			break;
//		}
//	struct Node* aux=createNewNode(n);
		
//		printf(" %d\n",n);
		add(&head,n);
		scanf("%d",&n);
//		printList(head);

		
		
	}
//	printf("hi");

    printList(&head);
    printf("\n");
    reverse(&head);
	printList(&head);
	
	return 0;
}
