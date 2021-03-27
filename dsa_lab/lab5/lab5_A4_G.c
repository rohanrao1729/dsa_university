#include<stdio.h>
#define max 10000
typedef long long int lli;

lli temp[max];

lli mergeSwaps(lli A[],int n,int left,int mid,int right){
	lli swaps = 0;
    int i = left, j = mid, k = left;
    while (i < mid && j <= right) 
    {
      if (A[i] <= A[j]) 
      {
        temp[k] = A[i];
        k++; i++;
      }
      else
      {
        temp[k] = A[j];
        k++; j++;
        swaps += mid - i;
      }
    }
    while (i < mid) 
    {
      temp[k] = A[i];
      k++; i++;
    }
 
    while (j <= right)
    {
      temp[k] = A[j];
      k++; j++;
    }
 
    while (left <= right) 
    {
      A[left] = temp[left];
      left++;
    }
    return swaps;
}
lli minNoSwaps(int arr[],int n,int s,int l){
    lli sw=0;    
    int m=(l+s)/2;
    if(s<l){
    sw+=minNoSwaps(arr,n/2,s,m);
    sw+=minNoSwaps(arr,n/2,m+1,l);
    sw+=mergeSwaps(arr,n,s,m,l);
	}    
	
	
	return sw;
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[max];
	
	int i;
	for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
	
	lli s=minNoSwaps(arr,n,0,n-1);
	printf("%lld",s);
	return 0;
}
