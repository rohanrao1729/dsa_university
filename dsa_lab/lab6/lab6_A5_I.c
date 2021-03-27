#include<stdio.h>

void swap(int* a,int* b){
	int t=*a;
	*a=*b;
	*b=t;
	return;
}
void maxheapify(int arr[],int n,int i){
	int li=2*i+1;
	int ri=li+1;
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

void buildHeapi(int arr[],int n){
	int i;
	for(i=n/2;i>=0;i--){
		maxheapify(arr,n,i);
	}
	return;
}

int replaceRoot(int arr[],int n){
	int val=arr[0];
	arr[0]=val/3;
//	print(arr[0]);
	maxheapify(arr,n,0);
	return val;
}
int main(){
	int n,d;
	int i;
	int arr[100001];
	scanf("%d %d",&n,&d);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	buildHeapi(arr,n);
//	for(i=0;i<n;i++){
//		printf("%d",arr[i]);
//	}
	int ans=0;
	int val;
	for(i=0;i<d;i++){
		val=replaceRoot(arr,n);
		ans+=val;
	}
	printf("%d",ans);
	
	return 0;
}
