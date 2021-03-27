#include<stdio.h>
#define max 10000
int store[max];
int abs(int x){
	return x>=0?x:-x;
}
void print(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
typedef struct Nodep{
	int data,ind;
}pair;

pair createNode(int data,int ind){
	pair np=(pair*)malloc(sizeof(pair));
	np->data=data;
	np->ind=ind;
	return np;
}

int solve(int arr[],int n,int al,int be){
	int i;
	int ans;
	int diff;
	int k=0;
//	print(arr,n);
	if(n==0){
		return -1;
	}
	if(n==1){
		return arr[0]!=0?arr[0]:-1;
	}
	for(i=0;i<n-1;i+=2){
		diff=arr[i]-arr[i+1];
		if(arr[i]==arr[i+1]){
			store[i]=store[i+1]=0;
			continue;
		}
		if(arr[i]>arr[i+1]){
			store[i]=0;
			ans=arr[i]-al*diff;
		}else{
			store[i+1]=0;
			diff=(-1)*diff;
			ans=arr[i+1]-al*diff;
		}
        ans=abs(ans);	
		arr[k++]=ans;
	}
	if(n%2==1){
		arr[k++]=arr[n-1]+be;
	}
  
  return solve(arr,k,al,be); 
}
int main(){
	int n,alp,bet;
	int arr[max];
	pair arr1[max];
	
	scanf("%d%d%d",&n,&alp,&bet);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		store[i]=arr[i];
		arr1[i]=createNode(arr[i],i);
	}
	
	int ans=solve(arr1,n,alp,bet);
	int in=-1;
	for(i=0;i<n;i++){
		if(store[i]!=0){
			in=i;
			break;
		}
	}
	
printf("%d %d",in,ans);
	
	return 0;
}
