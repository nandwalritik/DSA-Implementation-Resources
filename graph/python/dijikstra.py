import heapq

def dijkstra(graph, start):
    # Priority queue to store (cost, node)
    pq = [(0, start)]
    # Dictionary to store the shortest path to each node
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    
    while pq:
        current_distance, current_node = heapq.heappop(pq)
        
        # If the popped distance is greater than recorded, skip processing
        if current_distance > distances[current_node]:
            continue
        
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight
            
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
    
    return distances

# Example Graph as an adjacency list
graph = {
    'A': {'B': 4, 'C': 1},
    'B': {'A': 4, 'C': 2, 'D': 5},
    'C': {'A': 1, 'B': 2, 'D': 8, 'E': 10},
    'D': {'B': 5, 'C': 8, 'E': 2},
    'E': {'C': 10, 'D': 2}
}

start_node = 'A'
shortest_paths = dijkstra(graph, start_node)
print(shortest_paths)
