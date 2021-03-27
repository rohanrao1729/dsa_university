#include<stdio.h>
#define MAX 10000
#define MOD 1000000007
typedef long long int lli;

int main(){
	int n,m;
	lli pow[MAX];
	lli mul[MAX];
//    lli ans[MAX];	
	scanf("%d %d",&n,&m);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&pow[i]);
	}
    for(i=0;i<m;i++){
		
		scanf("%d",&mul[i]);
}
for(i=0;i<m;i++){
//	printf("%lld\n",mul[i]);
	mul[i+1]=mul[i+1]*mul[i];
	
}
for(i=0;i<m;i++){
	pow[i]=pow[i]*mul[i];
}
int x=n-m+1;
for(i=m;i<x;i++){
	pow[i]=(pow[i]*mul[i])%MOD;
}
int t=2;
for(i=n-1;i>=x;i--){
	 
	pow[i]=pow[i]*mul[m-1]/mul[m-t];
	pow[i]=pow[i]%MOD;
	t++;
}

for(i=0;i<n;i++){
	printf("%d ",pow[i]);
}
return 0; 
}
