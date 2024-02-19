#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*

Given an integer array arr that consists of n elements, and 2 integers k and x, find the number of pairs of indices i, j (0 ≤ i, j < n) such that arr[i]<=arr[j] and there are exactly k elements in the range [arr[i], arr[j]] that are divisible by x.

Example :

Consider n = 4, arr = [1, 3, 5, 7], k = 2 and x= 2.

The valid pairs of indices are:

⚫ (0, 2): arr[0] = 1, arr[2] = 5. Number of elements in [1, 5] divisible by 2 are 2. i.e. 2 and 4, which equals k.

⚫ (1,3): arr[1] = 3, arr[3] = 7. Number of elements in [3, 7] divisible by 2 are 2. i.e.4 and 6, which equals k.

*/

int f(vector<int> nums, int x, int k)
{
    vector<int> prefix(nums.size(), 0);
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        prefix[i] = nums[i] / x;
    }

    int start = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        int c = prefix[i] - prefix[start];
        if (c == k)
            ans.push_back({start, i});

        // sliding window
        while (c > k)
        {
            if (start == i)
                break;
            start++;
            c = prefix[i] - prefix[start];
            if (c == k)
                ans.push_back({start, i});
        }
    }
    return ans.size();
}

// int solve(vector<int> &nums, int k, int x)
// {
// }

int main()
{
    vector<int> nums = {1, 3, 5, 7};
    cout << f(nums, 2, 2) << endl;
    return 0;
}