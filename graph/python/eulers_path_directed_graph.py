from collections import defaultdict, deque

def find_eulerian_path(graph):
    # Step 1: Compute in-degrees and out-degrees
    in_degree = defaultdict(int)
    out_degree = defaultdict(int)
    
    for u in graph:
        for v in graph[u]:
            out_degree[u] += 1
            in_degree[v] += 1

    # Step 2: Find start and end nodes
    start = None
    end = None
    for node in set(in_degree) | set(out_degree):
        if out_degree[node] - in_degree[node] == 1:
            if start is None:
                start = node
            else:
                return None  # More than one start node
        elif in_degree[node] - out_degree[node] == 1:
            if end is None:
                end = node
            else:
                return None  # More than one end node
        elif in_degree[node] != out_degree[node]:
            return None  # Not an Eulerian path

    # Step 3: Choose start node
    if start is None:
        start = next(iter(graph))  # Pick any node with outgoing edges

    # Step 4: Recursive function to construct Eulerian path
    path = deque()

    def dfs(node):
        while graph[node]:  # While there are outgoing edges
            next_node = graph[node].pop()  # Remove an edge
            dfs(next_node)
        path.appendleft(node)  # Add node to path after visiting all edges

    # Step 5: Find Eulerian Path
    dfs(start)

    # Step 6: Validate path (should use all edges)
    total_edges = sum(len(v) for v in graph.values())
    if len(path) - 1 == total_edges:
        return list(path)
    return None  # No Eulerian path

# Example graph as an adjacency list
graph = {
    0: [1],
    1: [2],
    2: [3],
    3: [0, 4],
    4: [2]
}

# Convert adjacency list to a mutable format (lists)
graph = {k: list(v) for k, v in graph.items()}

eulerian_path = find_eulerian_path(graph)
print("Eulerian Path:", eulerian_path)
