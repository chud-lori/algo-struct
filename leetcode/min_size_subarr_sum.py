# failed
def minsub(target: int, nums: list):
    sublen = len(nums)
    least = ...
    while sublen > 0:
        for i in range(sublen, len(nums)):
            print(nums[:sublen], sublen, i)
            #tot = [a for a in range()]
                #cur = arr[i - (...-1)]

        sublen -= 1



def minsubb(target, nums):
    l = 0
    r = -1
    sum_val = 0
    minlen = len(nums) + 1

    while l < len(nums):
        # Bitwise AND (&) has higher precedence than comparison (<).
        if r + 1 < len(nums) and sum_val < target:
            r += 1
            sum_val += nums[r]
        else:
            sum_val -= nums[l]
            l += 1
        if sum_val >= target:
            minlen = min(minlen, r-l+1)
    print(minlen)
    return 0 if minlen == len(nums) + 1 else minlen

if __name__ == "__main__":
    nums = [2,3,1,2,4,3]
    target = 7

    assert minsubb(target, nums) == 2

