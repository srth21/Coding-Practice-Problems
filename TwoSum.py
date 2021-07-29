#https://leetcode.com/problems/two-sum
def twoSum(self, nums: List[int], target: int) -> List[int]:
    m = {}
    j = 0
    for i in nums:
        if(i in m.keys()):
            m[i].append(j)
        else:
            m[i] = [j]
        j += 1
    l = 0
    r = len(nums) - 1
    nums = sorted(nums)
    while(l<r):
        if(nums[l] + nums[r] == target):
            if(nums[l] == nums[r]):
                return m[nums[l]]
            return [m[nums[l]][0],m[nums[r]][0]]
        if(nums[l] + nums[r] > target):
            r -= 1
        else:
            l += 1
nums = [int(i) for i in input().split()]
target = int(input())
print(twoSum(nums,target))
            