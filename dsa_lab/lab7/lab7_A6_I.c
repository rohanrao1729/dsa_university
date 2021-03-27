#include<stdio.h>
#include<stdlib.h>
#define max 100000
int ind=0;
int minx=100000,miny=100000;

//p(x,y)  p1(x1,y)  p2(x2,y2)
// y1-y/x1-x<y2-y/x2-x =>y1-y*x2-x<y2-y*x1-x   
typedef struct node{
	int p,x,y;
}Node;
Node arr[max];  
Node arrn[max];
static int index=0;
int abs(int x){
	return x>0?x:-1*x;
}
int mhDist(Node* n1,Node* n2){
	int xdist=n1->x-n2->x;
	int ydist=n1->y-n2->y;
	return abs(xdist)+abs(ydist);
}
int cmpfunc(const void* a,const void* b){
	Node* n1=(Node*)a;
	Node* n2=(Node*)b;
	Node n;
	n.x=minx;
	n.y=miny;
	if((n1->x<=minx&&n2->x>=minx)){
		if(n1->x==n2->x){
			return n1->y-n2->y;
		}
		return n2->x-n1->x;
	}
	if((n1->x>=minx&&n2->x<=minx)){
		if(n1->x==n2->x){
			return n1->y-n2->y;
		}
		return n2->x-n1->x;
	}
	if((n1->x<minx&&n2->x<minx)){
	 long long int val=(n2->y-miny)*(n1->x-minx)-(n1->y-miny)*(n2->x-minx);
		if(val>0){
			return -1;
		}else{
			if(val==0){
				return mhDist(n2,&n)-mhDist(n1,&n);
			}else{
				return 1;
			}
			
		}
	}
	if((n1->x>minx&&n2->x>minx)){
	long long int val=(n2->y-miny)*(n1->x-minx)-(n1->y-miny)*(n2->x-minx);
		if(val>0){
			return -1;
		}else{
			if(val==0){
				return mhDist(n2,&n)-mhDist(n1,&n);
			}else{
				return 1;
			}
			
		}
	}
	
	
}


int main(){
	int n;
	scanf("%d",&n);
	
	int pi,xi,yi;
   int i;
	for(i=0;i<n;i++){
		scanf("%d %d %d",&pi,&xi,&yi);
		Node no;
		no.p=pi,no.x=xi,no.y=yi;
		arr[i]=no;
		if(yi<miny){
			miny=yi;
		}
	}
	
	for(i=0;i<n;i++){
		if(arr[i].y==miny&&arr[i].x<minx){
			minx=arr[i].x;
			ind=i;
		}
	}
//	printf("%d %d\n",minx,miny);
   for(i=0;i<n;i++){
   	if(arr[i].x==minx&&arr[i].y==miny){
   		
	   }else{
	   	Node np;
	   	np.p=arr[i].p;
	   	np.x=arr[i].x;
	   	np.y=arr[i].y;
	   	arrn[index++]=np;
	   }
   }
	
	qsort(arrn,index,sizeof(Node),cmpfunc);
	for(i=0;i<index;i++){
		printf("%d ",arrn[i].p);
	}
	
	return 0;
}
