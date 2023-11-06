
# Python3 Program for Floyd Warshall Algorithm
import re
import numpy as np
# Number of vertices in the graph
V = 1000

# Define infinity as the large
# enough value. This value will be
# used for vertices not connected to each other
INF = 99999

# Solves all pair shortest path
# via Floyd Warshall Algorithm


def floydWarshall(graph,start,end):
	""" dist[][] will be the output 
	matrix that will finally
		have the shortest distances 
		between every pair of vertices """
	""" initializing the solution matrix 
	same as input graph matrix
	OR we can say that the initial 
	values of shortest distances
	are based on shortest paths considering no 
	intermediate vertices """

	dist = list(map(lambda i: list(map(lambda j: j, i)), graph))

	""" Add all vertices one by one 
	to the set of intermediate
	vertices.
	---> Before start of an iteration, 
	we have shortest distances
	between all pairs of vertices 
	such that the shortest
	distances consider only the 
	vertices in the set 
	{0, 1, 2, .. k-1} as intermediate vertices.
	----> After the end of a 
	iteration, vertex no. k is
	added to the set of intermediate 
	vertices and the 
	set becomes {0, 1, 2, .. k}
	"""
	for k in range(V):

		# pick all vertices as source one by one
		for i in range(V):

			# Pick all vertices as destination for the
			# above picked source
			for j in range(V):

				# If vertex k is on the shortest path from
				# i to j, then update the value of dist[i][j]
				dist[i][j] = min(dist[i][j],
								dist[i][k] + dist[k][j]
								)
	printSolution(dist,start,end)


# A utility function to print the solution
def printSolution(dist, start, end):
    i=start
    for i in range(end-start):
        for j in range(V):
            if(dist[i][j] == INF):
                print("%7s" % ("INF"), end=" ")
            else:
                print("%7d\t" % (dist[i][j]), end=' ')
            if j == V-1:
                print()

def chunks(lst, n):
    for i in range(0, len(lst), n):
        yield lst[i:i + n]
# Driver's code

if __name__ == "__main__":
    start = input("START VERTEX:")
    end = input("END VERTEX:")
    stream = open("graph.txt")
    numbers = re.findall('[+-]?\d+',str(stream.readlines())) 
    s = []
    n = 3
    for x in range(n):
        s.append(int(numbers[x::n]))
        print(s)
    graph = [[0, 5, INF, 10],
			[INF, 0, 3, INF],
			[INF, INF, 0, 1],
			[INF, INF, INF, 0]
			]
    numbers= np.split(numbers, np.arange(0, len(numbers),3))
    print(numbers)
    print(len(numbers))
	# Function call
    floydWarshall(numbers,start,end)
# This code is contributed by Mythri J L
