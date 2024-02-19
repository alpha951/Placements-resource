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
    long long totalCost(vector<int> &costs, int k, int x) // take first or last x candidates for selection
    {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pq1, pq2; // just take max-heap for team-formation problem

        int i = 0, j = n - 1;

        long long ans = 0;
        while (k--) // k rounds of selection: selecting exactly one candidate in each round
        {
            while (pq1.size() < x and i <= j)
            {
                pq1.push(costs[i]);
                i++;
            }

            while (pq2.size() < x and i <= j)
            {
                pq2.push(costs[j]);
                j--;
            }

            int left = pq1.size() ? pq1.top() : INT_MAX;
            int right = pq2.size() ? pq2.top() : INT_MAX;

            if (left <= right)
            {
                ans += (long long)left;
                pq1.pop();
            }
            else
            {
                ans += (long long)right;
                pq2.pop();
            }
        }
        return ans;
    }
};