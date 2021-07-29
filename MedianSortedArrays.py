#https://leetcode.com/problems/median-of-two-sorted-arrays/
def findMedian(array1, array2):
    m = len(array1)
    n = len(array2)
    s = m+n
    isEven = False
    x = s//2
    if(s%2 == 0):
        isEven,x =  True,s//2
    array1Pointer = 0
    array2Pointer = 0
    numberOfElementsTraversed = 0
    prev = None
    curr = None

    while(True):
        prev = curr
        if(array1Pointer >= m):
            curr = array2[array2Pointer]
            array2Pointer += 1
        elif(array2Pointer >= n):
            curr = array1[array1Pointer]
            array1Pointer += 1  
        elif(array1Pointer < m and array1[array1Pointer] < array2[array2Pointer]):
            curr = array1[array1Pointer]
            array1Pointer += 1
        elif(array2Pointer < n and array1[array1Pointer] >= array2[array2Pointer]):
            curr = array2[array2Pointer]
            array2Pointer += 1            

        numberOfElementsTraversed += 1

        if(numberOfElementsTraversed-1 == x):
            if(isEven):
                return (float)(prev + curr)/2
            else:
                return (float)(curr)

array1 = [int(i) for i in input().split()]
array2 = [int(i) for i in input().split()]
print(findMedian(array1,array2))