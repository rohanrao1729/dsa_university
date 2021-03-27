#include<stdio.h>
#include<limits.h>
#define max 500
int arr[max][max];
int visited[max];
int dist[max];

typedef struct node{
	int src,w;
}Node;
Node q[max];
int tind=-1;
int q_size(){
	return tind+1;
}
Node createNewNode(int sr,int we){
	Node n;
	n.src=sr;	
	n.w=we;
	return n;
}
void swap(Node* a,Node* b){
	Node t=*a;
	*a=*b;
	*b=t;
	return;
}
void minheapify(Node arr[],int n,int i){
   	int li=2*i+1;
   	int ri=2*i+2;
   	int minIn=i;
   	if(li<n&&arr[li].w<arr[minIn].w){
   		minIn=li;
	   }
	   
	if(ri<n&&arr[ri].w<arr[minIn].w){
   		minIn=ri;
	   }   
	 if(minIn!=i){
	 	swap(&arr[i],&arr[minIn]);
	 	minheapify(arr,n,minIn);
	 }  
	 return;
}
void heapify(Node arr[], int n, int i) 
{ 
    int parent = (i - 1) / 2; 
    if(parent>=0){
	
    if (arr[parent].w> 0) { 
        if (arr[i].w < arr[parent].w) { 
            swap(&arr[i], &arr[parent]); 
            heapify(arr, n, parent); 
        } 
    }
	} 
} 
  
void insertNode(Node arr[], int n, int sr,int k) 
{  
   Node a=createNewNode(sr,k);
   int x = n + 1; 
    arr[x-1] = a; 
    heapify(arr,x, x- 1);
	tind++;
	return; 
}
Node deleteNode(Node arr[],int n){
	Node val=arr[0];
	swap(&arr[0],&arr[n-1]);
	minheapify(arr,n-1,0);
	tind--;
	return val;
}

void initialiseDist(int n,int s){
	int i;
	for(i=0;i<n;i++){
		if(i==s){
		dist[i]=0;
		}else{
		dist[i]=INT_MAX;
		}
	}
}
void djikstra(int n,int s){
		
	initialiseDist(n,s);
	
	insertNode(q,q_size(),s,dist[s]);
	
	Node temp;
	while(q_size()>0){
		temp=deleteNode(q,q_size());
		int sr=temp.src;
		int weight=temp.w;
		visited[sr]=1;
//		printf("%d %d",sr,weight);
		int i;
		for(i=0;i<n;i++){
			if(arr[sr][i]!=0&&visited[i]==0){
				if(weight+arr[sr][i]<dist[i]){
				dist[i]=weight+arr[sr][i];
				}
				insertNode(q,q_size(),i,dist[i]);
			}
		}
		
	}
	return;
}

void print(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return;
}
int main(){
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	int i,a,b,w;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&w);
		arr[a][b]=w;
		arr[b][a]=w;
	}
	djikstra(n,s);

	print(dist,n);
	return 0;
}
