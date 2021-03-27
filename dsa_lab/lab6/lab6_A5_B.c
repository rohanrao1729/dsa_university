#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define mod 1000000007
typedef long long int lli;
char arr[10000];
int ans[100000];
lli process(){
	scanf("%s",arr);
	lli ans=0;
	lli d=1;
	int i,len=strlen(arr);
	
	for(i=len-1;i>=0;i--){
		if(isalpha(arr[i])!=0){
			d=1;
		}
		if(isdigit(arr[i])!=0){
			ans+=((arr[i]-'0')*d);
			ans=ans%mod;
	        d*=10;	
		}
	}
	return ans;
}
void swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}

void heapify(int arr[],int n,int i){
	int lci=2*i+1,lc;
	int rci=2*i+2,rc;
	int max=i;
	int j=i;
	if(lci<n&&arr[lci]>arr[i]){
		max=arr[lci];
		j=lci;
	}
	if(rci<n&&arr[rci]>max){
	max=arr[rci];
	j=rci;
	}
	if(max!=i){
		swap(&arr[i],&arr[j]);
        heapify(arr,n,max);	
	}
	return;
}
int buildHeap(int arr[],int n){
	int i;
	for(i=n/2;i>=0;i--){
		heapify(arr,n,i);
	}
	return arr[0];
}
void heapSort(int arr[],int n){
	buildHeap(arr,n);
	int i;
	for(i=n-1;i>=1;i--){
		heapify(arr,n,0);
	}
	return ;
}
int removeRoot(int arr[],int n){
	int val=arr[0];
	swap(&arr[0],&arr[n-1]);
	heapify(arr,n-1,0);
	return val;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int i;
	
	for(i=0;i<n;i++){
		ans[i]=process();
	}
//	heapSort(ans,n);
  buildHeap(ans,n);

int val;
lli fans=0;
    for(i=0;i<k;i++){
    val=removeRoot(ans,n-i);
//	printf("%d ",val);
      fans=(fans+val)%mod;
	}
//	for(i=0;i<n;i++){
//		
//		printf("%d ",ans[i]);
//	}
   printf("%lld",fans);
	return 0;
}
