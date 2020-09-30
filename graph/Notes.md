Types of Graphs:
	Directed Graph
	Unidirected Graph
Note :- Adjacency matrix for undirected graph is always symmetric	
Graph Representation 
	Adjadency Matrix
	Adjacency List

Operations on Graph:
	1.Create 
	2.Clear 
	3.IsEmpty
	4.Traversing
	5.Print

Types of traversal in Graphs:
	Depth First :- Similar to preorder(root,left,right) traversal of 		binary tree
	DFS in tree uses backtracking
	
	/*Write Your logic here*/
	Applications of DFS:-
		Topological sorting
		Finding connected components
		Finding articulation points(cut vertices) of the graph
		Finding strongly connected components
		Solving puzzles such as mazes
	
	Breadth First :- Similar to levelOrder tr++aversal of binary trees
	
	
	
	Applications of BFS
		Finding all connected components in graph
		Finding all nodes within one connected component
		Finding all shortest path between two nodes
		Testing a graph for bipariteness
/*Imoortant theory coursera*/
1.) If a graph has cycle than it cannot be linearly ordered.
2.) Instead of traversing whole path again to find the sink , we can keep a trace ....  so we use STACK in topological Sorting
3.) In directed graph we can say that u and v are connected if both are reachable from each other.
4.)So the result is that you have a directed graph. It can always be partitioned into strongly connected components. Such that two vertices are connected if and only if they're in the same component.
