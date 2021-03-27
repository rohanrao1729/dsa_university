#include<stdio.h>
#include<string.h>
#define max 10001
char stack[max];
char str[max];
char ans[max];
int ans_ind=0;
int level=0,flag=0;
int top_in=-1;

char aux[max];
int aux_in=0;
int size(){
	return top_in+1;
}
void push(char data){
	top_in++;
	stack[top_in]=data;
	return;
}
char pop(){
	if(size()==0){
		return -1;
	}
	return stack[top_in--];
}

char top(){
	if(size()==0){
		return -1;
	}
	return stack[top_in];
}

int main(){
	
	scanf("%s",str);
	int i=0;
	int j=0;
	while(str[i]!='\0'){
		if(str[i]>='a'&&str[i]<='z'){
			if(level==0){
				if(flag==0){
				ans[ans_ind++]=str[i];
				}else{
					if(str[i]+flag>'z'){
						ans[ans_ind++]=str[i]+flag-'z'+'a'-1;
					}else{
						ans[ans_ind++]=str[i]+flag;
					}
					
				}
				
			}else{
				if(flag==0){
				push(str[i]);
				}else{
//					push(str[i]+flag-'z'+'a');
                    if(str[i]+flag>'z'){
						push(str[i]+flag-'z'+'a'-1);
					}else{
						push(str[i]+flag);
					}
				}
				
			}
		}
		if(str[i]=='['){

            flag++;
		}
		if(str[i]=='('){

            push('(');
            level++;
		}
		if(str[i]==']'){
			flag--;
		}
		if(str[i]==')'){
			level--;
//			printf("%d ",1);
			while(top()!='('&&size()>0){
				char ch=pop();
				
				aux[aux_in++]=ch;
			}
			pop();
			for(j=0;j<aux_in;j++){
//				printf("%d ",level);
			if(level==0){
			  ans[ans_ind++]=aux[j];
			}else{
				push(aux[j]);
			}
			}
			aux_in=0;
			
		}
//		printf("%d",i);
		i++;
	}
	
	for(i=0;i<ans_ind;i++){
	
	printf("%c",ans[i]);
}
	return 0;
}
