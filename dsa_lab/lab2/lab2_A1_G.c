#include<stdio.h>
#define MAX 500
int arr[MAX][MAX];
int visited[MAX];
int sol[MAX];


int dfs(int i,int n){
	int c=1;
	visited[i]=1;
	int j;
	for(j=0;j<n;j++){
		if((arr[i][j]==1)&&(visited[j]!=1)){
			
			c+=dfs(j,n);
		}
	}
	return c;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int i,j;
	int sr,des;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			arr[i][j]=0;
		}
		visited[i]=0;
	}
	for(i=0;i<m;i++){
		scanf("%d %d",&sr,&des);
		arr[sr][des]=1;
		arr[des][sr]=1;
	}


	int no=0,k=0;
	for(i=0;i<n;i++){
		if(visited[i]==0){
			no++;
			sol[k++]=dfs(i,n);
//			printf("%d ",dfs(i,n));
		}
	}
	printf("%d\n",no);
	
	for(i=0;i<no;i++){
		printf("%d ",sol[i]);
	}
	return 0;
}
