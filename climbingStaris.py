class Solution:
    def climbStairs(self, n: int) -> int:
        if n > 4:
            return n
        a,b,c = 1,1,0
        for i in range(n-1):
            c = a
            a = a+b
            b = c
        return a