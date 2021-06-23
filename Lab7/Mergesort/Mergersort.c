#include<stdio.h>
// #include<conio.h>
// #include<process.h>
#include<stdlib.h>
#include<time.h>
void merge_sort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);
void merge_sort(int a[],int low,int high)
{

	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);

		merge(a,low,mid,high);
	}
}

void merge(int a[],int low,int mid,int high)
{
	int c[14000];
	int i=low,k=low,j=mid+1;
	while(i<=mid&&j<=high)
	{
		if(a[i]<a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];
	}

	while(i<=mid)
		c[k++]=a[i++];
	while(j<=high)
		c[k++]=a[j++];
	for(i=low;i<=high;i++)
		a[i]=c[i];
}

void main()
{
	int aa[100],nn;
	printf("enter value of n - no of elements\n");
	scanf("%d",&nn);
	printf("enter values into the array\n");
	for(int i=0;i<nn;i++)
		scanf("%d",&aa[i]);
	merge_sort(aa,0,nn-1);
	printf("after merge sort :\n");
	for(int i=0;i<nn;i++)
		printf("%d-->",aa[i]);


	int a[15000],n;
    clock_t start,end;
	n=500;
	printf("\n\n ---Time taken for different values of N--- \n");
	while(n<=14000)
	{
		for(int i=0;i<n;i++)
			a[i]=n-i;

		start=clock();
		merge_sort(a,0,n-1);

	    //delay
		for(int j=0;j<=100;j++);

		end=clock();

		printf("time taken by %d elements = %f secs \n",n,((double)(end-start))/CLOCKS_PER_SEC);
		n=n+1000;
	}
}