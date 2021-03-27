#include<stdio.h>
#define max 10000
	int arr[max];
	int tarr[max];
	int first[max],second[max];
	void preprocess(int n,int k){
		int i;
		first[0]=arr[0];
		second[0]=arr[n-1];
		for(i=n-1;i>=1;i--){
			first[i]=arr[i];
			second[i]=arr[i-1];
		}
		for(i=1;i<k;i++){
			tarr[i]+=tarr[i-1];
		}
		return;
	}
	void query(int ti,int n){
		printf("%d %d\n",first[ti%n],second[ti%n]);
		return;
	}
int main(){
	int n,t;

	scanf("%d %d",&n,&t);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<t;i++){
		scanf("%d",&tarr[i]);
	}
	preprocess(n,t);
	for(i=0;i<t;i++){
		query(tarr[i],n);
	}
	return 0;
}
