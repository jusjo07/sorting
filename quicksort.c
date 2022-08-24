#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int pivot;

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int partition (int a[], int low, int high)

{
	int temp,i,j,k;
	pivot = a[high];  

	i =low-1;

	for (j = low; j <= high- 1; j++)
	{
		if (a[j] < pivot)
		{
			i++;  
			temp=a[i];
			a[i]=a[j];
			a[j]=temp; 
		 }
	 }
	 temp=a[i+1];
	 a[i+1]=a[high];
	 a[high]=temp;
	 k=i+1;
	 return k;
}

void quicksort(int arr[], int left, int right)
{
	if(left<right)
	{
		pivot=partition(arr, left, right);
		quicksort(arr,left,pivot-1);
		quicksort(arr,pivot+1,right);
	}
}
	

void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	int arr[100], n, i;
	printf("\nEnter number of elements: ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		arr[i]=rand()%100;
	}
	printf("\nThe generated array\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\nThe sorted array\n");
	gettimeofday(&t0, NULL);
	quicksort(arr, 0, n-1);
	gettimeofday(&t1, NULL);
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	elapsed = timedifference_msec(t0, t1);
	printf("\nFunction executed in %f milisseconds", elapsed);
	printf("\n");
}
