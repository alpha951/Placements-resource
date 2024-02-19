#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &tree, int node, int parent)
{
    int max1 = 0;
    for (int child : tree[node])
    {
        if (child != parent)
        {
            int depth = dfs(tree, child, node);
            if (depth >= max1)
            {
                max1 = depth;
            }
        }
    }
    return max1 + 1;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);    

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int goodness = dfs(tree, i, 0);
        ans = max(ans, goodness);
    }
    return 0;
}


