#include<stdio.h>
#include<stdlib.h>

/*

Given an sorted array of size n. Find number of elements which are less than or equal to given element

n -> 7
say arr -> 1 2 2 2 5 7 9
ele -> 2
initially : lr=0 and up=6
m=3
arr[3]<=2 is true : lr becomes 4 and m becomes 5
now arr[5] > 2 : thus up becomes 4  and m becomes 4
now arr[4] > 2 : thus up becomes 3 and m becomes 3
but lr is now greater than up : thus stops.
lr is returned : 4
*/

int check(int *arr, int size,int ele)
{
	int lr=0;
	int up=size-1;
	int m=(lr+up)/2;

	int pos;
	
	while(lr<=up)
	{
		if(arr[m]<=ele)
		{
			lr=m+1;
			m=(lr+up)/2;
		}	
		else if(arr[m]>ele)
		{
			up=m-1;
			m=(lr+up)/2;
		}
	}
	
	return lr;
	
}
int main()
{
	int n;
	scanf("%d",&n);
	int *answers;
	answers=(int *)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++)
	{
		int *arr;
		int size;

		scanf("%d",&size);

		arr=(int *)malloc(sizeof(int)*size);

		for(int j=0;j<size;j++)
		{
			scanf("%d",&arr[j]);
		}
		int ele;
		scanf("%d",&ele);
		answers[i]=check(arr,size,ele);

	}
	for(int i=0;i<n;i++)
	{
		printf("%d\n",answers[i]);
	}
}