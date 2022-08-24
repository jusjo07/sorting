#include <math.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void insertionsort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) 
	{
		key = arr[i];
		j = i-1;     
		while (j>=0&&arr[j]>key) 
		{
		    arr[j+1] = arr[j];
		    j=j-1;
		}
		arr[j+1] = key;
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
	insertionsort(arr,n);
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

