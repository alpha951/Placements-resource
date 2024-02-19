
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Here, we have to find the number of subarrays having its OR equal to some element of that subarray.

! Reframing the problem, we can state it as Print ANS VECTOR where ANS[I] tells the number of subarrays having OR equal to Arr[I] where Arr is given the initial array.

* Now, Solve this problem by iterating over all bits. Store the indices for each bit, where the corresponding bit of arr[I] is set.

Now, to get the OR=arr[I], the only condition is that all unset bits of arr[I] should be unset in each element of valid subarray.

!! For unsets bit in arr[I], get the maximum index less than i where the any unset bit was set,
!! similarly get minimum greater than i where any unset bit was set.

We can find it using lower bound. Now the valid subarrays can be found using simple math formula. You have now rightmost index, i and leftmost index. Just apply simple maths now.

At last return the sum of ANS vector.
*/

int func(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> prefix(n), suffix(n);

    vector<int> pre(32, -1), suff(32, n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            if ((arr[i] & (1 << j)) != 0) //! checks if the `j`th bit of `arr[i]` is set or not
            {
                pre[j] = max(pre[j], i); // ? why max  : It checks that till `i-th` index what is the maximum index of arr where the `j-th` bit of arr[i] is set
            }
            prefix[i] = pre; //! `pre` is vector<int>
        }
    }

    //! reverse traversal
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < 32; ++j)
        {
            if ((arr[i] & (1 << j)) != 0)
            {
                suff[j] = min(suff[j], i); // ? why min : minimum greater than i where any unset bit was set
            }
        }
        suffix[i] = suff; //! `suff` is vector<int>
    }

    int ans = 0;

    //!  the number of subarrays having OR equal to arr[i]

    for (int i = 0; i < n; ++i)
    {
        int left = -1, right = n;

        // For unsets bit in arr[I], get the maximum index less than i where the any unset bit was set,
        // similarly get minimum greater than i where any unset bit was set.
        for (int j = 0; j < 32; ++j)
        {
            if ((arr[i] & (1 << j)) == 0) // ? why
            {
                left = max(left, prefix[i][j]);
                right = min(right, suffix[i][j]);
            }
        }

        // ? check is very necessary to handle counting the subarray only once take this example to understand {7, 7, 7, 7}.  If we do not check this condition then it will count the same subarray twice

        if (arr[left + 1] != arr[i])
        {
            ans += (i - (left + 1)); // subarray will be from left+1 to i
        }
        ans += (right - i);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 3};
    cout << func(arr) << endl; // 5 (correct)
    return 0;
}