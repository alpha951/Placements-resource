#include <bits/stdc++.h>
#define int long long int
#define float long double
#define fastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

// just memoize also

int help(int i, int j, vector<int>& t1, vector<int>& t2)
{
    if (i >= t1.size() or j >= t2.size())
        return 0;

    int ans = 0;

    if (t1[i] == t2[j]) {
        ans = 1 + help(i + 1, j + 1, t1, t2);
    } else {
        ans = max(help(i + 1, j, t1, t2), help(i, j + 1, t1, t2));
    }
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> t1(n), t2(n);
    for (int i = 0; i < n; i++)
        cin >> t1[i];

    for (int i = 0; i < n; i++)
        cin >> t2[i];

    cout << help(0, 0, t1, t2) << endl;

    return 0;
}
