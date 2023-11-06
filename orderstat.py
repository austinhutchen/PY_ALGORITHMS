
# Python3 code for kth smallest element in an array
import re
import sys

# function to calculate number of elements
# less than equal to mid


def count(nums, mid):
	cnt = 0
	for i in range(len(nums)):
		if nums[i] <= mid:
			cnt += 1
	return cnt


def kthSmallest(nums, k):
	low = sys.maxsize
	high = -sys.maxsize - 1

	# calculate minimum and maximum the array.
	for i in range(len(nums)):
		low = min(low, nums[i])
		high = max(high, nums[i])

		# Our answer range lies between minimum and maximum element
		# of the array on which Binary Search is Applied
	while low < high:
		mid = low + (high - low) // 2
		# if the count of number of elements in the array less than equal
		# to mid is less than k then increase the number. Otherwise decrement
		# the number and try to find a better answer.
		if count(nums, mid) < k:
			low = mid + 1
		else:
			high = mid
	return low


# Driver's code
if __name__ == "__main__":
    stream = open("7.txt")
    nums = stream.readlines()
    numbers = re.findall('[+-]?\d+',str(nums))    
    k= int(numbers[0])
    numbers= numbers[:0] + numbers[(1):]
    print ( "K is:", k)
    print(numbers);
    param= [ int(x) for x in numbers ]
    print( "ORDER STATISTIC:", kthSmallest(param,k)) 
# This code is contributed by Tapesh(tapeshdua420)

