#include<stdio.h>
#include<stdlib.h>
#define max 10000

int cmpfun(const void* a,const void* b){
 return *(int*)a-*(int*)b;
}
int main(){
	int n,k,x;
	int noSt[max];
	int r[max];
	int aux[max];
	int sum[max];
	scanf("%d %d %d",&n,&k,&x);
	int i;
	int ans1=0,ans2=0;
	for(i=0;i<n;i++){
		scanf("%d",&noSt[i]);
		ans1+=noSt[i];
	}
	for(i=0;i<k;i++){
		scanf("%d",&r[i]);
		aux[i]=noSt[r[i]];
		ans1-=noSt[r[i]];
	}
	
	
//	qsort(aux,k,sizeof(int),cmpfun);
	int j=k-1;
//	int val=x;
//	ans2=ans1;
//	while(val>0&&j>=0){
//		ans2+=aux[j];
//		val--;
//		j--;
//	}
int maxim;
for(i=0;i<k;i++){
	for(j=0;j<x&&(i+j)<k;j++){
	  sum[i]+=noSt[r[i+j]]; 
	}
}
for(i=0;i<k;i++){
	if(sum[i]>maxim){
		maxim=sum[i];
	}
}	
	ans2=ans1+maxim;
	printf("%d %d",ans1,ans2);
	return 0;
}
