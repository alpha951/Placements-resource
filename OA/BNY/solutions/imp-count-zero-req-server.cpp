#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}

class Solution
{
public:
    vector<int> countServers(int totalServer, vector<vector<int>> &logs, int x, vector<int> &query)
    {
        int n = query.size();

        sort(logs.begin(), logs.end(), [&](auto &a, auto &b)
             { return a[1] <= b[1]; });

        unordered_map<int, int> mpq; // q, idx  for query
        for (int i = 0; i < n; i++)
        {
            mpq[query[i]] = i;
        }

        sort(query.begin(), query.end());

        unordered_map<int, int> mp;
        int i = 0, j = 0;
        vector<int> ans(n);

        for (auto &q : query)
        {
            int s = q - x, e = q;

            // count all unique servers till end time
            while (j < logs.size() && logs[j][1] <= e)
            {
                mp[logs[j][0]]++;
                j++;
            }

            while (i < logs.size() && logs[i][1] < s)
            {
                mp[logs[i][0]]--;
                if (mp[logs[i][0]] == 0)
                    mp.erase(logs[i][0]);
                i++;
            }
            ans[mpq[q]] = totalServer - mp.size();
        }
        return ans;
    }
};