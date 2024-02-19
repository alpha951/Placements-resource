#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://leetcode.com/discuss/interview-question/3818935/BNY-Mellon-Internship-OA-oror-75k-Stipend

int mask(vector<int> &nums)
{
    int m = 0;
    for (auto &x : nums)
    {
        m |= (1 << (x - 1)); //?  why (x-1) : to make 1 based indexing work so for x==1, 0th bit will set
    }
    return m;
}

int solve(vector<vector<int>> &customer, vector<vector<int>> &shops)
{
    //* only two shops can be opened at once

    unordered_map<int, int> mp;

    for (auto &c : customer)
    {
        mp[mask(c)]++; //! it stores the freq of a particular combination of customers choices of products
    }

    unordered_set<int> st;

    for (auto &s : shops)
    {
        st.insert(mask(s)); //! stores the unique offering of combinations of products offers by all shops
    }

    int ans = 0;

    for (auto itr1 = st.begin(); itr1 != st.end(); itr1++)
    {
        for (auto itr2 = itr1; itr2 != st.end(); itr2++)
        {
            int totalProducts = (*itr1) | (*itr2); //! total pdts which two shops can offer together
            int cur = 0;
            for (auto &c : mp)
            {
                if ((c.first & totalProducts) == c.first)
                {
                    cur += c.second; //! add all the customer count who need c.first set of products
                }
            }
            ans = max(ans, cur);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> customer = {{1, 2}, {1, 5}};
    vector<vector<int>> shops = {{1, 2, 3, 4}, {2, 3, 4, 5}, {1, 2, 4, 5}};
    cout << solve(customer, shops) << endl;
    return 0;
}