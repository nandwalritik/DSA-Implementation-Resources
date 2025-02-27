# Bridge is an edge in a graph which when removed makes graph disconnected/ 
# increases the number of connected components

# Whole algorithm is based on two concepts
    # We need to track the starting time and lowest time of every node
    # Starting time -> time at which node was discovered during DFS
    # Lowest time -> minimum lowest time among all the nodes which are connected to current node
    # except its parent node  
# condition for bridge is consider an edge u-v
    # if the lowest time of v is  > discovery time of u then its a bridge


from collections import defaultdict

class Graph:
    def __init__(self,vertices):
        self.V = vertices
        self.graph = defaultdict(list)
        self.time = 0
    
    def add_edge(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)
    
    def dfs_bridge_util(self,u,visited,discovery_times,lowest_times,parent,bridges):
        visited[u] = True
        discovery_times[u] = self.time
        lowest_times[u] = self.time 
        self.time+=1

        for v in self.graph[u]:
            """
                Two Cases:
                    v is not yet visited
                        dfs over all its child and update the lowest_time of parent of v i.e u
                    v is already visited -> make sure its not = parent
                        means it was discovered already so update low as min of low[u],discovery[v]
            
            """
            if not visited[v]:
                self.dfs_bridge_util(v,visited,discovery_times,lowest_times,u,bridges)

                # update minm lowest time for node u
                lowest_times[u] = min(lowest_times[u],lowest_times[v])

                # check condition for bridge
                if lowest_times[v] > discovery_times[u]:
                    bridges.append((u,v))
            elif v != parent: 
                # elif means v is already visited so we need to update the low time, but it should not be equal to parent
                lowest_times[u] = min(lowest_times[u],discovery_times[v])

    def find_bridges(self):
        visited = [False]*self.V 
        discovery_times = [-1]*self.V 
        lowest_times = [float("inf")]*self.V 
        bridges = []

        for i in range(self.V):
            if not visited[i]:
                self.dfs_bridge_util(i,visited,discovery_times,lowest_times,-1,bridges)        
        return bridges
if __name__ == "__main__":
    # Example Usage
    g = Graph(5)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(1, 3)
    g.add_edge(3, 4)

    print("Bridges in the graph:", g.find_bridges())
    # Output: [(3, 4), (1, 3)]
    """
       0---1---3---4
        \  |
         \ |
          2
    """