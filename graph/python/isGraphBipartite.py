from queue import Queue

def is_bipartite(graph):
    n = len(graph)
    color = [-1] * n  # -1 means uncolored
    
    for start in range(n):  # Check all components of the graph
        if color[start] == -1:  # Start BFS for unvisited component
            q = Queue()
            q.put(start)
            color[start] = 0  # Start coloring with 0
            
            while not q.empty():
                node = q.get()
                for neighbor in graph[node]:
                    if color[neighbor] == -1:  # If not colored, color with opposite
                        color[neighbor] = 1 - color[node]
                        q.put(neighbor)
                    elif color[neighbor] == color[node]:  # Conflict found
                        return False
    return True

# Example graph (Adjacency List)
graph = {
    0: [1, 3],
    1: [0, 2],
    2: [1, 3],
    3: [0, 2]
}

print(is_bipartite(graph))  # Output: True (Graph is Bipartite)
