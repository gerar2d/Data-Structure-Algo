from typing import List

class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        holder = set()
        for start, end in nums:
            for i in range(start,end+1):
                print(holder)
                holder.add(i)
        return len(holder)

nums = [[3,6],[1,5],[4,7]]
a = Solution()

print(a.numberOfPoints(nums))