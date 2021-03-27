#include<stdio.h>
#include<string.h>
#define cap 10000
int arr[cap];
int level[cap];
int func[cap];
int zerArr[cap];
int ind=0;
int ti=-1;
static int val=0,k=0,indi=0;

static int ans=0;
void push(char n){
	if(ind>=cap){
		return;
	}
	arr[ind++]=n;
	ti++;
	return;
}
char top(){
	if(ti==-1||ti>=cap){
		return -1;
	}
	
	return arr[ti];
	
}
char pop(){
	if(ti==-1||ti>cap){
	  return -1;
	}
	
	return arr[ti--];
}
int size(){
	return ind;
}
int funCompute(int n){
	int i;
	int j=k--;
//	printf("%d",j);
	j--;
	for(i=n-1;i>=0;i--){
		if(func[i]==2){
			j--;
		}
		if(func[i]==0){
			int an=arr[j]+zerArr[level[j]+1];
			zerArr[level[j]]+=an;
			arr[j]=zerArr[level[j]];
			j--;
		}
		if(func[i]==1){
//			int sel=arr[j]*zerArr[level[j]+1];
			zerArr[level[j]]*=arr[j];
			arr[j]=zerArr[level[j]];
			j--;
		}
		
	}
	
	return zerArr[0];
}
void printArray(int barr[],int n){
	int i;
	for(i=0;i<n;i++){
		
		printf("%-4d ",barr[i]);
	}
	printf("\n");
	
	return;
}

int main(){
    int n;
	char str[32];
	scanf("%d",&n);
	int n1;
	int p=n;
	while(n--){
	    scanf("%s",str);
	    if(strcmp(str,"FD")==0){
	        scanf("%d%*c",&n1);
	        func[indi++]=0;
	       push(n1);
	       level[k++]=val;
	    }
	    if(strcmp(str,"LOOP")==0){
	        scanf("%d%*c",&n1);
	        push(n1);
	        func[indi++]=1;
	       val++;
	       level[k++]=val;
	    }
	    if(strcmp(str,"END")==0){
	    	push(0);
	        func[indi++]=2;
			level[k++]=val;
	        val--;
	    }
	}
//	printArray(arr,p);
//	printArray(level,p);
//	printArray(func,p);
//	printArray(zerArr,p);
	printf("%d",funCompute(indi)); 
//	printArray(arr,p);
//	printArray(level,p);
//	printArray(func,p);
//	printArray(zerArr,p); 
	
	
	return 0;
}
