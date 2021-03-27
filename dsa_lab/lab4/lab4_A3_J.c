#include<stdio.h>
#define MAX 500
#define maxi 100000

int arr[MAX][MAX];
int visited[MAX];
int parent[MAX];
void initialise(int n){
	int i;
	for(i=0;i<n;i++){
		parent[i]=-1;
	}
}

//int parent(int n){
//	return parent[n];
//}
int find(int n){
	if(parent[n]==-1){
		return n;
	}
	return find(parent[n]);
}
void unionFind(int a,int b){
	int s1=find(a);
	int s2=find(b);
	 
	 if(s1!=s2){
	 	parent[s1]=s2;
	 }
	return;
}

int minSpanCost(int n){
	int noOfV=1;
	int min;
	int i,j;
	int a,b;
	int cost=0;
	while(noOfV<n){
		 min=maxi;
		for(i=0;i<n-1;i++){
           		
			for(j=i+1;j<n;j++){
				
				
				if(find(i)!=find(j)&&arr[i][j]>=1&&arr[i][j]<min){
					min=arr[i][j];
					a=i;
					b=j;
				}
			
			}
			
		}
//		printf("%d ",min);
		cost+=min;
		unionFind(a,b);
		arr[a][b]=0;
		noOfV++;
	}

	
	return cost;
	
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	initialise(n);
	int sr,dest,w;
	while(m--){
		scanf("%d%d%d",&sr,&dest,&w);
		arr[sr][dest]=w;
		arr[dest][sr]=w;
	}
	
	
	int cost=minSpanCost(n);
	printf("%d",cost);
	
	return 0;
	
}
