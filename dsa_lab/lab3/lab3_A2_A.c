#include<stdio.h>
int numOfDiv(int n){
	int i;
	int c=0;
	for(i=2;i*i<=n;i++){
		if(n%i==0){
		  if(i*i==n){
		  	c+=1;
		  }else{
		    c+=2;
		  }
		}
		
		if(c>=2){
			return 1;
		}
	}
	return 0;
}
int ans(int n){
	int i;
	int div1,div2;
	int c=0;
	for(i=2;i<=n/2;i++){
		
		if(n%i==0&&c==0){
			div1=n/i;
			c++;
			continue;
		}
		if(n%i==0&&c==1){
			div2=n/i;
            c++;
            break;
		}
		
	}
	
	return div1+div2;
}

int funcGhot(int n){
	int no=numOfDiv(n);
//	printf("%d",no);
	if(no==0){
		return n;
	}
	return ans(n);
}
int main(){
	int n;
	scanf("%d",&n);
	int x=funcGhot(n);
	printf("%d",x);
	return 0;
}
