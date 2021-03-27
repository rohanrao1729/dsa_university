#include<stdio.h>
#define MAX 500
int arr[MAX][MAX];
int visited[MAX];
int colour[MAX];
int dfs(int i,int n,int c){
	visited[i]=1;
	colour[i]=c;
	printf("%d %d",i,colour[i]);
	int j;
	for(j=0;j<n;j++){
		
		if(arr[i][j]==1){
			if(visited[j]==0){
				printf("%d",j);
			if(dfs(j,n,c^1)==0){
                	return 0;
			}
			}else{
				if(colour[i]==colour[j]){
					return 0;
				}
			}
			
		}
	}
	return 1;
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
	int ans;
//	int k;
//	for(k=0;k<n;k++){
//		if(visited[k]==0){
//			ans=dfs(i,n,0);
//			if(ans==0){
//				printf("need more colors");
//				break;
//			}
//		}
//	}
ans=dfs(0,n,0);
	if(ans==1){
		
		for(i=0;i<n;i++){
			if((colour[i]==0)){
				printf("R");
			}else{
				printf("B");
			}
		}
	}else{
		printf("need more colors");
	}
	
	return 0;
}
