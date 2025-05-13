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
def summaryRanges(nums: List[int]): -> List[str]:
    result = []


if __name__ == "__main__":
    nums = [0,1,2,4,5,7]
    r = summaryRanges(nums)
    print(r)
    #assert ["0->2","4->5","7"] == r

