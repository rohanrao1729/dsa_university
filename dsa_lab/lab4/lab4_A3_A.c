#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
int visited[MAX];

//wrong solution test case 
//5 4 5
//20 25 50 65 75 
//25 45 70 60

// 3 2 5
// 10 20 30
// 15 65
//15 25                      

static int index=0;
int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int bsLessThan(int arr[],int n,int val,int fi,int l){
 int li=fi,ri=l;
 int mi;

 while(li<=ri){
 	mi=(li+ri)/2;
 	
 	if(arr[mi]>=val){
	  ri=mi-1;
	 }else{
	 	li=mi+1;
	 } 
 }
 
 return li-fi;
}
int bsGreaterThan(int arr[],int n,int val,int fi,int li){
	int l=fi, h =li; 
    while (l<=h) { 
        int mid =(l+h)/2; 
        if(arr[mid]<=val){
		 
            l = mid+1;} 
        else{
		h = mid-1;} 
    } 
//    if(h<0){
//    	return 0;
//	}
    return h-fi; 
}
int range(int arr[],int n,int val1,int val2,int fi,int li){
  int no1=bsLessThan(arr,n,val1,fi,li);
  int no2=bsGreaterThan(arr,n,val2,fi,li);
//  printf("%d %d %d",no1,no2,no2-no1+1);
  return no2-no1+1;	
}
//trying for a solution of(nlogn+mlogm+nlogm)  order 10^6
int maxDistr(int arr[],int ice[],int k,int n,int m){
	int i,j=0;
	int c=0;
	int indic=0;
	int r=0;
	int val1,val2;
	for(i=0;i<m;i++){
		val1=ice[i]-k;
		val2=ice[i]+k;
	    r=range(arr,n,val1,val2,index,n-1);
//	    printf("%d\n",index);
	    
	    if(r>0){
		c++;
		index++;
		}
	}
	
	return c;
}
// brute force O(n*m) 10^10
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
	int ans1=maxDistr(arr,ice,k,n,m);
	int ans2=maxDistri(arr,ice,k,n,m);
	printf("%d",ans1);
	
	return 0;
}
