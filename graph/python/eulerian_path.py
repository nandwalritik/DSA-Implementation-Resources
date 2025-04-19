from collections import defaultdict

class EulerianGraph:
    def __init__(self, n, edges):
        self.n = n
        self.graph = defaultdict(list)
        self.degree = [0] * n
        self.edges = edges
        self.path = []

        for u, v in edges:
            self.add_edge(u, v)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)
        self.degree[u] += 1
        self.degree[v] += 1

    def is_connected(self):
        visited = [False] * self.n
        start = next((i for i in range(self.n) if self.degree[i] > 0), -1)
        if start == -1: return True

        def dfs(u):
            visited[u] = True
            for v in self.graph[u]:
                if not visited[v]:
                    dfs(v)

        dfs(start)
        return all(visited[i] or self.degree[i] == 0 for i in range(self.n))

    def eulerian_type(self):
        if not self.is_connected():
            return "Not Eulerian", None

        odd_vertices = [i for i in range(self.n) if self.degree[i] % 2 == 1]

        if len(odd_vertices) == 0:
            return "Eulerian Circuit", 0
        elif len(odd_vertices) == 2:
            return "Eulerian Path", odd_vertices[0]
        else:
            return "Not Eulerian", None

    def find_eulerian_path(self):
        g_copy = defaultdict(list)
        for u in self.graph:
            for v in self.graph[u]:
                g_copy[u].append(v)

        def dfs(u):
            while g_copy[u]:
                v = g_copy[u].pop()
                g_copy[v].remove(u)
                dfs(v)
            self.path.append(u)

        graph_type, start = self.eulerian_type()
        if graph_type == "Not Eulerian":
            return []

        dfs(start)
        return self.path[::-1]  # Reverse to get correct order

# Example Usage:
n = 5
edges = [(0, 1), (1, 2), (2, 0), (1, 3), (3, 4)]
g = EulerianGraph(n, edges)
path = g.find_eulerian_path()
print("Eulerian Path/Circuit:", path)
