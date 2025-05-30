'''
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high
https://www.geeksforgeeks.org/bubble-sort/
'''


def bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j+1]:
                # swap
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


def main():
    arr = [3, 1, 9, 8, 7, 2, 4, 10, 6, 5]
    print("Before sorting: ", arr)
    bubble_sort(arr)
    print("After sorting: ", arr)


if __name__ == "__main__":
    main()
