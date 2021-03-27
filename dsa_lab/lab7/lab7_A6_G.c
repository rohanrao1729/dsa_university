#include<stdio.h>
#define max 10000
int one[max];
int two[max];
static int sti=0;
static int stt=0;

int noOfSetBits(int x){
	int c=0;
	int n=x;
	while(n>0){
		n-=(n&(-n));
		c++;
	}
	return c;
}
int hammingDistance(int a,int b){
	int x=a^b;
	return noOfSetBits(x);
}
int min(int a,int b){
	return a<b?a:b;
}
void recurseFunc(int arr[],int n,int i,int f){
	if(i>=n){
		return;
	}
	if(arr[i]==-1){
		return;
	}
	if(2*i+1>=n){
		if(f==0){
		one[sti++]=arr[i];
		}else{
		two[stt++]=arr[i];
		}
		return;
	}
	

	if(arr[2*i+1]==-1&&arr[2*i+2]==-1){
		if(f==0){
		one[sti++]=arr[i];
		}else{
		two[stt++]=arr[i];
		}
		return;
	}
	
	recurseFunc(arr,n,2*i+1,f);
	if(2*i+2<n){
	recurseFunc(arr,n,2*i+2,f);
	}
	

	
	
	return;
}
int main(){
	int n,a,b;
	int arr[max];
	
	scanf("%d %d %d",&n,&a,&b);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	if(n==1){
		printf("%d",0);
		return;
	}
	int inda=0;
	int indb=0;
	for(i=0;i<n;i++){
		if(arr[i]==a){
			inda=i;
		}
		if(arr[i]==b){
			indb=i;
	}	
	}
	int j;
	i=inda;
	j=indb;
	int ans=hammingDistance(arr[inda],arr[indb]);
    recurseFunc(arr,n,inda,0);
	recurseFunc(arr,n,indb,1);

	for(i=0;i<sti;i++){
		printf("%d ",one[i]);
	}
	printf("\n");
	for(i=0;i<stt;i++){
		printf("%d ",two[i]);
	}
	ans=hammingDistance(one[0],two[0]);
	for(i=0;i<sti;i++){
		for(j=0;j<stt;j++){
			ans=min(ans,hammingDistance(one[i],two[j]));
		}
	}
	printf("%d",ans);
	return 0;
}
