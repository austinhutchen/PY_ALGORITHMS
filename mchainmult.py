# Python code to implement the
# matrix chain multiplication using recursion
import re
# Dynamic Programming Python implementation of Matrix
# Chain Multiplication. See the Cormen book for details
# of the following algorithm
def MatChainMul(arr, n):
    dp = [[0 for i in range(n)] for j in range(n)]
    for i in range(1, n):
        dp[i][i] = 0
    
    for L in range(2, n):
        for i in range(1, n-L+1):
            j = i+L-1
            dp[i][j] = 10**10
            for k in range(i, j):
                q = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]
                if q < dp[i][j]:
                    dp[i][j] = q
    
    return dp[1][n-1]
 

if __name__ == '__main__':
    stream = open("10(3).txt")
    nums = stream.readlines()
    numbers = re.findall('[+-]?\d+',str(nums)) 
    print(numbers)
    numbers = [ int(x) for x in numbers]
    end = numbers[-1]
    arr = numbers[0::2]
    arr.append(end)
    print("-----")
    print(arr)
    print ("LEN:")
  
    N = len(arr) 	
    print(N)
	# Function call
    print("Minimum number of multiplications is ",	MatChainMul(arr, N))

# This code is contributed by Aryan Garg
