# SCC - for every pair of i,j if i remove the edge between i and j they will still be connected

from collections import defaultdict


class KosarajuSCC:
    def __init__(self,num_nodes):
        self.graph = defaultdict(list)
        self.reversed_graph = defaultdict(list)
        self.V = num_nodes

    def add_edge(self,u,v):
        self.graph[u].append(v)
        self.reversed_graph[v].append(u)
    
    def dfs(self,u,visited,stack):
        visited[u] = True
        for v in self.graph[u]:
            if not visited[v]:
                self.dfs(v,visited,stack)
        stack.append(u)
    
    def rev_dfs(self,u,visited,component):
        visited[u] = True
        component.append(u)
        for v in self.reversed_graph[u]:
            if not visited[v]:
                self.rev_dfs(v,visited,component)
    
    def find_sccs(self):
        stack = []

        visited = [False]*self.V

        for i in range(self.V):
            if not visited[i]:
                self.dfs(i,visited,stack)

        visited = [False]*self.V
        sccs = []
        while stack:
            u = stack.pop()
            if not visited[u]:
                component = []
                self.rev_dfs(u,visited,component)
                sccs.append(component)
        return sccs
        
if __name__ == "__main__":
    # Example Usage
    g = KosarajuSCC(5)
    edges = [(0, 2), (2, 1), (1, 0), (0, 3), (3, 4)]
    for u, v in edges:
        g.add_edge(u, v)

    print(g.find_sccs())  # Output: [[0, 2, 1], [3], [4]]