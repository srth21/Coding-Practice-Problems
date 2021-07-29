#https://leetcode.com/problems/container-with-most-water/
def solve(array):
    n = len(array)
    m = -1
    p1, p2 = 0, n-1
    while(p1<p2):
        m = max(m, min(array[p1], array[p2])*(p2-p1))
        if(array[p1] > array[p2]):
            p2 -= 1
        else:
            p1 += 1
    return m
array =[int(i) for i in input().split()]
print(solve(array))