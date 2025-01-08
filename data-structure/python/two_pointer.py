

def tp(arr: int, size: int, val: int):
    """
    two poitner algorithm to find pair sum
    """
    i = 0
    j = size - 1

    while i < j:
        sum_arr = arr[i] + arr[j]
        if (sum_arr == val):
            return sum_arr
        elif (sum_arr < val):
            i += 1
        else:
            j -= 1

    return 0


if __name__ == "__main__":
    arr: list = [10, 20, 35, 50, 75, 80]
    size: int = len(arr)
    found: int = tp(arr, size, 30)
    print(found)
