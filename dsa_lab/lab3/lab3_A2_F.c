#include<stdio.h>

int fun(int n){
	int i=n;
	int res=0;
	int j=0;
	
	if(n==0){
		return 1;
	}
	if(n==1){
		return 1;
	}
	
	while(j<=n/2){
		
		
		res+=fun(j);
		
	j++;
//		j=j<<1;
//		i=i/2;
		
	}
  return res;	
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",fun(n));
   return 0;
}
