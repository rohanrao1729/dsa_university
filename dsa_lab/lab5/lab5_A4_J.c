#include<stdio.h>
#define max 10000
int abinarySearch(int arr[],int n,int s,int li,int ri){
	int l=li,r=ri;
	int mid;
	while(l<=r){
      mid=(l+r)/2;
	  if(arr[mid]==s){
//	  	printf("YES");
        return mid;	  
	  }
	  if(arr[mid]>s){
	  	
	  		r=mid-1;
		  
	  }else{
	  	
		  	l=mid+1;
		 
	  }
	  	
	}
//	printf("NO");
	return -1;
}
int bbinarySearch(int arr[],int n,int s,int li,int ri){
	int l=li,r=ri;
	int mid;
	while(l<=r){
      mid=(l+r)/2;
	  if(arr[mid]==s){
//	  	printf("YES");
        return mid;	  
	  }
	  if(arr[mid]>s){
	  	
	  		l=mid+1;
		  
	  }else{
	  	
		  	r=mid-1;
		 
	  }
	  	
	}
//	printf("NO");
	return -1;
}

int findPeak(int arr[],int n){
	int l=0,r=n-1;
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){
			return mid;
		}
		if(arr[mid]<arr[mid+1]){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	
	return -1;
}

void bitonicSearch(int arr[],int n,int s){
	int l=0,r=n-1;
	int mid;
	int p=findPeak(arr,n);
	if(s==arr[p]){
		printf("YES");
		return;
	}
	if(s>arr[p]){
		printf("NO");
		return;
	}
	int ls=abinarySearch(arr,n,s,0,p);
	int rs=bbinarySearch(arr,n,s,p,n-1);
	printf("%d %d",ls,rs);
	if(ls!=-1||rs!=-1){
		printf("YES");
	     return;
	}
printf("NO");
return ;
}

int main(){
	int n,q;
	int i,s;
	int arr[max];
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	while(q--){
		scanf("%d",&s);
		bitonicSearch(arr,n,s);
	}
//	printf("%d",findPeak(arr,n));
	
	return 0;
}
