n=int(input())
def gt(a,b):
	#print(a,b,type(a))
	l1=len(a)
	l2=len(b)
	for i in range(min(l1,l2)):
		if(int(a[i])>int(b[i])):
			return 1
		elif(int(a[i])<int(b[i])):
			return 2
	if(int(a+b)>int(b+a)):
		return 1
	else:
		return 2
ans=[]
for i in range(n):
	size=int(input())
	array=input().split()
	for m in range(size-1):
		for j in range(size-1):
			if(gt(array[j+1],array[j])==1):
				temp=array[j]
				array[j]=array[j+1]
				array[j+1]=temp
	num=''.join(array)
	ans.append(num)
for i in ans:
	print(i)