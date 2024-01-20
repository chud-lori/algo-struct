# https://leetcode.com/problems/remove-element
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        nums[:] = [a for a in nums if a != val]
        return len(nums)
