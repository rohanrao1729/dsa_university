#include<stdio.h>
#define MAX 26
void permute(char arr[], int in,char chset[],int n,int k ){
	if(in==k){
		arr[in]='\0';
		printf("%s\n",arr);
		return;
	}
	
	int i;
	
	for(i=0;i<n;i++){
		arr[in]=chset[i];
		permute(arr,in+1,chset,n,k);
	}
	
	return ;
}
int main(){
	int n,k;
	char arr[MAX];
	char chset[MAX];
	scanf("%d %d",&n,&k);
	
	int i;
//	for(i=0;i<n;i++){
//		scanf("%c ",&chset[i]);
//	}
   scanf("%s",chset);
	
	permute(arr,0,chset,n,k);
	
	return 0;
}
