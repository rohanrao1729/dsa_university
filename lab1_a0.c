#include<stdio.h>
#define MAX 1001
int main(){
	int t;
	scanf("%d",t)
	char a[MAX];
	char b[MAX];
	char c[MAX+1];
while(t--){
	int cr=0;
	scanf("%s",a);
	scanf("%s",b);
	int i=0,j=0;
	while(a[i]!='\0'){
		i++;
	}
	while(b[j]!='\0'){
		j++;
	}
	c[j+1]='\0';
	i--,j--;
	while(i>=0||j>=0){
		
		if(i>=0&&j>=0){
		
		c[j+1]=((cr+a[i]-'0'+b[j]-'0')%10)+'0';
		cr=(a[i]-'0'+b[j]-'0'+cr)/10;
		i--;
		j--;}
		if(i<0&&j>=0){
			c[j+1]=((cr+b[j]-'0')%10)+'0';
			cr=(b[j]-'0')/10;
			j--;
		}
	}
	c[0]=cr+'0';
	
	if(cr==0){
	  printf("%s",c+1);
	}else{
	printf("%s",c);
	}
}
	return 0;
}
