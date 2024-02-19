#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &tree, int node, int parent)
{
    int maxi = 0;
    for (int child : tree[node])
    {
        if (child != parent)
        {
            maxi = max(maxi, dfs(tree, child, node));
        }
    }

    return maxi + 1;
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

    int root = 1;
    for (int i = 1; i <= n; i++)
    {
        if (tree[i].size() == 1)
        {
            root = i;
            break;
        }
    }

    int ans = dfs(tree, root, 0);
    cout << ans << endl;

    return 0;
}
