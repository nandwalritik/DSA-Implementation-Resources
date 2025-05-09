"""
    To determine that a given graph contains hamiltonian cycle or not
    Hamiltonian Path :- A path in undirected graph which visits every vertex exactly once
    If there is an articulation point in graph then hamil cycle wont exist
    
"""

"""
    Code will remain same as hamiltonian path, only the base case for recurssive
    call will change

"""
"""
    A Hamiltonian Path in a graph is a path that visits every vertex exactly once.

"""

def is_hamiltonian_path(graph,path,visited,n):
    # if path includes all vertices we found a hamiltonian path
    if len(path) == n:
        return path[0] in graph[path[-1]]
    
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
            path.append(path[0]) # closing the cycle
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