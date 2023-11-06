import re 
# Initializing the distance and
# Next array
from collections import defaultdict
 
# Function to solve the task 
MAXM,INF = 990,10**7
V = 990 
import sys
 
 

class Graph():
 

    def __init__(self, vertices):

        self.V = vertices

        self.graph = [[0 for column in range(vertices)]

                      for row in range(vertices)]
 

    def printSolution(self, dist):

        print("Vertex \tDistance from Source")

        for node in range(self.V):

            print(node, "\t", dist[node])
 

    # A utility function to find the vertex with

    # minimum distance value, from the set of vertices

    # not yet included in shortest path tree

    def minDistance(self, dist, sptSet):
 

        # Initialize minimum distance for next node

        min = sys.maxsize
 

        # Search not nearest vertex not in the

        # shortest path tree

        for u in range(self.V):

            if dist[u] < min and sptSet[u] == False:

                min = dist[u]

                min_index = u
 

        return min_index
 

    # Function that implements Dijkstra's single source

    # shortest path algorithm for a graph represented

    # using adjacency matrix representation

    def dijkstra(self, src):
 

        dist = [sys.maxsize] * self.V

        dist[src] = 0

        sptSet = [False] * self.V
 

        for cout in range(self.V):
 

            # Pick the minimum distance vertex from

            # the set of vertices not yet processed.

            # x is always equal to src in first iteration

            x = self.minDistance(dist, sptSet)
 

            # Put the minimum distance vertex in the

            # shortest path tree

            sptSet[x] = True
 

            # Update dist value of the adjacent vertices

            # of the picked vertex only if the current

            # distance is greater than new distance and

            # the vertex in not in the shortest path tree

            for y in range(self.V):

                if (self.graph[x][y] > 0 and sptSet[y] == False):
                    dist[y] = dist[x] + self.graph[x][y]
 

        self.printSolution(dist)

def find(pairs):
    mapp = defaultdict(list)
    for x, y , z in pairs:
        mapp[x].append(y)
        mapp[x].append(z)
    return [(x, *y) for x, y in mapp.items()]

def initialise(V):
    global dist, Next 
    for i in range(V):
        for j in range(V):
            thing_index = graph[i].index(j) if j in graph[i] else INF
            dist[i][j] = thing_index             # No edge between node
            # i and j
            if (thing_index == INF):
                Next[i][j] = -1
            else:
                Next[i][j]  = j
 
# Function construct the shortest
# path between u and v
def constructPath(u, v):
    global graph, Next, weight 
    # If there's no path between
    # node u and v, simply return
    # an empty array
    if (Next[u][v] == -1):
        return {} 
    # Storing the path in a vector
    path = [u]
    while (u != v):
        weight+= dist[u][Next[u][v]]
        u = Next[u][v]
        path.append(u)
    return path
 
# Standard Floyd Warshall Algorithm
# with little modification Now if we find
# that dis[i][j] > dis[i][k] + dis[k][j]
# then we modify next[i][j] = next[i][k]
def floydWarshall(V):
    global dist, Next
    for k in range(V):
        for i in range(V):
            for j in range(V):
                # We cannot travel through
                # edge that doesn't exist
                if (dist[i][k] == INF or dist[k][j] == INF):
                    continue
                if (dist[i][j] > dist[i][k] + dist[k][j]):
                    dist[i][j] = dist[i][k] + dist[k][j]
                    Next[i][j] = Next[i][k] 
# Print the shortest path
def printPath(path):
    n = len(path)
    for i in range(n - 1): 
        print(path[i], end=" -> ")
    print (path[n - 1])
 
if __name__ == "__main__":
    dist = [[-1 for i in range(MAXM)] for i in range(MAXM)]
    Next = [[-1 for i in range(MAXM)] for i in range(MAXM)]
    weight=0
    stream = open("graph.txt")
    numbers = re.findall('[+-]?\d+',str(stream.readlines()))
    numbers = [int(x) for x in numbers]
    graph = [numbers[i:i+3] for i in range (0, len(numbers),3) ]
    #now need to convert seperate graphs into vertex # -bound representatons 
    graph = find(graph)
    print(graph)
    print(len(graph))
    V= 990
    g= Graph(V)
    g.graph = graph
    g.dijkstra(0)
    #now must go for each graph[i][0], and interate up to graph[i][j] to store edge weights in a row
  



 
  
# This code is contributed by Divyanshu Mehta and Updated by Pranav Singh Sambyal
