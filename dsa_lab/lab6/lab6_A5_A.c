#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;

typedef struct Pair{
 int priority;
 int time;
 int ind;
}pair;

void swap(pair** a,pair** b){
	pair* t=*a;
	*a=*b;
	*b=t;
	return;
}

pair* createPair(int i){
	int a,b;
	scanf("%d %d",&a,&b);
	pair* ptr =(pair*)malloc(sizeof(pair));
    ptr->priority=b;
    ptr->time=a;
    ptr->ind=i;
    
    return ptr;
}

void heapify(pair** arr,int n,int i){
  int li=2*i+1;
  int ri=2*i+2;
  int minIn=i;
  if(li<n&&arr[li]->priority<arr[i]->priority){
           minIn=li;
  }
   if(li<n&&arr[li]->priority==arr[i]->priority){
           	  if(arr[li]->time<arr[i]->time){
           	  	minIn=li;
				 }
		 }
   if(ri<n&&arr[ri]->priority<arr[minIn]->priority){
           minIn=ri;
  }
   if(ri<n&&arr[ri]->priority==arr[minIn]->priority){
           	  if(arr[ri]->time<arr[minIn]->time){
           	  	minIn=ri;
				 }
	 }
	 if(minIn!=i){
//       printf("%d %d swap ",arr[i]->ind,arr[minIn]->ind);
	   swap(&arr[i],&arr[minIn]);
       
	   heapify(arr,n,minIn);	 
	 }
	 return;
}

void buildHeap(pair** arr,int n){
	int i;
	for(i=n/2;i>=0;i--){
//		printf("%d",i);
		heapify(arr,n,i);
	}
//	heapify(arr,n,0);
	return;
	
}
void printArray(pair** arr,int n){
	int i;
	for(i=0;i<n;i++){
	printf("%d %d\n",arr[i]->priority,arr[i]->time);
	}
}
pair* deleteRoot(pair** arr,int n){
	pair* val=arr[0];
	swap(&arr[0],&arr[n-1]);
	heapify(arr,n-1,0);
	
	return val;
}
int main(){
	int t,k;
	scanf("%d %d",&t,&k);
	int i;
	pair** arr=(pair**)malloc(t*sizeof(pair*));
	for(i=0;i<t;i++){
		arr[i]=createPair(i);
	}
	
//	printf("%d %d",arr[1]->priority,arr[1]->time);
//	swap(&arr[1],&arr[4]);
//	printf("%d %d",arr[1]->priority,arr[1]->time);
	buildHeap(arr,t);
//	printArray(arr,t);
	for(i=0;i<k;i++){
		pair* val=deleteRoot(arr,t-i);
		
		printf("%d ",val->ind);
	
		
	}
//	
	
	return 0;
}
