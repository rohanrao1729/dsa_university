#include<stdio.h>
#define MAX 10000


int noOfPairs(int arra[],int arrb[],int k1,int k2,int n){
  int i,j;
  int c=0;
  int val=k1-k2;
  for(i=0;i<n-1;i++){
  	
	  for(j=i+1;j<n;j++)
  	if(arra[i]+arra[j]+val>arrb[i]+arrb[j]){
	    c++;
	  }
  }	
  
  return c;
}
int main(){
	int n,k1,k2;
	int arra[MAX];
	int arrb[MAX];
	scanf("%d%d%d",&n,&k1,&k2);
	
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arra[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&arrb[i]);
	}
	
	int count=noOfPairs(arra,arrb,k1,k2,n);
	
	printf("%d",count);
	
	return 0;
}
