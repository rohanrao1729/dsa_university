#include<stdio.h>
typedef long long int lli;


int isPrime(lli n){
	if(n==1){
		return 0;
	}
	if(n==2){
		return 1;
	}
	if(n%2==0){
		return 0;
	}else{
		int i;
		for(i=2;i*i<=n;i++){
			if(n%i==0){
				return 0;
			}
		}
	}
	
	return 1;
}

void func(lli a,lli b,lli count[10]){
	lli i,n;
	for(i=a;i<=b;i++){
		
		if(isPrime(i)){

			n=i;
			while(n>0){
				count[n%10]+=1;
				n/=10;
			}
		}
	}
	
	return;
}
int main(){
	lli a,b;
	lli count[10];
	int k;
	for(k=0;k<10;k++){
		count[k]=0;
	}
	
   scanf("%lld %lld",&a,&b);
   func(a,b,count);
   
   int i,j=0;
   lli max=count[0];
	for(i=0;i<10;i++){
		if(max<count[i]){
			max=count[i];
			j=i;
		}
	}
	
	printf("%d %lld",j,max);
	
   return 0;
}
