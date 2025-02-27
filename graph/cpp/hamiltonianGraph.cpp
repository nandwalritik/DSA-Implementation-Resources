/*
    To determine that a given graph contains hamiltonian cycle or not
    Hamiltonian Path :- A path in undirected graph which visits every vertex exactly once


*/

#include <bits/stdc++.h>
using namespace std;
bool isSafe(int vertex, vector<vector<int>> &graph, vector<int> &path, int index)
{
    // check if this vertex is adjacent to previously added vertex
    if (graph[path[index - 1]][vertex] == 0)
        return false;
    // check if it's already included or not
    for (int i = 0; i <= index - 1; i++)
    {
        if (path[i] == vertex)
            return false;
    }
    return true;
}
bool hashamCycle(vector<vector<int>> &graph, vector<int> &path, int index, int n)
{
    // If all vertices have been included
    if (index == n)
    {
        // we need to check if there is a path
        // from last added vertex to first added vertex
        if (graph[path[index - 1]][path[0]] != 1)
            return false;
        else
            return true;
    }
    // try out possible candidates for next index
    for (int v = 1; v < n; v++)
    {
        if (isSafe(v, graph, path, index))
        {
            path[index] = v;
            if (hashamCycle(graph, path, index + 1, n))
                return true;
            // backtrack
            path[index] = -1;
        }
    }
    return false;
}
int main()
{
    int n = 5;
    vector<vector<int>> graph{{0, 1, 0, 1, 0},
                              {1, 0, 1, 1, 1},
                              {0, 1, 0, 0, 1},
                              {1, 1, 0, 0, 1},
                              {0, 1, 1, 1, 0}};
    vector<int> path(n, -1);
    path[0] = 0;
    if (hashamCycle(graph, path, 1, 5))
    {
        cout << "Hamiltonian Path\n";
        for (auto x : path)
            cout << x << " ";
        cout << endl;
    }
    else
    {
        cout << "No hamiltonian path exist\n";
    }
    return 0;
}