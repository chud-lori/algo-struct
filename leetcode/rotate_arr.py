nums = [1,2,3,4,5,6,7]
k = 3
#nums=  [-1]
#k = 2
#temp = [0 for a in range(len(nums))
# mine
#temp = nums[:]
#for i, v in enumerate(nums):
#    temp_i = i+k
#    if temp_i >= len(nums):
#        temp_i = temp_i - len(nums)
#    if temp_i >= len(nums):
#        temp_i = 0
#    temp[temp_i] = v
#
#nums[:] = temp[:]
#k -= 1

#print(temp)

def rotate(nums, k):
    n = len(nums)
    k %= n # normalize k to within nums length

    def reverse(start, end):
        print(f"start: {nums}")
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            print(nums)
            start += 1
            end -= 1


    # Reverse the entire array
    reverse(0, n - 1)
    print("FIRST DONE\n")
    # Reverse the first k elements
    reverse(0, k - 1)
    print("SECOND DONE\n")
    # Reverse the remaining elements
    reverse(k, n - 1)

    print("Result: ", nums)

rotate(nums, k)
#python way
#n = len(nums)
#k %= n
#nums[:] = nums[-k:] + nums[:-k]


