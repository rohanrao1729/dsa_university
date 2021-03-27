#include<stdio.h>
#define max 10000
int arr[max];
int maxpre[max];
int minsuff[max];
int main(){
	int n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	  	scanf("%d",&arr[i]);
	}
	maxpre[0]=arr[0];
	minsuff[n-1]=arr[n-1];
	for(i=1;i<n;i++){
		if(arr[i]>maxpre[i-1]){
			maxpre[i]=arr[i];
		}else{
			maxpre[i]=maxpre[i-1];
		}
	}
	for(i=n-2;i>=0;i--){
		if(arr[i]<minsuff[i+1]){
			minsuff[i]=arr[i];
		}else{
			minsuff[i]=minsuff[i+1];
		}
	}
	int count=1;
	
	for(i=n-1;i>=1;i--){
		if(minsuff[i]>=maxpre[i-1]){
			count++;
		}
	}
	printf("%d",count);
	return 0;
}
