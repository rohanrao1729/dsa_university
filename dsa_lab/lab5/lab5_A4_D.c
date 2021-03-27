#include<stdio.h>
#define max 1000

float in[max];
float out[max];
void makeZero(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
	arr[i]=0;
	}
	
}
typedef struct Node{
float x;
int y;
}pair;


void printArr(float arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%.2f ",arr[i]);
	}
	printf("\n");
}
void print(pair arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i].y);
	}
	
}



int cmpfun(const void* a,const void* b){
	float one=((pair*)a)->x;
	float two=((pair*)b)->x;
	
	return one>=two?-1:1;
}
int main(){
	int n,e,s,i;
	
	scanf("%d%d%d",&n,&e,&s);
	int sr,de;
	
	float p;
	
	makeZero(in,n);
	makeZero(out,n);
	in[s]=1;
	for(i=0;i<e;i++){
		scanf("%d%d%f",&sr,&de,&p);
		
		
		if(sr==s){
			in[de]=p;
		}else{
			in[de]=in[sr]*p;
		}
		out[sr]+=p;
	}
	pair* ans=(pair*)(malloc(n*sizeof(pair)));
	for(i=0;i<n;i++){
		out[i]=(1-out[i])*in[i];
		ans[i].x=out[i];
		ans[i].y=i;
	}
	qsort(ans,n,sizeof(pair),cmpfun);
//	printArr(in,n);
//	printArr(out,n);
	print(ans,n);
	
	return 0;
}
