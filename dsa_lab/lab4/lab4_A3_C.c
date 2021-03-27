#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

int cmpfunc(const void* a,const void* b){
	return (*(int*)a-*(int*)b);
}

int max(int a,int b){
	if(a>=b){
		return a;
	}
	
	return b;
}

int isPossible(int arr[],int k,int n,int mid){
	int i;
	int l=0;
	int count=1;
	for(i=0;i<k;i++){
		if((arr[i]-arr[l])>=mid){
			count++;
			l=i;
		}
		
	}
//	printf("\n%d %d",mid,count);
	if(count>=n){
		return 1;
	}
	
	
	return 0;
}
int largeMinDist(int arr[],int k,int n){
	int fi=0,li=arr[k-1]-arr[0],mi;
	int res=0;
	while(fi<=li){
		mi=(fi+li)/2;
//		printf("%d",mi);
	    if(isPossible(arr,k,n,mi)==1){
	    	res=mi;
			fi=mi+1;
		}else{
			li=mi-1;
		}	
	}
	
	return res;
  
}

int main(){
	int n,k;
	int arr[MAX];
	scanf("%d%d",&n,&k);
	int i;
	for(i=0;i<k;i++){
		scanf("%d",&arr[i]);
	}
	
	qsort(arr,k,sizeof(int),cmpfunc);
	int res=largeMinDist(arr,k,n);

	
	
	printf("%d",res);
	
	return 0;
}
