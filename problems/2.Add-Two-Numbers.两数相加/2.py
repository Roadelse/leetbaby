#!/usr/bin/env python3
#coding=utf-8

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    @staticmethod
    def fromInt(val):
        root = None
        for i in str(val):
            root = ListNode(int(i), root)
        return root

    def toInt(self):
        n = self
        val = 0
        i = 0
        while n is not None:
            val += n.val * 10**i
            n = n.next
            i += 1
        return val         

class Solution1:
    """
    暴力思路: 先全加起来, 再化简, 逻辑简单清晰, 性能吗一般般
    不过不改动l1和l2, 内存上感觉也么有优化空间了啊...
    time: 56ms, beat 58.67%
    memory: beat 46.38%
    """
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def sim(ln: Optional[ListNode]):
            if not ln:
                return
            if ln.val >= 10:
                ln.val -= 10
                if ln.next:
                    ln.next.val += 1
                else:
                    ln.next = ListNode(1)
                    return
            sim(ln.next)


        l3r = ListNode()
        l3 = l3r
        while l1 or l2:
            if l1 and l2:
                l3.next = ListNode(l1.val + l2.val)
                l1 = l1.next
                l2 = l2.next
                l3 = l3.next
            elif l1:
                l3.next = l1
                break
            elif l2:
                l3.next = l2
                break
        l3 = l3r.next
        sim(l3)
        return l3

class Solution2:
    """
    这个的思路是在l1和l2的基础上直接修改, 不利用一个新的链表l3
    time: 41ms, beat 97.06%
    memory: beat 35.86%
    """
    def __init__(self):
        self.carry = 0
        self.depth = 0

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        self.depth += 1
        # print(self.depth, l1.toInt() if l1 else -1, l2.toInt() if l2 else -1, self.carry)
        if l1 and l2:
            l1.val += l2.val + self.carry
        elif l1:
            l1.val += self.carry
        elif l2:
            l1 = l2
            l2 = None
            l1.val += self.carry
        elif self.carry:
            return ListNode(1)
        else:
            return 

        # print(f'{self.depth=}, {l1.val=}')

        if l1.val > 9:
            l1.val -= 10
            self.carry = 1
        else:
            self.carry = 0
        l1.next = self.addTwoNumbers(l1.next, l2.next if l2 else None)
        # print(f'at last, {l1.val=}')
        return l1

S = Solution2()
assert ListNode.fromInt(123).toInt() == 123, f'{ListNode.fromInt(123).toInt()}'
assert S.addTwoNumbers(ListNode.fromInt(123), ListNode.fromInt(456)).toInt() == 579
assert S.addTwoNumbers(ListNode.fromInt(0), ListNode.fromInt(456)).toInt() == 456
assert S.addTwoNumbers(ListNode.fromInt(0), ListNode.fromInt(0)).toInt() == 0
assert S.addTwoNumbers(ListNode.fromInt(342), ListNode.fromInt(465)).toInt() == 807, f'{S.addTwoNumbers(ListNode.fromInt(342), ListNode.fromInt(465)).toInt()}'
