#include<stdio.h>

int arrmin[100000];
int arrmax[100000];
int answer[10000];
void swap(int* a,int* b){
	int t=*a;
	*a=*b;
	*b=t;
	return;
}

void minheapify(int arr[],int n,int i){
	int li=2*i+1;
	int ri=2*i+2;
	int minIn=i;
	if(li<n&&arr[li]<arr[i]){
		minIn=li;
	}
	if(ri<n&&arr[ri]<arr[minIn]){
		minIn=ri;
	}
	if(minIn!=i){
	swap(&arr[i],&arr[minIn]);
	minheapify(arr,n,minIn);
	}
	return;
}
void maxheapify(int arr[],int n,int i){
	int li=2*i+1;
	int ri=2*i+2;
	int maxIn=i;
	if(li<n&&arr[li]>arr[i]){
		maxIn=li;
	}
	if(ri<n&&arr[ri]>arr[maxIn]){
		maxIn=ri;
	}
	if(maxIn!=i){
	swap(&arr[i],&arr[maxIn]);
	maxheapify(arr,n,maxIn);
	}
	return;
}

void buildHeap(int arr1[],int arr2[],int n){
	int i;
	for(i=n/2;i>=0;i--){
		maxheapify(arr2,n,i);
		minheapify(arr1,n,i);
	}
	return;
}
int deleteMinMax(int n,int prevsum){
	int min=arrmin[0];
//	printf("%d  ",min);
	int max=arrmax[0];
	int val=max-min;
	arrmin[0]=val;
	 minheapify(arrmin,n,0);
    arrmax[0]=val;
     maxheapify(arrmax,n,0);
     return prevsum-2*min;
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arrmin[i]);
		arrmax[i]=arrmin[i];
	}
	int que,ans;
	int insum=0;
	for(i=0;i<n;i++){
		insum+=arrmin[i];
	}
	buildHeap(arrmin,arrmax,n);
	for(i=0;i<n;i++){
		answer[i]=insum;
		insum=deleteMinMax(n,insum);
        	
	}
	
//		for(i=0;i<n;i++){
//		printf("%d-",arrmax[i]);	
//	}
//	
	while(q--){
		scanf("%d",&que);
		printf("%d ",answer[que]);
	}
//	for(i=0;i<n;i++){
//		printf("%d ",answer[i]);
//	}
	
	return 0;
}
