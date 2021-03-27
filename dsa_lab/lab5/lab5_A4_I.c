#include<stdio.h>
#define MOD 1000000007
typedef long long int lli;

lli binExp(lli a,int p){
	lli res=1;
	int n=p;
	while(n){
		if(n&1){
			res=(1LL*res*a)%MOD;
		}
		a=(1LL*a*a)%MOD;
		n>>=1;
	}
	
	return res;
}
lli facto(int n){
	lli ans=1;
	int i=1;
	while(i<=n){
      ans=(1LL*ans*i)%MOD;
	  i++;	
	}
	return ans;
}
lli ncr(int n,int r,lli fact[],lli inv[]){
	if(n==r){
		return 1;
	}
	if(n<r){
		return 0;
	}
	
	lli ans;
	ans=fact[n];
//	printf("%lld",ans);
	ans=(1LL*ans*inv[r])%MOD;
	ans=(1LL*ans*inv[n-r])%MOD;
	
	return ans;
	
}
int main(){
	int n,x,pos;
	scanf("%d%d%d",&n,&x,&pos);
	lli fact[1000];
	lli inv[1000];
    int i;
    fact[0]=1;
    inv[0]=1;
    for(i=1;i<n;i++){
    	fact[i]=(1LL*fact[i-1]*i)%MOD;
    	inv[i]=binExp(fact[i],MOD-2);
	}
    
    int cl=0,cr=0;
	int l=0,r=n;
	int mid;
while(l<r){
mid =(l+r)/2 ;
if(mid<=pos){
if(mid!=pos){
cl++;
}

l= mid+1;
}
else {
	if(pos<mid){
	
cr++;	
r = mid ;
	}
}
}
  lli ansl=(ncr(x-1,cl,fact,inv)*fact[cl])%MOD;
  lli ansr=(ncr(n-x,cr,fact,inv)*fact[cr])%MOD;

//  printf("%lld %lld",cl,cr);
  lli fac=fact[n-cl-cr-1];
  lli fans=(((1LL*ansl*ansr)%MOD)*fac)%MOD;
  printf("%lld",fans);
  
	return 0;
}
