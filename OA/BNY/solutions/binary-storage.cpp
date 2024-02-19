#include <bits/stdc++.h>
#define int long long int
#define float long double
#define fastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

int power(int x, int y, int mod = 1e9 + 5)
{
    // x^y
    int res = 1;
    while (y > 0)
    {
        if (y % 2 == 1) // odd power
            res = (res * x);
        y = y >> 1; // dividing the pow by 2
        x = (x * x);
    }
    return res % mod;
}

int32_t main()
{
    vector<vector<int>> bits = {{0, 2}, {2, 3}, {2, 1}};
    int n = bits.size();
    vector<pair<int, int>> ans; // {value, index}
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = 0; j < bits[i].size(); j++)
        {
            sum += power(2, bits[i][j]);
        }
        ans.push_back({sum, i});
    }

    sort(ans.begin(), ans.end(), greater<pair<int, int>>());

    vector<int> res;
    for (auto &x : ans)
    {
        res.push_back(x.second);
    }

    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }

    return 0;
}
