#include<stdio.h>
#include<stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void linear( int arr[], int key, int n)
{
	int i=0, pos, flag=0;
	for(i=0; i<n; i++)
	{
		if(arr[i]==key)
		{
			pos=i+1;
			flag=1;
		}
	}
	if(flag==1)
	{
		printf("\nElement found at position %d\n", pos);
	}
	else
	{
		printf("\nElement not found\n");
	}
}

void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
    	int arr[100], n, i, key;
	printf("\nEnter number of elements: ");
	scanf("%d",&n);
	printf("\n");
	for(i=0; i<n; i++)
	{
		arr[i]=rand()%100;
	}
	printf("\nThe generated array\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n\nEnter key: ");
	scanf("%d",&key);
	gettimeofday(&t0, NULL);	
	linear(arr, key, n);
	gettimeofday(&t1, NULL);
	elapsed = timedifference_msec(t0, t1);
	printf("\nFunction executed in %f milisseconds", elapsed);
	printf("\n");
}
