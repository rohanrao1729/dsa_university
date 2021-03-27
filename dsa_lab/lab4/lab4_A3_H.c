#include<stdio.h>
#include<stdlib.h>
#define MA 1000

int arr[MA];
int auth[MA];
int ans[MA][MA];

int cmpfun(const void*a,const void* b){
	 return *(int*)a-*(int*)b;
}

void binarySearch(int i,int n,int m){
	int h=0;
	qsort((ans+i),m,sizeof(int),cmpfun);
	int li=0,ri=m-1,mi;
	int j;
    while(li<=ri){
    	mi=(li+ri)/2;
    	if(ans[i][mi]>=m-mi){
    		h=m-mi;
    		ri=mi-1;
		}else{
		  li=mi+1;
		}
	}
	
	ans[i][0]=h;
	return;
}
int main(){
	int a,p,c;
	scanf("%d%d%d",&a,&p,&c);
	
	int i,ci,cj;
	for(i=0;i<p;i++){
		scanf("%d",&auth[i]);
	}
	for(i=0;i<c;i++){
		scanf("%d%d",&ci,&cj);
		arr[cj]+=1;
	}
	
	for(i=0;i<p;i++){
		ans[auth[i]][i]=arr[i];
	}
	
//	for(i=0;i<p;i++){
//		printf("%d",arr[i]);
//	}
//	int j;
//	printf("\n");

	
	for(i=0;i<a;i++){
//		printf("%d",i);
		binarySearch(i,a,p);
		
	}

//	for(i=0;i<a;i++){
//		for(j=0;j<p;j++){
//		
//		printf("%d ",ans[i][j]);
//  }
//      printf("\n"); 
//
//	}

	for(i=0;i<a;i++){
		
		printf("%d ",ans[i][0]);
	}
	


	return 0;
}
