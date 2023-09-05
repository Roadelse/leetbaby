#!/usr/bin/env python3
#coding=utf-8


class Solution:
    def maxArea(self, height: list[int]) -> int:
        if len(height) < 2:
            return 0
        i, j = 0, len(height)-1
        fn = lambda x,y : (y - x) * min(height[x], height[y])
        maxV = fn(i, j)

        while j > i:
            # print(f"i={i}, j={j}")
            if height[j] >= height[i]:
                k = i + 1
                while height[k] <= height[i] and k < j:
                    k += 1
                if k >= j:
                    return maxV
                newV = fn(k, j)
                if newV > maxV:
                    maxV = newV
                i = k
            else:
                k = j - 1
                while height[k] <= height[j] and k > i:
                    k -= 1
                if k <= i:
                    return maxV
                newV = fn(i, k)
                if newV > maxV:
                    maxV = newV
                j = k
        return maxV

s = Solution()
assert s.maxArea([1,1]) == 1
assert s.maxArea([3]) == 0
assert s.maxArea([1,8,6,2,5,4,8,3,7]) == 49

print("\033[32mtest passed!\033[m")