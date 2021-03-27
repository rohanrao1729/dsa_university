#include<stdio.h>
#define MAX 500
void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
	return;
}

int cost (int arr[],int n){
	int i,sos=0,soc=0,diff=0;
	for(i=0;i<n;i++){
		if(i%2==0){
		sos+=(arr[i]*arr[i]);	
		}else{
			soc+=(arr[i]*arr[i]*arr[i]);
		}
		
	}
	diff=sos-soc;
	
	return diff;
}
void reverse(int arr[],int i,int k){
	int j1,j2,temp;
	for(j1=i,j2=k;j1<j2;j1++,j2--){
		 temp=arr[j2];
		 arr[j2]=arr[j1];
		 arr[j1]=temp;
	}
}
void reverse1(int arr[],int i,int n){
	int j;
	int temp;
	for(j=i;j<=(n-i+1)/2;j++){
		 swap(arr[j],arr[n-j]);
	}
	return ;
}


void rotate(int arr[],int n){
	reverse(arr,0,n-2);
	reverse(arr,0,n-1);
	return;
}
void display(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	return;
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[MAX];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	display(arr,n);
	
	int maxcr=cost(arr,n),mincr;
	mincr=maxcr;
	
//	printf("%d",maxcr);
//display(arr,n);
	
	for(i=0;i<n-1;i++){
		rotate(arr,n);
//		display(arr,n);
		int cos=cost(arr,n);
		if(cos>maxcr){
			maxcr=cos;
		}
		if(cos<mincr){
			mincr=cos;
		}
	}
	int ans=maxcr-mincr;
	printf("\n%d",ans);
	
	return 0;
}
