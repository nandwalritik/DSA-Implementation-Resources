"""
    A Hamiltonian Path in a graph is a path that visits every vertex exactly once.

"""

def is_hamiltonian_path(graph,path,visited,n):
    # if path includes all vertices we found a hamiltonian path
    if len(path) == n:
        return True
    
    # try out all poss next vertices
    last_vertex = path[-1]
    for v in graph[last_vertex]:
        if not visited[v]:
            visited[v] = True 
            path.append(v)
            
            if is_hamiltonian_path(graph,path,visited,n):
                return True
            
            # Backtrack
            path.pop()
            visited[v] = False
            
    return False
    
    

def find_hamiltonian_path(graph,n):
    for start in range(n):
        visited = [False]*n
        path = [start]
        visited[start] = True
        
        if is_hamiltonian_path(graph,path,visited,n):
            return path 
    
    return None    

if __name__ == "__main__":
    # Example Graph (Adjacency List)
    graph = {
        0: [1, 3],
        1: [0, 2, 3],
        2: [1, 3],
        3: [0, 1, 2]
    }

    path = find_hamiltonian_path(graph, len(graph))
    print("Hamiltonian Path:", path if path else "No Hamiltonian Path")