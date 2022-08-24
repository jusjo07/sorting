#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void bubblesort(int arr[], int n)
{
   int i, j, temp;
   for (i = 0; i < n-1; i++)
   {
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           temp=arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=temp;
        }
     }
    }
}

void main(void)
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
	bubblesort(arr,n);
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

