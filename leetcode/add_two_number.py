from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def print(self):
        count = 1
        curr = self
        while True:
            print(f"Node {count}: {curr.val}")
            count += 1
            if not curr.next:
                break
            curr = curr.next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l1_list = self.node_to_list(l1)
        l1_list.reverse()
        l2_list = self.node_to_list(l2)
        l2_list.reverse()
        l1val = int(''.join([str(a) for a in l1_list]))
        l2val = int(''.join([str(a) for a in l2_list]))
        res = l1val + l2val
        res = [int(a) for a in str(res)]
        res.reverse()
        res = self.list_to_node(res)
        return res

    def node_to_list(self, list_node: ListNode):
        current_node = list_node
        nodeval = []
        while True:
            val = current_node.val
            nodeval.append(val)
            if not current_node.next:
                break
            current_node = current_node.next

        return nodeval


    def list_to_node(self, ldata: List[int]):
        if not ldata:
            return None
        head_node = ListNode(ldata[0])
        current_node = head_node
        for i in range(1, len(ldata)):
            current_node.next = ListNode(ldata[i])
            current_node = current_node.next

        return head_node

class Solution2:
    # from leetcode
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead = ListNode(0)
        curr = dummyHead
        carry = 0
        while l1 != None or l2 != None or carry != 0:
            l1Val = l1.val if l1 else 0
            l2Val = l2.val if l2 else 0
            columnSum = l1Val + l2Val + carry
            print(f"columnSum: {columnSum}")
            carry = columnSum // 10
            print(f"carry: {carry}")
            newNode = ListNode(columnSum % 10)
            curr.next = newNode
            curr = newNode
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return dummyHead.next


so = Solution2()
l1 = ListNode(2, ListNode(4, ListNode(3)))
l2 = ListNode(5, ListNode(6, ListNode(4)))
a=so.addTwoNumbers(l1,l2)
# a.print()





