'''
1. complete except for the last level
2. max or min heap
3. root at arr[0]
4. for the ith node : 
	arr[(i-1)/2]-> parent
	arr[2*i+1]-> left child
	arr[2*i+2]-> right child

Operations ( Min heap )
	1. getMinimum() : O(1)
	2. extractMinimum : removes the minimum element from the heap
		needs to call heapify. O(logN)
	3. decreaseKey : decrease the value and then maybe heapify O(logN)
	4. insert() : O(logN)
	5. delete(k) : O(logN)
		decrease key(k,-inf)
		heapify()
		extractMin()

Given an array of positive integers and two positive integers K1 and K2. 
Find sum of all elements greater tha K1th and smaller than K2th smallest elements of array.
'''

class heap:
	def __init__(self,n):
		self.size=n
		arr=[float('inf')]*n
		self.arr=arr
		self.currSize=0
	
	def leftChild(self,i):
		return (2*i)+1
	def rightChild(self,i):
		return (2*i)+2
	def parent(self,i):
		return (i-1)//2

	def getMinimum(self):
		return self.arr[0]

	def heapify(self,i):
		l=self.leftChild(i)
		r=self.rightChild(i)
		#print(l,r)
		#print("here")
		#print(self.arr[l],self.arr[r])
		smallest=i
		if(l<self.size and self.arr[l]<self.arr[i]):
			smallest=l
		if(r<self.size and self.arr[r]<self.arr[smallest]):
			smallest=r 
		if(smallest!=i):
			temp=self.arr[i]
			self.arr[i]=self.arr[smallest]
			self.arr[smallest]=temp
			self.heapify(smallest)

	def insert(self,key):
		if(self.currSize==self.size):
			print("heap full.")
		else:
			self.arr[self.currSize]=key
			self.currSize+=1
			i=self.currSize-1
			while(i!=0 and self.arr[self.parent(i)]>self.arr[i]):
				temp=self.arr[i]
				self.arr[i]=self.arr[self.parent(i)]
				self.arr[self.parent(i)]=temp
				i=self.parent(i)
	
	def decreaseKey(self,i,newVal):
		self.arr[i]=newVal
		#print(self.arr)
		while(i!=0 and self.arr[self.parent(i)]>self.arr[i]):
				temp=self.arr[i]
				self.arr[i]=self.arr[self.parent(i)]
				self.arr[self.parent(i)]=temp
				i=self.parent(i)
		#print(self.arr)
	
	def extractMin(self):
		#print(self.arr,self.currSize)
		if(self.currSize==0):
			print("heap empty.")
			return
		if(self.currSize==1):
			self.currSize-=1
			return self.arr[0]
		#print("here")
		#print(self.arr,self.currSize)
		root=self.arr[0]
		self.arr[0]=self.arr[self.currSize-1]
		self.arr[self.currSize-1]=float('inf')
		self.currSize-=1
		#print(self.arr)
		#print("calling heapify")
		self.heapify(0)
		return root

	def delete(self,i):
		self.decreaseKey(i,-1000000)
		#print(self.arr)
		self.extractMin()
		#print(self.arr)
	def replaceMin(self,key):
		root=self.arr[0]
		self.arr[0]=key
		if(root<key):
			self.heapify(0)
		return root

def kthSmallest(arr,n,k):
	k=n-k+1
	#new heap of those many elements
	heapArr=heap(k)

	#inserting first n-k+1 elements in to the array
	for i in range(0,k):
	    heapArr.insert(arr[i])

	#traversing the elements after the ones added to the hea[]
	#if the heap root is greater than the element currently traversed, replace and heapify
	#in the end the heap will have n-k+1 largest elements with the n-k+1th at the root-> this is the kth smallest element in the heap
	for i in range(k,n):
		if(arr[i]>heapArr.arr[0]):
			heapArr.arr[0]=arr[i]
			heapArr.heapify(0)
			#print(heapArr.arr)
		else:
			pass
	#printing
	return heapArr.arr[0]
ans=[]
t=int(input())
for i in range(t):
	n=int(input())
	arr=[int(j) for j in input().split()]
	k=(input().split())
	k1=int(k[0])
	k2=int(k[1])
	s=0
	for j in range(k1+1,k2):
		s+=kthSmallest(arr,n,j)
	ans.append(s)
for i in ans:
	print(i)