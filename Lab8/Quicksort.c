#include<stdio.h>
#include<time.h>

int a[10],n;
void quick_sort(int [ ],int,int);
int partition(int [ ], int, int);

void main()
{
	int aa[100],nn;
	printf("enter value of n - no of elements\n");
	scanf("%d",&nn);
	printf("enter values into the array\n");
	for(int i=0;i<nn;i++)
		scanf("%d",&aa[i]);
	quick_sort(aa,0,nn-1);
	printf("after quick sort :\n");
	for(int i=0;i<nn;i++)
		printf("%d-->",aa[i]);

	int a[15000],n;
    clock_t start,end;
	n=500;
	printf("\n\n ---Time taken for different values of N--- \n");
	while(n<=14500)
	{
		for(int i=0;i<n;i++)
			a[i]=n-i;

		start=clock();
		quick_sort(a,0,n-1);

	    //delay
		for(int j=0;j<=100;j++);

		end=clock();

		printf("time taken by %d elements = %f secs \n",n,((double)(end-start))/CLOCKS_PER_SEC);
		n=n+1000;
	}
}

void quick_sort(int a[ ], int low, int high)
{
	int mid;
	if(low<high)
	{
		mid=partition(a,low,high);
		quick_sort(a,low,mid-1);
		quick_sort(a,mid+1,high);
	}
}

int partition(int a[],int low,int high)
{
	int i,j,temp,pivot;
	pivot=a[low];
	i=low+1;
	j=high;
	while(i<=j)
	{
		while(a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	return j;
}