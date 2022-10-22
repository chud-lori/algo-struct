package main

import (
	"fmt"
	"math"
)

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func findMax(arr []int, k int) int {
	maxVal := math.MinInt
	currentRunningSum := 0

	for i := 0; i < len(arr); i++ {
		currentRunningSum += arr[i]
		if i >= k-1 {
			maxVal = max(maxVal, currentRunningSum)
			currentRunningSum -= arr[i-(k-1)]
		}
	}

	return maxVal

}

func main() {

	arr := [10]int{4, 2, 1, 7, 8, 1, 2, 8, 1, 0}
	k := 3

	fmt.Println(findMax(arr[:], k))
	//fmt.Println("vim-go")

}
