#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_sort(int n,int arr[]){

	int temp,small,position;
	for(int i=0;i<n-1;i++){
		small=arr[i];
		position=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<small){
				small=arr[j];
				position=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[position];
		arr[position]=temp;
	}
}



void main()
{
	int a[15000],n;
    clock_t start,end;
	n=500;
	while(n<=14500)
	{
		for(int i=0;i<n;i++)
			a[i]=n-i;

		start=clock();
		selection_sort(n,a);

	    //delay
		for(int j=0;j<=100;j++);

		end=clock();

		printf("Time for N = %d elements is = %f secs \n",n,((double)(end-start))/CLOCKS_PER_SEC);
		n=n+1000;
	}

}
