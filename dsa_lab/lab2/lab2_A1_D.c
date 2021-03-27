#include<stdio.h>
#define MAX 25

int power(int n,int x){
	if(x==0){
		return 1;
	}
	int res=1;
	int val=power(n,x/2);
	val=val*val;
	if(x%2){
		res=res*n*val;
	}else{
		res=res*val;
	}
	return res;
}
int solveSubset(int arr[],int n,int b){
   	int i,j;
   	int p=power(2,n);
	int max=0;
	int poe; 
	int aux=0;
	int count=0,num; 
	for(i=0;i<p;i++){
        poe=0;
        num=0;
		for(j=0;j<n;j++){
			if(i&(1<<j)){
			poe+=arr[j];
			num++;
			}
		}
		if(num>=count&&poe<=b){
			count=num;
			max=poe;
			aux=i;
			
		}
	}
	
	return count;
} 
int main(){
	int b;
	scanf("%d",&b);
	int n;
	scanf("%d",&n);
	int arr[MAX];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	

 int fans=solveSubset(arr,n,b);
// int c=0;
// for(i=0;i<n;i++){
// 	if(fans&(1<<i)){
// 		c++;
//	 }
// }


printf("%d",fans);


}
