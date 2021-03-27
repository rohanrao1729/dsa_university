#include<stdio.h>

int calcFun(int arr[],int n,int k){
	int i;
	int max=arr[1]-arr[0];
	for(i=2;i<n;i++){
		if(max<arr[i]-arr[i-1]){
			max=arr[i]-arr[i-1];
		}
	}
	int ans=0;
	if(max==0){
		return 0;
	}
	int l=1,r=max;
	int mid=0;
	int insert;
	while(l<r){
		mid=(l+r)/2;
		insert=0;
		for(i=1;i<n;i++){
			insert+=(arr[i]-arr[i-1]-1)/mid;
		}
		
		if(insert>k){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return r;
}
int main(){
	int n,k;
	int arr[10000];
	scanf("%d %d",&n,&k);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int ans=calcFun(arr,n,k);
	printf("%d",ans);
	return 0;
}
