/*
Check whether an array can be fit into another array rearranging the elements in the array
Given two arrays A and B of same size N. Check whether array A can be fit into array B. 
An array is said to fit into another array if by arranging the elements of both arrays, 
there exists a solution such that the ith element of the first array is less than or equal to ith element of the second array.

*/

#include<stdio.h>
#include<stdlib.h>

void sort(int *a, int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]<a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int check(int n, int *a, int *b)
{
	sort(a,n);
	sort(b,n);
	
	for(int i=0;i<n;i++)
	{
		if(b[i]<a[i])
		{
			return -1;
		}
	}
	return 1;

}
int main(int argc, char const *argv[])
{
	/* code */
	int n;
	scanf("%d",&n);
	int *answers;

	answers=(int *)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++)
	{
		int size;

		scanf("%d",&size);
		int *a;
		int *b;

		a=(int *)malloc(sizeof(int)*size);
		b=(int *)malloc(sizeof(int)*size);

		for(int j=0;j<size;j++)
		{
			scanf("%d",&a[j]);
		}
		for(int j=0;j<size;j++)
		{
			scanf("%d",&b[j]);
		}

		answers[i]=check(size,a,b);
		free(a);
		free(b);
	}

	for(int i=0;i<n;i++)
	{
		if(answers[i]==1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	free(answers);
	return 0;
}