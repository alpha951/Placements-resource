#include <bits/stdc++.h>
#define int long long int
#define float long double
#define fastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

long long getHash(string& s)
{
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int power(int x, int y, int mod)
{
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res % mod;
}

void help(int cur, int sum, vector<int>& nums, unordered_set<int>& st)
{
    if (cur >= nums.size()) {
        st.insert(sum);
        return;
    }
    help(cur + 1, sum + nums[cur], nums, st);
    help(cur + 1, sum, nums, st);
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        unordered_set<int> st;
        help(0, 0, nums, st);
        cout << st.size() << endl;
    }
    return 0;
}
