
class Solution:
    def countSymmetricIntegers( low: int, high: int) -> int:
        def is_symmetric(num):
            num_str = str(num)
            n = len(num_str) // 2
            left_part = num_str[:n]
            right_part = num_str[-n:]
            return sum(int(digit) for digit in left_part) == sum(int(digit) for digit in right_part)

        count = 0
        for num in range(low, high + 1):
            if len(str(num)) % 2 == 0 and is_symmetric(num):
                count += 1
        return count

x = 1
y = 100

a = Solution
print(a.countSymmetricIntegers(x,y))