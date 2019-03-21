'''
Given any sequence  S = {a_1, a_2 a_n } , find the largest derangement of  S .

A derangement   D  is any permutation of  S , such that no two elements at the same position in  S and  D  are equal.

The Largest Derangement is such that  D_i > D_{i+1}, for all i .
'''

arr=[int(i) for i in input().split()]
n=len(arr)
arrCopy=arr.copy()
arr.sort(reverse=True)
newArr=[]

i=0
while(len(newArr)!=n):
	print(arr,newArr)
	f=arr[0]
	arr.remove(arr[0])
	if(f!=arrCopy[i] or i==n-1):
		newArr.append(f)
		i+=1
	else:
		#print(arr)
		newf=arr[0]
		arr.remove(arr[0])
		newArr.append(newf)
		arr.append(f)
		i+=1
		arr.sort(reverse=True)
if(newArr[n-1]==arrCopy[n-1]):
	newArr[n-1]=newArr[n-2]
	newArr[n-2]=arrCopy[n-1]
print(newArr)