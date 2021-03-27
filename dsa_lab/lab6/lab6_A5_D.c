#include<stdio.h>
int main(){
	int n;
	long long int ans=0;
	int arr[100000];
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int min=arr[0],max=arr[0];
	for(i=0;i<n;i++){
	 if(arr[i]<min){
	   min=arr[i];	
	 }
	 if(arr[i]>max){
	 	max=arr[i];
	 }
	}
	int c_min=0,c_max=0;
	for(i=0;i<n;i++){
      if(arr[i]==min){
      	c_min++;
	  }	
	  if(arr[i]==max){
	  	c_max++;
	  }
		}
		
		if(min==max){
			ans=(n*(n-1)/2);
		}else{
			ans=c_min*c_max;
		}
		
		printf("%d %lld",max-min,ans);
	return 0;
}
