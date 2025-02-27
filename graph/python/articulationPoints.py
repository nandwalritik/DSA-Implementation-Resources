# An articulation point (or cut vertex) is defined as a vertex which, when
# removed along with associated edges, makes the graph disconnected (or 
# more precisely, increases the number of connected components in the graph). 

# Steps to find articulation, logic remains almost same as bridges
    # mark the discovery and lowest time for a node u (see bridges)
    # for any node u check if its root i.e parent == -1 and its children are > 1
    # Two cases for ap
        # Case 1: Root node with 2 or more children
        # Case 2:  non root node where lowest_time[v] >= discovery[u]

from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)
        self.time = 0  
    
    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)
    
    def ap_util(self,u,visited,discovery_times,lowest_times,parent,ap):
        visited[u] = True
        discovery_times[u] = lowest_times[u] = self.time 
        self.time+=1
        children = 0
        for v in self.graph[u]:
            if not visited[v]:
                children+=1
                self.ap_util(v,visited,discovery_times,lowest_times,u,ap)
                lowest_times[u] = min(lowest_times[u],lowest_times[v])

                if parent == -1 and children > 1:
                    ap.add(u)
                if parent != -1 and lowest_times[v] >= discovery_times[u]:
                    ap.add(u)

            elif v != parent:
                lowest_times[u] = min(lowest_times[u],discovery_times[v])

    def find_articulation_points(self):
        visited = [False]*self.V 
        discovery_times = [-1]*self.V 
        lowest_times = [-1]*self.V 
        ap = set()
        for i in range(self.V):
            if not visited[i]:
                self.ap_util(i,visited,discovery_times,lowest_times,-1,ap)
        return list(ap)
if __name__ == "__main__":
    g = Graph(5)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(1, 3)
    g.add_edge(3, 4)

    print("Articulation Points:", g.find_articulation_points())
    """
         0
        / \
        1---2
        \
        3---4

    
    
    """