#include <bits/stdc++.h>
#define int long long int
#define float long double
#define fastIO               \
	ios::sync_with_stdio(0); \
	cin.tie(0);
using namespace std;

void merged(vector<int> &nums, int low, int mid, int high, unordered_map<int, int> &count)
{
	vector<int> temp;

	int i = low, j = mid + 1;

	while (i <= mid or j <= high)
	{
		if (i <= mid && j <= high)
		{
			if (nums[i] > nums[j])
			{
				//! imp : only addition in merge sort code
				count[nums[j]]++;
				temp.push_back(nums[j]);
				j++;
			}
			else if (nums[i] < nums[j])
			{
				temp.push_back(nums[i]);
				i++;
			}
			else
			{
				temp.push_back(nums[i]);
				i++;
				j++;
			}
		}
		else if (i <= mid)
		{
			temp.push_back(nums[i]);
			i++;
		}
		else if (j <= high)
		{
			temp.push_back(nums[j]);
			j++;
		}
	}

	for (int i = low; i <= high; i++)
	{
		nums[i] = temp[i - low];
	}
}

void mergeSort(vector<int> &nums, int low, int high, unordered_map<int, int> &count)
{
	if (low >= high) //! don't forget the base case
		return;

	int mid = (low + high) / 2;
	mergeSort(nums, low, mid, count);
	mergeSort(nums, mid + 1, high, count);
	merged(nums, low, mid, high, count);
}

int32_t main()
{

	vector<int> nums = {6, 1, 4, 5, 2};
	int n = nums.size();
	unordered_map<int, int> count;
	mergeSort(nums, 0, n - 1, count);
	int ans = 0;

	for (auto &x : count)
	{
		ans = max(ans, x.second);
	}
	cout << ans << endl;
	return 0;
}