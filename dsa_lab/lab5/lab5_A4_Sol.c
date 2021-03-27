#include<stdio.h>
#define max 100000
#define lli long long int
lli merge(int arr[], int temp[], int left, int mid, int right) 
{ 
    lli inv_count = 0; 
  
    int i = left; 
    int k = left; 
    int j = mid; 
    while ((i <= mid - 1) && (j <= right)) 
    { 
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++]; 
        else
        { 
            temp[k++] = arr[j++]; 
  
            
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
   
    for (i=left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
  

lli mergeSort(int arr[], int temp[], int left, int right) 
{   lli inv_count = 0;
    int mid ; 
    if (right > left) 
    { 
        
        mid = (right + left)/2; 
  
       
        inv_count  += mergeSort(arr, temp, left, mid); 
        inv_count += mergeSort(arr, temp, mid+1, right); 
  
       
        inv_count += merge(arr, temp, left, mid+1, right); 
    } 
  
    return inv_count; 
} 

lli countSwaps(int arr[], int n) 
{ 
    int temp[max]; 
    return mergeSort(arr, temp, 0, n - 1); 
} 

int main(){
	int n;
	scanf("%d",&n);
	int arr[max];
	
	int i;
	for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
	
	lli s=countSwaps(arr,n);
	printf("%lld",s);
	return 0;
}
