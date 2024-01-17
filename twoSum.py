from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for index, value in enumerate(nums):
            a = target - value
            if a in d:
                return d[a], index
            d[value] = index
        return d


nums = [2,3,4,5]
target = 9
a = Solution()
print(a.twoSum(nums,target))

