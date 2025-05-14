from typing import List

#def summaryRanges(nums: List[int]) -> List[str]:
#    second = 0
#    inter = []
#    start = nums[0]
#    for i in range (len(nums)):
#        print(nums[i+1], nums[i] + 1)
#        if nums[i + 1] != nums[i] + 1:
#            inter.append(f"{start}->{nums[i]}")
#
#            start = nums[i+1]
#        #print(inter)
#
#    return inter
def summaryRanges(nums: List[int]) -> List[str]:
    if not nums:
        return []

    start = nums[0]
    result = []
    for i in range(0, len(nums)-1):
        if(nums[i + 1] != nums[i] + 1):
            if start == nums[i]:
                result.append(f"{nums[i]}")
            else:
                result.append(f"{start}->{nums[i]}")

            start = nums[i + 1]

    if start == nums[-1]:
        result.append(str(nums[-1]))
    else:
        result.append(f"{start}->{nums[-1]}")

    return result


if __name__ == "__main__":
    nums = [0,1,2,4,5,7]
    r = summaryRanges(nums)
    print(r)
    assert ["0->2","4->5","7"] == r
    nums = [0,2,3,4,6,8,9]
    r = summaryRanges(nums)
    print(r)
    assert ["0","2->4","6","8->9"] == r

