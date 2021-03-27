#include<stdio.h>
typedef long long int lli;
int findCubeRoot(int n){
	int c=0;
	if (n<0){
		return -1*findCubeRoot(-n);
	}
	int l=0;
	int r=n;
	int mi;
	while(l<=r){
		mi=(l+r)/2;
		lli val=mi*mi*mi-n;//doesnt work for pretty large numbers
		double e=0.1;
		if(val>0&&val<e){
			return mi;
		}else{
			if(val>0){
				r=mi-1;
			}else{
				l=mi+1;
			}
		}
	}
	
	
	
	return mi;
}

int findSquareRoot(int n){
	int c=0;
	if (n<0){
		return -1*findCubeRoot(-n);
	}
	int l=0;
	int r=n;
	int mi;
	while(l<=r){
		mi=(l+r)/2;
		lli val=mi*mi-n;//doesnt work for pretty large numbers
		double e=0.1;
		if(val>0&&val<e){
			return mi;
		}else{
			if(val>0){
				r=mi-1;
			}else{
				l=mi+1;
			}
		}
	}
	
	
	
	return mi;
}
double abs(double a){
	return a>0?a:-1*a;
}
int findCubeRoot_A(int n){
	if(n<0){
		return -1*findCubeRoot_A(-1*n);
	}
	int ans;
	double rootk=n;
	double rootkp1=0;
	double e=0.2;
	double diff=rootk-rootkp1;
	while(diff>e){
		rootkp1=(2*rootk+n/(double)(rootk*rootk))/3;
	  diff=abs(rootk-rootkp1);
	  rootk=rootkp1;
	  } 
	return ans=(int)rootkp1;
}
int main(){
	int n;
	scanf("%d",&n);
	int ans=findCubeRoot_A(n);
	printf("%d",ans);
	return 0;
}
