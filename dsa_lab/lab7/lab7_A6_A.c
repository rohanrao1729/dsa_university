#include<stdio.h>
#define max 100000
typedef struct node{
	int mod,val;
}Node;

Node arr[max];
int cmpfun(const void* a,const void* b){
	Node* n1=(Node*)a;
	Node* n2=(Node*)b;
	if(n1->mod==n2->mod){
		return n1->val-n2->val;
	}
	return n1->mod-n2->mod;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int i;
	int p;
	for(i=0;i<n;i++){
		Node no;
	    scanf("%d",&p);
	    no.val=p;
	    no.mod=no.val%k;
	    arr[i]=no;
	}
	qsort(arr,n,sizeof(Node),cmpfun);
	
	for(i=0;i<n;i++){
		printf("%d ",arr[i].val);
	}
	return 0;
}
