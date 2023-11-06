
# This is the memoization approach of 
# 0 / 1 Knapsack in Python in simple 
# we can say recursion + memoization = DP 
import re 
import math
import sys

def knapsack(wt, val, W, n): 

	# base conditions 
	if n == 0 or W == 0: 
		return 0


	# choice diagram code 
	if wt[n-1] <= W: 
		wt[n][W] = max( 
			val[n-1] + knapsack( 
				wt, val, W-wt[n-1], n-1), 
			knapsack(wt, val, W, n-1)) 
		return wt[n][W] 
	elif wt[n-1] > W: 
		wt[n][W] = knapsack(wt, val, W, n-1) 
		return wt[n][W]

# Driver code 
if __name__ == '__main__':
    sys.setrecursionlimit(1500)
    stream = open("8(1).txt")
    nums = stream.readlines()
    numbers = re.findall('[+-]?\d+',str(nums))    
    W= int(numbers[0])
    numbers= numbers[:0] + numbers[(1):]
    n =1
    List = [numbers[i:i + 3] 
        for i in range(len(numbers) -2)]
    List = List[0::3]
    profit =  [ ]
    weight =[]
    for i in range(len(List)):
        profit.append(int(List[i][0]))
    for j in range(len(List)):
        weight.append(int(List[j][1]))
    print(profit)
    print(weight)
    n=len(profit)
    print(knapsack(weight, profit, W, n)) # This code is contributed by Prosun Kumar Sarkar 
# if __name__ == '__main__': 
#	profit = [60, 100, 120] 
#	weight = [10, 20, 30] 
#	W = 50
#	n = len(profit) 
	
	# We initialize the matrix with -1 at first. 
#	t = [[-1 for i in range(W + 1)] for j in range(n + 1)] 
#	print(knapsack(weight, profit, W, n)) 

