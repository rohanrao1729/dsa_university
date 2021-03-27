#include<stdio.h>
#include<string.h>
char arr1[201];
char arr2[201];
char next1[201];
char next2[201];
int nextFun(int i,int j){
	if(next1[i]-'0'<next2[j]-'0'){
		return 0;
	}else{
		return 1;
	}
}

int find(int i,int j){
	int one=arr1[i]-'0';
	int two=arr2[j]-'0';
	if(one>two){
		return 1;
	}
	if(one==two){
		return nextFun(i,j);
	}
	return 0;
	
}
int main(){
	
	
	char ans[401];
	scanf("%s",arr1);
	scanf("%s",arr2);
	int i=0;
	int j=0;
	int l1=strlen(arr1);
	int l2=strlen(arr2);
	next1[l1-1]=arr1[l1-1];
	for(i=l1-1;i>0;i--){
		if((arr1[i]-'0')==(arr1[i-1]-'0')){
			next1[i-1]=next1[i];
		}else{
		next1[i-1]=arr1[i];
		}
		
	}
	next2[l2-1]=arr2[l2-1];
	for(i=l2-1;i>0;i--){
		if((arr2[i]-'0')==(arr2[i-1]-'0')){
			next2[i-1]=next2[i];
		}else{
		next2[i-1]=arr2[i];
		}
		
	}
	
//		printf("%s",next1);
	i=0;
	j=0;
	while((i+j)<(l1+l2)){
		int val=find(i,j);
		if(val==1){
			ans[i+j]=arr1[i];
			i++;
		}
		if(val==0){
			ans[i+j]=arr2[j];
			j++;
		}
	}
	ans[i+j]='\0';
   printf("%s",ans);
	
	return 0;
}
