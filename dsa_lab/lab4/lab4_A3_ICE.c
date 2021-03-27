#include<stdio.h>
#include<stdlib.h>
#define MAX 100000


static int index=0;
int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int maxDistri(int arr[],int ice[],int k,int n,int m){
	int i,j=0;
	int c=0;
	int l=0;
	int val1,val2;
    for(i=0;i<m;i++){
    	val1=ice[i]-k;
    	val2=ice[i]+k;
    	for(j=l;j<n;j++){
		
    	if(arr[j]<=val2&&arr[j]>=val1){
    		j++;
    		c++;
    		l=j;
    		break;
		}
		if(arr[j]>val2){
			
		}
		if(arr[j]<val1){
			
		}
	}
    	
	}
	return c;
}
int main(){
	int n,m,k;
	int arr[MAX];
	int ice[MAX];
	scanf("%d%d%d",&n,&m,&k);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d",&ice[i]);
	}
	
	qsort(arr,n,sizeof(int),cmpfunc);
	qsort(ice,m,sizeof(int),cmpfunc);
	
	int ans=maxDistri(arr,ice,k,n,m);
	printf("%d",ans);
	
	return 0;
}
