#include<stdio.h>
#include<stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void selsort(int a[], int n)
{
	int i, temp, j,  min;
	for(int i=0; i<=(n-2); i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		if(min!=i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
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
	printf("\n\nThe generated array\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n\nThe sorted array\n");
	gettimeofday(&t0, NULL);
	selsort(arr, n);
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


