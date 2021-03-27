#include<stdio.h>
#define max 1000

int compfun(void* a,void* b){
	return (*(int*)a-*(int*)b);
}
void display(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
//		if(i==n-1){
//			printf("%d",arr[i]);
//		}
		printf("%d ",arr[i]);
		
	}
	return;
}
int binarySearch(int arr[],int n,int val){
	int fi=0,li=n-1,mi;
	int ansi=-1;
	
	while(fi<=li){
		mi=(fi+li)/2;
	   if(arr[mi]<=val){
	   	fi=mi+1;
	   	ansi=mi;
	   }else{
	   	li=mi-1;
	   }
		
		
	}
	return ansi+1;
}

void calculateChoices(int mon[],int cost[],int n,int m){
	
	int i;
	for(i=0;i<n;i++){
	  mon[i]=binarySearch(cost,m,mon[i]);
	}
	
	return;
}
int main(){
	int m,n;
	int cost[max],mon[max];
	scanf("%d%d",&m,&n);
	int i;
	for(i=0;i<m;i++){
		scanf("%d",&cost[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&mon[i]);
	}
	
	qsort(cost,m,sizeof(int),compfun);
	
	calculateChoices(mon,cost,n,m);
	
	display(cost,m);
	
	display(mon,n);
	
	return 0;
}
