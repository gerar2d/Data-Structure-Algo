from typing import List

# BINARY SEARCH.

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
            s = 0
            e = len(nums)-1
            while (s <= e):
                mid = (s+e)//2
                if target > nums[mid]:
                    s = mid+1
                elif target < nums[mid]:
                    e = mid-1
                else:
                    return mid
            return s

        
            

x = [1,3,5,6]
b = 5
a = Solution
print(a.searchInsert(x,b))
