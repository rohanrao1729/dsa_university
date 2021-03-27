#include<stdio.h>
#include<math.h>
#define MAX 1000
#define COL 20
int arr[MAX];
int calcFights(char str[][COL],int n,int c){
	
	int i=0,j;
	int p;
	int fp=0;
	for(;i<n;i++){
		p=0;
		for(j=0;j<i;j++){
			if(str[i][0]==str[j][0]){
				p++;
			}
			
//			if(p==0){
//				arr[i]=0;
//			}
			
		}
		if(p<c){
				arr[i]=p;
			}
			if(p>=c){
				arr[i]=p%c;
				fp+=floor(p/c);
			}
	}
	
	return fp;
}
int main(){
	int n,c;
	scanf("%d %d",&n,&c);
	char str[MAX][COL];
	int i;
	for(i=0;i<n;i++){
		scanf("%s",str[i]);
	}
	int fight=calcFights(str,n,c);
	printf("%d",fight);
	
	return 0;
	
}
