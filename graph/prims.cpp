#include <bits/stdc++.h>
using namespace std;
/*
    LOGIC
    1.) Maintain two sets
        i.)  First set contains vertices already included in MST
        ii.) Second set contains vertices not yet included.
    
    2.) At every step consider all edges that connects two sets
        pick the minm weight edge from these edges.


*/
int main()
{
    int N, m;
    cin >> N >> m;
    vector<pair<int, int>> adj[N];
    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    int parent[N];
    int key[N];
    bool mstSet[N];

    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX, mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    int cost = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int minI = INT_MAX, u;
        for (int v = 0; v < N; v++)
        {
            if (mstSet[v] == false && key[v] < minI)
            {
                minI = key[v], u = v;
            }
        }
        mstSet[u] = true;
        cost += minI;
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u, key[v] = weight;
            }
        }
    }
    cout << cost << endl;
    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << " " << i << "\n";
    }
    return 0;
}