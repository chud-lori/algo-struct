package main

import "fmt"

func bubbleSort(arr []int) {
	for i := 0; i < len(arr)-1; i++ {
		for j := 0; j < len(arr)-i-1; j++ {
			if arr[j] > arr[j+1] {
				// swap
				arr[j] = arr[j] + arr[j+1]
				arr[j+1] = arr[j] - arr[j+1]
				arr[j] = arr[j] - arr[j+1]
			}
		}
	}
}

func main() {
	arr := []int{3, 1, 9, 8, 7, 2, 4, 10, 6, 5} // slice
	fmt.Println("before:", arr)
	bubbleSort(arr)
	fmt.Println("before:", arr)
}
