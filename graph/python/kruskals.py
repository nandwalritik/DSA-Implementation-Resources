class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n  # Rank optimization
    
    def find(self, v):
        if self.parent[v] != v:
            self.parent[v] = self.find(self.parent[v])  # Path compression
        return self.parent[v]

    def union(self, u, v):
        root1 = self.find(u)
        root2 = self.find(v)

        if root1 != root2:
            if self.rank[root1] > self.rank[root2]:
                self.parent[root2] = root1
            elif self.rank[root1] < self.rank[root2]:
                self.parent[root1] = root2
            else:
                self.parent[root2] = root1
                self.rank[root1] += 1

def kruskal(n, edges):
    edges.sort(key=lambda x: x[2])  # Sort edges by weight
    ds = DisjointSet(n)
    mst = []
    total_weight = 0

    for u, v, weight in edges:
        if ds.find(u) != ds.find(v):  # If adding edge does not form a cycle
            ds.union(u, v)
            mst.append((u, v, weight))
            total_weight += weight

            if len(mst) == n - 1:  # MST complete
                break

    return mst, total_weight

# Example Usage
edges = [
    (0, 1, 10), (0, 2, 6), (0, 3, 5),
    (1, 3, 15), (2, 3, 4)
]
n = 4  # Number of nodes

mst, weight = kruskal(n, edges)
print("MST Edges:", mst)
print("Total MST Weight:", weight)
