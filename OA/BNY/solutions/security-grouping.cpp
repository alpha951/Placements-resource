#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(unordered_map<int, int> &mp, int f, int &ans)
{
    int cur = 0;
    for (auto &x : mp)
    {
        int y = x.second; // freq of x.first server

        int a = y % (f + 1);
        int b = y / (f + 1);

        if (a == 0) // try max size grp , to minimize no. of grps
        {
            cur += b; // b levels required
        }
        else if (a % f == 0) // remaining servers of x.first type can be used by f
        {
            cur += b;
            cur += a / f;
        }
        else if (y % f == 0)
        {
            cur += y / f;
        }
        else
        {
            return false;
        }
    }
    ans = cur;
    return true;
}

int solve(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    for (auto &x : nums)
        mp[x]++;

    int min_freq = 1e9; // finding min_freq since one security level can has only same value server
    for (auto &x : mp)
        min_freq = min(min_freq, x.second);

    int ans = 1e9;
    for (int i = min_freq; i >= 0; i--)
    {
        int temp = 1e9;
        if (isPossible(mp, i, temp))
        {
            ans = min(ans, temp);
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {2, 2, 2, 3, 3, 1};
    int n = nums.size();
    unordered_map<int, int> mp;
    for (auto &x : nums)
        mp[x]++;

    int min_freq = 1e9; // finding min_freq since one security level can has only same value server
    for (auto &x : mp)
        min_freq = min(min_freq, x.second);

    int ans = 1e9;
    for (int i = min_freq; i >= 0; i--)
    {
        int temp = 1e9;
        if (isPossible(mp, i, temp))
        {
            ans = min(ans, temp);
        }
    }
    cout << ans << endl;
    return 0;
}