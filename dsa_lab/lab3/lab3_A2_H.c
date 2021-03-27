#include<stdio.h>
#define MAX 10000

int aggregateFun(int arr[],int n){
	int c=0;
	int l=1;
	int i;
	int h=1;
	for(i=0;i<n;){
		int aux=0;
		int ai=l;
		while(ai--){
			aux+=arr[i];
			i++;
		}
//		printf("%d ",aux);
		c+=(aux*h);
		h++;
		l=l<<1;
	}
	
	return c;
}
int main(){
	int n;
	int arr[MAX];
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	int ans=aggregateFun(arr,n);
	printf("%d",ans);
	return 0;
}
