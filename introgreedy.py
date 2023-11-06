import numpy as np
# Python3 program for activity selection problem.

# The following implementation assumes that the activities
# are already sorted according to their finish time

# Prints a maximum set of activities that can be done 
# by a single person, one at a time
def printMaxActivities(s, f):
	n = len(f)
	print("Following activities are selected")
	print(n)
	# The first activity is always selected
	i = 0
	print(i, end=' ')

	# Consider rest of the activities
	for j in range(1, n):

		# If this activity has start time greater than
		# or equal to the finish time of previously
		# selected activity, then select it
		if s[j] >= f[i]:
			print(j, end=' ')
			i = j


# Driver code
if __name__ == '__main__':
 s = []
 f = []
 sum=0

 for i in range(1,101):
     i*=6
     s.append(i+1)
     f.append(i+3)
 # Function call
 Z = [x for _,x in sorted(zip(f,s))]
 s=Z 
 printMaxActivities(s,f)
 print(sum)
# This code is contributed by Nikhil Kumar Singh
