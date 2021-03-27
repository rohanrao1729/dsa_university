#include<stdio.h>
#define MAX 1000
#define CAP 30
int arr[MAX][MAX];
int visited[MAX];
int present[30];
int visited1[MAX];
int recurse[MAX];

char stack[CAP];
int tos=-1;
int ind=0;
void push(char ch){
	
	stack[ind++]=ch;
	tos++;
	return;
}
char top(){
	return stack[tos];
}
char pop(){
	char an=stack[tos];
	stack[tos]='0';
	tos--;
	ind--;
	return an;
}
int size(){
	return ind;
}
int dfs(int i){
	visited[i]=1;
	int j;
	for(j=0;j<26;j++){
	
		
		if(arr[i][j]==1&&visited[j]==0){
			
			dfs(j);
				
			
		}
	}
	push(i+'A');
	return 0;
}
int dfsCycle(int i){
	visited1[i]=1;
	if(recurse[i]==1){
		printf("ALIENS ARE CRAZY");
		return 1;
	}
	
	
	recurse[i]=1;
	int j;
	printf("%d ",i);
	for(j=0;j<26;j++){
		
		if(arr[i][j]==1&&visited1[j]==0){
			 
			 if(dfsCycle(j)==1){
			 	return 1;
			 }
			 
			 
		}
	}

	recurse[i]=0;
	return 0;
}


int main(){
	int n;
	scanf("%d\n",&n);
	char ans[30];
	int i;
	char c1,c2,c3;
	for(i=0;i<n;i++){
		scanf("%c %c%*c",&c1,&c2,&c3);
		arr[c1-'A'][c2-'A']=1;
		present[c1-'A']=1;
        present[c2-'A']=1;		
	}
	int pa=0,flag=0;
	for(i=0;i<26;i++){
		if(present[i]==1&&visited[i]==0){
		dfs(i);

		}
		if(visited1[i]==0&&present[i]==1){
				pa=dfsCycle(i);
				
		if(pa==1){
			flag==1;
			break;
		}	
		}
	}
	if(flag==1){
		printf("ALIENS BE CRAZY");
	}else{
	
	int k=0;
	while(size()>0){
		char t=pop();
		ans[k++]=t;
//		printf("%c",t);
	}
	ans[k]='\0';
	printf("%s",ans);
}
	return 0;
}
