#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	char dec;
	int ans=0,curr=0;
	int n1;
	int a;
	
	while(n--){
//	    scanf("%c%d%*[^\n]d",&dec,&n1,&a);
		scanf("%c%d\n",&dec,&n1,&a);
//		printf("%d",dec);
		if(dec=='E'){
		   
//	       scanf("%d ",&n1);		
		   curr+=n1;
		   if(curr>ans){
		   	ans=curr;
		   }
		}
		if(dec=='L'){
//			scanf("%d ",&n1);
			curr-=n1;
			int i;
//			for(i=0;i<n1;i++){
////				scanf("%d",&n1);
////				printf("%d",n1);
//			}
		}
		
	}
	
	printf("%d",ans);
	
	return 0;
}
