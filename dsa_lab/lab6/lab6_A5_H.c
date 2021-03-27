#include<stdio.h>
#define max 10000
int tol=-1,tor=-1;
int arrminright[max];
int arrmaxleft[max];
void printArray(int arr[],int n){
 int i;
 for(i=0;i<n;i++){
 	printf("%d ",arr[i]);
 }
 printf("\n");
 return;
}
void swap(int* a,int* b){
	int t=*a;
	*a=*b;
	*b=t;
	return;
}
void maxheapify(int arr[],int n,int i){
	int li=2*i+1;
	int ri=2*i+2;
	int maxIn=i;
	if(li<n&&arr[li]>arr[maxIn]){
		maxIn=li;
	}
	if(ri<n&&arr[ri]>arr[maxIn]){
		maxIn=ri;
	}
	if(maxIn!=i){
		swap(&arr[i],&arr[maxIn]);
		maxheapify(arr,n,maxIn);
	}
	return;
}

void minheapify(int arr[],int n,int i){
	int li=2*i+1;
	int ri=2*i+2;
	int minIn=i;
	if(li<n&&arr[li]<arr[minIn]){
		minIn=li;
	}
	if(ri<n&&arr[ri]<arr[minIn]){
		minIn=ri;
	}
	if(minIn!=i){
		swap(&arr[i],&arr[minIn]);
		minheapify(arr,n,minIn);
	}
	return;
}

void buildHeap(int arr[],int n,int f){
	int i;
	if(f==1){
		for(i=n/2;i>=0;i--){
		  maxheapify(arr,n,i);
		}
	}else{
		for(i=n/2;i>=0;i--){
		  minheapify(arr,n,i);
		}
	}
	return;
}
void maxheapifyB(int arr[],int n,int i){
	int parent=(i-1)/2;
	if(arr[parent]<arr[i]){
		swap(&arr[parent],&arr[i]);
		maxheapifyB(arr,n,parent);
	}
	return;
}
void minheapifyB(int arr[],int n,int i){
	int parent=(i-1)/2;
	if(arr[parent]>arr[i]){
		swap(&arr[parent],&arr[i]);
		minheapifyB(arr,n,parent);
	}
	return;
}

int insertMinHeap(int ans[],int n,int k){
	int x=n;
	tor++;
	ans[x+1]=k;
	minheapifyB(ans,x+2,x+1);
	return n+1;
}
int insertMaxHeap(int ans[],int n,int k){
	int x=n;
	tol++;
	ans[x+1]=k;
	maxheapifyB(ans,x+2,x+1);
	return n+1;
}
int deleteMinHeap(int ans[],int n){
	int val=ans[0];
	ans[0]=0;
	swap(&ans[n-1],&ans[0]);
	tor--;
	minheapify(ans,n-1,0);
	
	return val;
}
int deleteMaxHeap(int ans[],int n){
	int val=ans[0];
	ans[0]=0;
	swap(&ans[n-1],&ans[0]);
	tol--;
	maxheapify(ans,n-1,0);
	
	return val;
}
int sizeL(){
	return tol+1;
}
int sizeR(){
	return tor+1;
}
int medianHeap(int ans[],int le,int val){
	if(sizeR()>0&&val>arrminright[0]){
		insertMinHeap(arrminright,tor,val);
	}else{
		insertMaxHeap(arrmaxleft,tol,val);
	}
//	printArray(arrmaxleft,sizeL());
//	printArray(arrminright,sizeR());
	if(sizeL()-sizeR()>=2||sizeL()-sizeR()<=-2){
		if(sizeL()>sizeR()){
			int t=deleteMaxHeap(arrmaxleft,sizeL());
//			printf("%d    \n",t);
			insertMinHeap(arrminright,tor,t);
		}else{
			int v=deleteMinHeap(arrminright,sizeR());
//			printf("%d    \n",v);
			insertMaxHeap(arrmaxleft,tol,v);
		}
	}
	int ans_to_ret;
	if((le+1)%2==1){
//		printf("***%d %d***\n",sizeL(),sizeR());
		if(sizeL()>=sizeR()){
		ans_to_ret=arrmaxleft[0];
		}else{
		
			ans_to_ret=arrminright[0];
		}	
	}else{
		ans_to_ret=(arrmaxleft[0]+arrminright[0])/2;
	}
//	printArray(arrmaxleft,sizeL());
//	printArray(arrminright,sizeR());
	return ans[le]=ans_to_ret;
}

int main(){
	
	int n;
	scanf("%d",&n);
	int arr[max];

	int ans[max];
	
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		medianHeap(ans,i,arr[i]);
	}
	
//	for(i=0;i<n;i++){
//		printf("%d ",arrmaxleft[i]);
//	}
//	printf("\n");
//	for(i=0;i<n;i++){
//		printf("%d ",arrminright[i]);
//	}
//	printf("\n");
	for(i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
//	printf("\n");
	return 0;
}
