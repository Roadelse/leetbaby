# coding=utf-8

class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if money < children:
            return -1
        if children == 1 and money == 4:
            return -1
        if children == 0 and  money > 0:
            return -1

        return self.distMoney(money-8, children-1) + 1

S = Solution()

print(S.distMoney(20))