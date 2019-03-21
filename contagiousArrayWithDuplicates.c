/*

Given an array of n integers(duplicates allowed). Print “Yes” if it is a set of contiguous integers else print “No”.


INPUT: The first line consists of an integer T i.e. the number of test cases. First line of each test case consists of an integer n, denoting the size of array. Next line consists of n spaced integers, denoting elements of array.


OUTPUT:  Print “Yes” if it is a set of contiguous integers else print “No”.
*/
#include<stdio.h>
#include<stdlib.h>

int check(int n, int *arr, int min, int max)
{
   // printf("here");
	int *hash;

	hash=(int *)calloc(max-min+1,sizeof(int));

	for(int i=0;i<n;i++)
	{
		hash[arr[i]-min]=1;
	}

	int start=-1;
	int done=-1;
	
	for(int i=0;i<n;i++)
	{
		if(hash[i]==0)
			return 0;
	}
	free(hash);
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

		int min=100000;
		int max=-100000;

		int *arr;
		arr=(int *)malloc(sizeof(int)*size);

		for(int j=0;j<size;j++)
		{
			scanf("%d",&arr[j]);
			if(arr[j]<min)
			{
				min=arr[j];
			}
			if(arr[j]>max)
			{
				max=arr[j];
			}
		}

		answers[i]=check(size,arr,min,max);

	}

	for(int i=0;i<n;i++)
	{
		if(answers[i]==1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	free(answers);
	return 0;
}