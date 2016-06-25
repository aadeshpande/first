#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void print(int *arr, int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
void swapping(int *a, int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void B_UPHEAP(int *arr, int i,int n)
{
	int p;
	p=(i-1)/2;
	while(p>=0 && arr[p]<arr[i])
	{
		swapping(&arr[i],&arr[p]);
		i=p;
		p=(i-1)/2;
	}
}
void T_DOWNHEAP(int *arr, int i,int n)
{
	int l,r,max;
	l=2*i+1;
	r=2*i+2;
	while(l<n && r<n)
	{
		if(arr[l]<arr[r])
			max=r;
		else
			max=l;
		if (arr[i]>=arr[max])	break;
		else	
		{
			swapping(&arr[i],&arr[max]);
			i=max;
			l=2*i+1;
			r=2*i+2;
		}
	}
	if(arr[l]>arr[i])
		swapping(&arr[l],&arr[i]);
}
void BUILD_HEAP(int *arr,int n)
{
	int i;
	i=n/2;
	while(i>=0)
	{
		T_DOWNHEAP(arr,i,n);
		i=i-1;
	}
}
void INSERT(int *arr,int num,int n)
{
	arr[0]=num;
	T_DOWNHEAP(arr,0,n);
}
int main(int argc, char *argv[])
{
	FILE *in=fopen(argv[1],"r");
	int n=pow(10,8);
	int k,i=0,no;
	int *arr=malloc(sizeof(int)*n);
	fscanf(in,"%d\n",&k);
	while(i<k)
	{
		fscanf(in,"%d ",&arr[i]);
		i++;
	}
	BUILD_HEAP(arr,k-1);
	while(!feof(in))
	{
		fscanf(in,"%d ",&no);
		if(no<arr[0])
			INSERT(arr,no,k-1);
	}
	for(i=0;i<k;i++)
		printf("%d\n",arr[i]);
}
	

