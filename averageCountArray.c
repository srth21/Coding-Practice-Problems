/*
You are given an integer 'n' which denote the number of elements in an array a[ ] and an integer 'x'. 
You have to calculate the average of element a[i] and x and find out if that number exist in array or not. 
Do it for all the elements of array and store the count result in another array for each index i.

*/
#include<stdio.h>
#include<stdlib.h>

int findMax(int *arr, int n)
{
	int max=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}

int check(int *arr, int n, int ele,int *avgArray)
{
	int max=findMax(arr,n);
	//printf("max %d\n",max);

	int *bitCount;
	if(max<ele)
	{
		bitCount=(int *)calloc(ele+1,sizeof(int));
		max=ele;
	}
	else
	{
		bitCount=(int *)calloc(max+1,sizeof(int));
	}
	
	for(int i=0;i<n;i++)
	{
		bitCount[arr[i]]+=1;
	}
	for(int i=0;i<n;i++)
	{
		int avg=(arr[i]+ele)/2;
		avgArray[i]=bitCount[avg];
	}
	free(bitCount);
	return 1;
}

int main()
{
	int n;
	
	scanf("%d",&n);
	
	int **answers;
	answers=(int **)malloc(sizeof(int *)*n);

	int *sizes;
	sizes=(int *)malloc(sizeof(int)*n);
	
	for(int i=0;i<n;i++)
	{
		int *arr;
		int size;
		int ele;		
		
		scanf("%d",&size);
		scanf("%d",&ele);
		
		answers[i]=(int *)malloc(sizeof(int)*size);
		sizes[i]=size;
		
		arr=(int *)malloc(sizeof(int)*size);

		for(int j=0;j<size;j++)
		{
			scanf("%d",&arr[j]);
		}
		
		int c=check(arr,size,ele,answers[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<sizes[i];j++)
		{
			printf("%d ",answers[i][j]);
		}
		printf("\n");
	}
	free(answers);
	free(sizes);
}