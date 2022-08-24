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

void binary(int key, int a[], int l, int h)
{
	int mid, flag=0;
	while(l<=h)
	{
		
		mid=(l+h)/2;
		if(key<a[mid])
		{
			h=mid-1;
		}
		else if(key==a[mid])
		{
			printf("\nElement found at position %d", mid);
			flag=1;
			break;
		}
		else
		{	
			l=mid+1;
		}
		
	}
	if(flag!=1)
		printf("\nElement not found");
	printf("\n");
}


void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	int arr[100], n, i, key;
	printf("\nEnter number of elements: ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		arr[i]=rand()%100;
	}
	printf("\n\nTHe generated array\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n\nThe sorted array\n");
	selsort(arr, n);	
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n\nEnter key: ");
	scanf("%d", &key);
	gettimeofday(&t0, NULL);
	binary(key, arr, 0, n-1);
	gettimeofday(&t1, NULL);
	elapsed = timedifference_msec(t0, t1);
	printf("\nFunction executed in %f milisseconds", elapsed);
	printf("\n");
}


