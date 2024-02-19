#include <bits/stdc++.h>
#define int long long int
#define float long double
#define fastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

int32_t main()
{

    vector<int> nums = {4, 3}; // initial servers
    vector<int> money = {8, 9};
    vector<int> sell = {4, 2};
    vector<int> upgrade = {4, 5};
    int n = nums.size();
    vector<int> ans(n);

    for (int i = 0; i < n; ++i)
    {
        int low = 0, high = nums[i];
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int totalCost = (mid)*upgrade[i] - (nums[i] - mid) * sell[i];
            if (totalCost <= money[i])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        ans[i] = low - 1;
    }

    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
