#include<stdio.h>
#include<stdlib.h>

/*

Given an Array of positive numbers, calculate the number of possible subarrays having product greater than a given number K.


say for 1,2,3,4,5 and k=10

start=0, end =0;
	p=1
	p<k so count=1 { {1} }
start =0 end =1
	p=2
	p<k so count =3 { {1}, {2}, {1,2}}
start =0 end =2
	p=6
	p<k so count =6 { {1}, {2}, {1, 2}, {3}, {1,2,3}, {2,3}}
start=0 end=3
	p=24
	p>=k
		p/=1 => p=24
		p/=2 => p=12
		p/=3 => 4
	p<k so count = 7 { ..... {4}}

*/
int check(long int *arr, long int n, long int k)
{
	int count=0;

	long int p=1;
	for(long int start=0,end=0;end<n;end++)
	{
		p*=arr[end];

		while(start<=end && p>=k)
		{
			p/=arr[start++];
		}
		if(p<k)
		{
			count+=(end-start+1);
		}
	}
	return count;
}
int main()
{
	int n;
	scanf("%d",&n);
	long int *answers;
	answers=(long int *)malloc(sizeof(long int)*n);

	for(int i=0;i<n;i++)
	{
		long int size, k;
		scanf("%ld",&size);
		scanf("%ld",&k);

		long int *arr;
		arr=(long int *)malloc(sizeof(long int)*size);

		for(long int j=0;j<size;j++)
		{
			scanf("%ld",&arr[j]);
		}

		answers[i]=check(arr,size,k);
	}
	for(long int i=0;i<n;i++)
	{
		printf("%ld\n",answers[i]);
	}
}