#include<stdio.h>
#include<limits.h>
#define max 10000

int sum(int a[],int x[],int y[],int n,int m){
	int i;
	int s1=0,s2=0;
	for(i=0;i<n;i++){
		if(y[i]>m){
			s1+=a[i];
		}else{
			s2+=a[i];
		}
	}
	if(s1==s2){
		return 1;
	}
	if(s1>s2){
		return -1;
	}
	return 0;
}

int possible(int arr[],int x[],int y[],int n){
	int pre[max];
	int i,j,m;
	int min=INT_MAX,maxi=INT_MIN;
	for(i=0;i<n;i++){
		y[i]=y[i]-x[i];
		if(y[i]<min){
			min=y[i];
		}
		if(y[i]>maxi){
			maxi=y[i];
		}
	}
	i=maxi,j=min;
	while(i>j){
		m=(i+j)/2;
		int val=sum(arr,x,y,n,m);
		if(val==1){
			return 1;
		}
		if(val==-1){
			j=m+1;
		}else{
			i=m-1;
		}
	}
	
	return 0;
}
/***
https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
https://www.geeksforgeeks.org/count-swaps-required-to-sort-an-array-using-insertion-sort/?ref=rp
https://www.geeksforgeeks.org/find-partition-line-such-that-sum-of-values-on-left-and-right-is-equal/
**/
int main(){
	int t;
	scanf("%d",&t);
	int n;
	int arr[max];
	int x[max];
	int y[max];
	while(t--){
		scanf("%d",&n);
		int i;
//		for(i=0;i<n;i++){
//			scanf("");
//		}
		for(i=0;i<n;i++){
			scanf("%d%d%d",&x[i],&y[i],&arr[i]);
		}
		
		if(possible(arr,x,y,n)){
			printf("YES");
		}else{
			printf("NO");
		}
	}
	
	return 0;
}
