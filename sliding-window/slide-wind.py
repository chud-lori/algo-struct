import sys

def find_max(arr, k):
    max_val = ~sys.maxsize
    current_running_sum = 0

    for i in range(len(arr)):
        current_running_sum += arr[i]
        if (i >= (k - 1)):
            max_val = max(max_val, current_running_sum)
            current_running_sum = current_running_sum - arr[i - (k-1)]

    return max_val


def main():
    arr = [4, 2, 1, 7, 8, 1, 2, 8, 1, 0]
    k = 3 # jumlah urutan

    print(find_max(arr, k))

if __name__ == "__main__":
    main()
