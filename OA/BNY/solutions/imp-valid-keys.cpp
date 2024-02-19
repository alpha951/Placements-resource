#include <bits/stdc++.h>
using namespace std;
#define ll long long

void seive(int n, vector<int> &prime)
{
    prime[0] = 0, prime[1] = 0;

    //! rem i*i <= n
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == 1)
        {
            // update all numbers greater than or equal to square of i
            // numbers which are multiple of i and less than square of i have been already marked false(not prime)
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

vector<int> validKeys(vector<int> &nums)
{
    int n = nums.size();
    int maxi = *max_element(nums.begin(), nums.end());
    int M = sqrt(maxi);
    vector<int> prime(M + 1, 1);
    seive(M, prime);
    map<int, int> mp; // num cnt

    int cnt = 0;
    for (int i = 2; i <= M; i++)
    {
        if (prime[i])
        {
            cnt++;
            mp[i] = cnt;
        }
    }
    vector<int> ans;
    for (auto &key : nums)
    {
        int val = sqrt(key);
        auto itr = mp.upper_bound(val);
        itr--;
        ans.push_back(itr->second);
    }
    return ans;
}

int main()
{
    vector<int> nums = {5, 11};
    vector<int> ans = validKeys(nums);
    for (auto &x : ans)
        cout << x << " ";
    return 0;
}
