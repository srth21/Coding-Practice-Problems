'''
Given an array of n distinct elements, the task is to find all elements in array which have at-least two greater elements than themselves.

Examples:

Input : A[] = {2, 8, 7, 1, 5};
Output : 1  2  5  
The output three elements have two or
more greater elements
      
Input  : A[] = {7, -2, 3, 4, 9, -1};
Output : -2  -1  3  4  

Input:
The first line of input contains an integer T denoting the no of test cases. Each test case contains two lines . The first line of input contains an integer n denoting the size of the array. Then in the next are n space separated values of the array.

Output:
For each test case in a new line print the space separated sorted values denoting the elements in array which have at-least two greater elements than themselves.

Constraints:
1<=T<=100
1<=N<=100
1<=A[]<=100

Example:
Input:
2
5
2 8 7 1 5
6
7 -2 3 4 9 -1

Output:
1 2 5
-2 -1 3 4 

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
n=int(input())
ans=[]
for i in range(n):
    a=[]
    l=int(input())
    arr=[int(j) for j in input().split()]
    heapArr=heap(l)
    for i in range(0,l):
    	heapArr.insert(arr[i])
    
    for i in range(0,l):
    	arr[i]=heapArr.extractMin()
    #print(arr)
    ans.append(arr[0:l-2])
s=""
for i in ans:
    for j in i:
        s+=str(j)+" "
    s+='\n'
print(s)