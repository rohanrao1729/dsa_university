#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1415926535897932384
typedef long long int lli;
typedef struct Pair{
	int x;
	int y;
	
}pair;
int abso(int x,int y){
	return x-y>=0?x-y:y-x;
}
lli computeManhattan(pair* arr,int n){
	int i;
	lli dist=0;
		for(i=0;i<n-1;i++){
		dist+=abso(arr[i].x,arr[i+1].x);
		dist+=abso(arr[i].y,arr[i+1].y);
	}
	dist+=abso(arr[0].x,arr[n-1].x);
	dist+=abso(arr[0].y,arr[n-1].y);
	
	return dist;
}
int cmpFun(const void* a,const void* b){
	
	pair* pa=(pair*)a;
	pair* pb=(pair*)b;
//	double angleA=atan(pa->y/(double)pb->x);
//	double angleB=atan(pb->y/(double)pb->x);
	double angleA=atan2(pa->y,pa->x);
	double angleB=atan2(pb->y,pb->x);
	angleA=angleA*180/PI;	
	angleB=angleB*180/PI;
	if(angleA<0){
		angleA=360+angleA;
	}
	
	if(angleB<0){
		angleB=360+angleB;
	}
//	printf("%f %f ",angleA,angleB);
	if(angleA>angleB){
	return 1;
	}
	if(angleA==angleB){
		return ((pa->y)*(pa->y)+(pa->x)*(pa->x))>((pb->y)*(pb->y)+(pb->x)*(pb->x))?1:-1;
	}
	
	return -1;
}

int main(){
	int n,i,x,y;
	scanf("%d",&n);
	pair* arr=(pair*)malloc(n*sizeof(pair));
	
	for(i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		arr[i].x=x;
		arr[i].y=y;
		
	}
	
//	cmpFun(&arr[0],&arr[1]);

	qsort(arr,n,sizeof(pair),cmpFun);
		
//	for(i=0;i<n;i++){
//		printf("%d %d",arr[i].x,arr[i].y);
//	}
   lli ans=computeManhattan(arr,n);
	printf("%lld",ans);
	free(arr);
	return 0;
}
