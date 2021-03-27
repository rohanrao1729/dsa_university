#include<stdio.h>
#define MAX 10000

int skill[MAX];
int gold[MAX];
int main(){
	int n,m;
	
	scanf("%d%d",&n,&m);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&skill[i]);
	}
	int ind,val;
	int min=MAX,max=-1;
	for(i=0;i<m;i++){
		scanf("%d %d",&ind,&val);
		gold[ind]=val;
		if(ind<min){
			min=ind;
		}
		if(ind>max){
			max=ind;
		}
	}
	
	for(i=1;i<max;i++){
		gold[i]+=gold[i-1];
	}
	
	for(i=0;i<n;i++){
		printf("%d ",gold[skill[i]]);
	}
	
	return 0;
}
