import heapq

def prim(n, graph):
    visited = [False] * n
    min_heap = [(0, 0)]  # (weight, node)
    total_weight = 0
    mst = []

    while len(mst) < n - 1:
        weight, u = heapq.heappop(min_heap)  # Get min edge
        if visited[u]:  # Skip if already in MST
            continue
        visited[u] = True
        total_weight += weight

        for v, w in graph[u]:  # Process neighbors
            if not visited[v]:
                heapq.heappush(min_heap, (w, v))
                mst.append((u, v, w))

    return mst, total_weight

# Example Usage
graph = {
    0: [(1, 10), (2, 6), (3, 5)],
    1: [(0, 10), (3, 15)],
    2: [(0, 6), (3, 4)],
    3: [(0, 5), (1, 15), (2, 4)]
}
n = 4  # Number of nodes

mst, weight = prim(n, graph)
print("MST Edges:", mst)
print("Total MST Weight:", weight)
