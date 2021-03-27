#include<stdio.h>
#define N 2000
int arr[N][N];
void func(int n){
	int i,j;
	int flag=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j&&arr[i][j]==0&&arr[j][i]==0){
			    flag=1;
				break;
			}
		}
		if(flag==1){
			break;
		}
	}
	
	int n1=i,n2=j;
//	printf("%d %d",n1+1,n2+1);
	for(i=0;i<n;i++){
	   if(arr[n1][i]==1&&arr[i][n2]==1){
	   	   printf("%d %d",n1+1,n2+1);
		   return;
	   }
	}
//	printf("hi");
	for(i=0;i<n;i++){
	   if(arr[n2][i]==1&&arr[i][n1]==1){
	   	   printf("%d %d",n2+1,n1+1);
		   return;
	   }
	}
	int ans=-1;
	printf("%d",ans);
	
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	int t=(n*(n-1)/2)-1;
	while(t--){
		int src,dest;
		scanf("%d %d",&src,&dest);
		arr[src-1][dest-1]=1;
	}
	
	func(n);
	
	return 0;
}
