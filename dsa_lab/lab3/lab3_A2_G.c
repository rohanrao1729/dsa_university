#include<stdio.h>
#define MAX 2000

void sort(int arr[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[i]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	return;
}
void printArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}
int targetPair(int arr[],int n,int b){
	int i=0,j=n-1;
	int c=0;
	
	while(i<j){
		if(arr[i]+arr[j]<=b){
			c++;
			i++;
			j--;
		}
		if(arr[i]+arr[j]>b){
			c++;
			j--;
		}
	}
	
	return c;
}
int main(){
	int n;
	scanf("%d",&n);
	int k=n;
	int arr[MAX];
	int B;
	int i=0;
	while(n--){
		scanf("%d ",&arr[i]);
        i++;	
	}
	scanf("%d",&B);
//	printf("%d",B);
//printf("%d",arr[9]);
//	printArray(arr,k);
	sort(arr,k);
//	printArray(arr,k);
	int x=targetPair(arr,k,B);
	printf("%d",x);
	return 0;
}
