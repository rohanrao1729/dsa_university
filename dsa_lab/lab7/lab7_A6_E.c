#include<stdio.h>
#include<stdlib.h>
#define max 1000
#define maxn 100000

typedef struct node{
	int flo1,flo2,ind,nscore;
}Node;
int arr[max][max];
Node ka[maxn];
int bx[max];
int by[max];
int cmpfun(const void* a,const void* b){
	Node* n1=(Node*)a;
	Node* n2=(Node*)b;
	if(n1->nscore==n2->nscore){
		return n1->ind-n2->ind;
	}
	return n1->nscore-n2->nscore;
}
int main(){
	int n,c,d,k;
	scanf("%d %d %d %d",&n,&c,&d,&k);
	int i=0;
	float f1,f2;
	while(i<n){
		scanf("%f %f",&f1,&f2);
		Node no;
		no.flo1=(int)f1;
		no.flo2=(int)f2;
		no.ind=i;
		ka[i]=no;
		i++;
		arr[(int)f1][(int)f2]+=1;
	}
	int j;
	
	for(i=0;i<c;i++){
		for(j=0;j<d;j++){
			bx[i]+=arr[i][j];
		}
	}
	
	for(j=0;j<d;j++){
		for(i=0;i<c;i++){
			by[j]+=arr[i][j];
		}
	}
	for(i=0;i<n;i++){
//		printf("%d",by[ka[i].flo2]);
		ka[i].nscore=bx[ka[i].flo1]*by[ka[i].flo2];
	
	}
	
	qsort(ka,n,sizeof(Node),cmpfun);
	for(i=0;i<k;i++){
		printf("%d ",ka[i].ind);
	}
	return 0;
}
