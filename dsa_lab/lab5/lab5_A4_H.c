#include<stdio.h>
#define max 10000

void initialise(int aux[],int freq[]){
	int i;
	for(i=0;i<8;i++){
		if(freq[i]!=0){
			aux[i]=1;
		}else{
			aux[i]=0;
		}
	}
}
int check(int arr[8]){
	int i;
	for(i=0;i<7;i++){
		if(arr[i]!=0){
			return 0;
		}
	}
	return 1;
}
int len(char arr[],int n,int freq[8],int aux[8],int sum){
	int len=0;
	int val=0;
	int i,j;
//	initialise(aux,freq);
//	int lmi=0;
//	int pl=0;
//	for(i=0;i<n-1;i++){
//		
//		
////		if(arr[i]!=arr[i+1]&&aux[arr[i]-'A']!=0){
////			val++;
////			aux[arr[i]-'A']=0;
////		}
////		
//		len++;
//		if(val==sum){
//		    val++;
//		}
//	}
  
  i=0,j=0;
  int min=1000;
  while(i<=j&&j<n){
  	if(val<sum){	
  		if(aux[arr[j]-'A']==0){
  		val++;
	  }
	  aux[arr[j]-'A']+=1;
	  j++;
	  }else {
	  	if(val==sum){
	  		if((j-i)<min){
	  			min=(j-i);
			  }
	  		if(aux[arr[i]-'A']==1){
	  			val--;
			  }
			  aux[arr[i]-'A']-=1;
	  		  i++;
		  }else{
		  	
		  }
	  }
  }
  while(val==sum){
       if((j-i)<min){
	  			min=(j-i);
			  }
	  		if(aux[arr[i]-'A']==1){
	  			val--;
			  }
			  aux[arr[i]-'A']-=1;
	  		  i++;
		  }
  
	
	return min;
}

int main(){
	int n;
	char arr[max];
	int freq[8];
	int aux[8];
	int i,sum=0;
	for(i=0;i<8;i++){
		freq[i]=0;
		aux[i]=0;
	}
	scanf("%d",&n);
	scanf("%s",arr);
	
	for(i=0;i<n;i++){
		if(freq[arr[i]-'A']==0){
			sum++;
		}
		freq[arr[i]-'A']+=1;
		
	}
	
	int ans=len(arr,n,freq,aux,sum);
	printf("%d",ans);
	return 0;
}
