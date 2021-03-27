#include<stdio.h>
#include<math.h>
#define MAX 10000
typedef long long int lli;

int tolls[MAX],capacity[MAX];
int dist[MAX];

int process(int u,int v,int m){
	int i=0,j=0;
	for(i=0;i<m;i++){
		if(tolls[i]>=u&&tolls[i]<=v){
			dist[j++]=tolls[i];
		}
	}
	
	return j;
}
void calcDiff(int s){
	int i;
	for(i=0;i<s-1;i++){
		dist[i]=dist[i+1]-dist[i];
	}
}

void calcValue(int a,int b,int s){
	int i;
	for(i=0;i<s;i++){
		dist[i]=ceil((dist[i]-b)/(double)a);
	}
}
lli sum(int s){
    int i;
    lli sum=0;
	for(i=0;i<s-1;i++){
		sum+=dist[i];
	}
	return sum;
}
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
    int j;
    for (j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}
int findValue(int val,int n){
	int li=0,ri=n-1;
	int mi;
	int cel=-1;
	while(li<=ri){
		mi=(li+ri)/2;
//		printf(" %d %d %d %d %d\n",val,li,ri,mi,capacity[mi]);
	if(capacity[mi]==val){
		cel=val;
		return val;
	}
	if(capacity[mi]<val){
		li=mi+1;
	}else{
		cel=capacity[mi];
		ri=mi-1;
	}
	}
	return cel;
}
int main(){
	int n,m,l;
	scanf("%d%d%d",&n,&m,&l);
	int u,v,a,b,k;
	scanf("%d%d%d%d%d",&u,&v,&a,&b,&k);
	
	int i;
	for(i=0;i<m;i++){
		scanf("%d",&tolls[i]);
	}
	for(i=0;i<l;i++){
		scanf("%d",&capacity[i]);
	}
	int soDist=process(u,v,m);
	
	quickSort(dist,0,soDist-1);
	
	calcDiff(soDist);
	calcValue(a,b,soDist);
	
	quickSort(capacity,0,l-1);
	int val;
	int flag=0;
	for(i=0;i<soDist-1;i++){
		val=findValue(dist[i],l);
//		printf("%d %d",dist[i],val);
		if(val==-1){
			flag=1;
			break;
		}
		dist[i]=val;
	}
//	for(i=0;i<soDist;i++){
//		printf("%d ",dist[i]);
//	}
//	for(i=0;i<l;i++){
//		printf("%d ",capacity[i]);
//	}
	if(flag==0){
		lli s=sum(soDist);
		printf("%lld",10*s);
	}else{
		printf("NOT POSSIBLE");
	}
	
	return 0;
}
