#include <bits/stdc++.h>
using namespace std;
void solve(int src, int dest, vector<int> adj[], int n)
{
    vector<pair<int, int>> newAdj[n];
    for (int i = 0; i < n; i++)
    {
        int u = i;
        for (auto v : adj[i])
        {
            newAdj[u].push_back({v, 0});
            newAdj[v].push_back({u, 1});
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    vector<int> cost(n, INT_MAX);
    cost[src] = 0;
    while (!pq.empty())
    {
        auto pnt = pq.top().second;
        pq.pop();
        for (auto x : newAdj[pnt])
        {
            if (x.second + cost[pnt] < cost[x.first])
            {
                cost[x.first] = x.second + cost[pnt];
                pq.push({cost[x.first], x.first});
            }
        }
    }
    cout << "Minimum cost required " << cost[dest] << endl;
    return;
}
int main()
{
    int n, e;
    // taking 0 based numbering for vertices of graph
    cin >> n >> e;
    vector<int> adj[n];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int src, dest;
    cin >> src >> dest;
    solve(src, dest, adj, n);
    return 0;
}