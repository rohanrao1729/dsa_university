#include<stdio.h>
#define max 10000
int time[max];
int calcNoFromTime(int n,int t){
	int i=0;
	int x=t;
	int ans=0;
	while(i<n){
		ans+=t/time[i];
		i++;
	}
	return ans;
}
int findExact(int n,int k,int l,int r){
	
	int le=l;
	int ri=r;
	int mid;
	while(le<ri){
		mid=(le+ri)/2;
		if(calcNoFromTime(n,mid)==k){
			return mid;
		}else{
			if(calcNoFromTime(n,mid)>k){
				ri=mid;
			}else{
				le=mid+1;
			}
		}
	}
	return le;
}
int main(){
	int n,k;
	
	scanf("%d %d",&n,&k);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&time[i]);
	}
	int tl=1;
	while(1){
		if(calcNoFromTime(n,tl)<=k&&calcNoFromTime(n,2*tl)>=k){
          break;			
		}
		tl=2*tl;
	}
	int ans=findExact(n,k,tl,2*tl);
    printf("%d",ans);
	return 0;
}
