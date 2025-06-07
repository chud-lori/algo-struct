from typing import List


def majorityElement(nums: List[int]) -> int:
    di = {}
    for i in nums:
        if i in di:
            di[i] += 1
            continue
        di[i] = 1

    return max(di, key=di.get)


nums = [3,2,3]
assert majorityElement(nums) == 3

nums = [2,2,1,1,1,2,2]
assert majorityElement(nums)

