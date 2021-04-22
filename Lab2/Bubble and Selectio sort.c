#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubblesort(int arr[],int n)
{
 int i, j,temp;
    for (i = 0; i < n-1; i++)      
     {for (j = 0; j < n-i-1; j++)  
       {if (arr[j] > arr[j+1])  
         {temp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=temp;}}} 
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionsort(int arr[], int n) 
{ 
    int i, j, min; 
  
   
    for (i = 0; i < n-1; i++) 
    { 
        
        min= i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
  
       
        swap(&arr[min], &arr[i]); 
    } 
} 

int main()
{clock_t start_t, end_t;
 double total_t;
 int arr[100];
 int i,n,c;
 printf("enter the size of the array\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
 
 printf("\n**MAIN MENU**\n");
 printf("1.bubble sort\n");
 printf("2.selection sort\n");
 printf("3.exit\n");
 printf("\n*******\n");
 printf("enter your choice:\n");
 scanf("%d",&c);
 printf("\n*******\n");
 switch(c)
 {case 1:start_t = clock();
         bubblesort(arr,n);
         printf("the sorted array\n");
         for(i=0;i<n;i++)
          printf("%d \n",arr[i]);
          end_t = clock();
          total_t = (double)end_t - start_t/CLOCKS_PER_SEC;
           printf("Total time taken by CPU: %f\n",total_t  ); 
         break;
  case 2:start_t = clock();
         selectionsort(arr,n);
         printf("the sorted array\n");
         for(i=0;i<n;i++)
          printf("%d \n",arr[i]);
          end_t = clock();
          total_t = (double)end_t - start_t/CLOCKS_PER_SEC;
           printf("Total time taken by CPU: %f\n", total_t  ); 
         break;
  case 3: exit(0);}               
  
 


 return 0;
 }