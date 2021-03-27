#include<stdio.h>
//#define Max 501
int ans[10];
int k=0;
int n;
int funcRecurse(int i,int j){
	char ch;
	scanf("%c",&ch);
	if(j>=n){
		return 0;
	}
	switch(i){
	case 0:
		if(ch=='b'){
			i++;
		}else{
			i=0;
		}
		break;
	case 1:
	   if(ch=='a'){
	   	  i++;
	   }else{
	   	i=0;
	   }
	   break;	
	case 2:
	   if(ch=='a'){
	   	i++;
	   }else{
	   	i=0;
	   }
	   break;  
	case 3:
		if(ch=='b'){
			i++;
		}else{
			i=0;
		}    
	   break;
     }
     if(i==4){
     	ans[k++]=j-3;
     	i=1;
     	return 1+funcRecurse(i,j+1);
     	}
//     	printf("hi %d",i);
    
     
   return  funcRecurse(i,j+1);
}
int main(){
	
	scanf("%d ",&n);
	int t=funcRecurse(0,0);
	int i;
	if(t==0){
		printf("NO");
	}else{
		printf("YES");
	}
	
	for(i=0;i<t;i++){
	
	printf(" %d",ans[i]+1);
}

return;
}
