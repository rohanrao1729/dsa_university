#include<stdio.h>
#define N 1000
int arr[N][N];
int visited[N];
void clearVisited(int n){
	int i=0;
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	return;
}
int dfs(int i,int n){
	visited[i]=1;
    int j;
    int c=1;
    for(j=0;j<n;j++){
    	if(arr[i][j]==1&&visited[j]==0){
    		c+=dfs(j,n);
		}
	}
	
	return c;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	
	int i;
	while(m--){
		int src,dest;
		scanf("%d %d",&src,&dest);
		arr[src-1][dest-1]=1;
	}
	int max=0;
	for(i=0;i<n;i++){
		clearVisited(n);
		int c=dfs(i,n);
		if(max<c){
			max=c;
		}
	}
	printf("%d",max);
	
	return 0;
}
