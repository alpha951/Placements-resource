#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dfs(int node, vector<vector<int>> &adj, vector<int> &dist, int par)
{
    int depth = 0;

    for (auto &child : adj[node])
    {
        if (child != par)
        {
            depth = max(depth, dfs(child, adj, dist, node));
        }
    }

    return dist[node] = depth + 1;
}

int help(int g_nodes, vector<int> &g_from, vector<int> &g_to)
{
    vector<vector<int>> adj(g_nodes + 1);
    for (int i = 0; i < g_from.size(); i++)
    {
        adj[g_from[i]].push_back(g_to[i]);
        adj[g_to[i]].push_back(g_from[i]);
    }

    // find max_depth node from any node let say from g_node = 1
    vector<int> dist(g_nodes + 1);
    dfs(1, adj, dist, -1);
    int max_depth_node = 0, max_depth = 0;
    for (int i = 1; i <= g_nodes; i++)
    {
        if (dist[i] > max_depth)
        {
            max_depth = dist[i];
            max_depth_node = i;
        }
        dist[i] = 0;
    }
    dfs(max_depth_node, adj, dist, -1);
    return *max_element(dist.begin(), dist.end());
}

int main()
{
    vector<int> from = {4, 2, 4, 2, 1, 2}, to = {2, 1, 7, 5, 6, 3};
    cout << help(7, from, to) << endl;
    return 0;
}
