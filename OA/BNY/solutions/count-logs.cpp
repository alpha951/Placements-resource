#include <bits/stdc++.h>
#define int long long int
#define float long double
#define fastIO               \
	ios::sync_with_stdio(0); \
	cin.tie(0);
#define fl(i, a, b) for (int i = a; i < b; i++)
/****************************VECTOR**********************************/
#define vi vector<int>
#define pb(n) push_back(n)
#define pv() pop_back()
#define vb v.begin()
#define ve v.end()
#define del(a, i) a.erase(a.begin() + i);
#define ins(a, i, n) a.insert(a.begin() + i, n);
#define sort(v) sort(v.begin(), v.end());
#define inp(a, n)               \
	for (int i = 0; i < n; i++) \
	{                           \
		int temp;               \
		cin >> temp;            \
		a.push_back(temp);      \
	}
#define op(a, n)                \
	for (int i = 0; i < n; i++) \
	{                           \
		cout << a[i] << endl;   \
	}
/*****************************PAIRS******************************/
#define pi pair<int, int>
#define mp make_pair
#define f first
#define s second
/***************************template Functions*******************/
template <typename T>
T myMax(T x, T y)
{
	return ((x > y) ? x : y);
}

using namespace std;
/******************************Useful Functions*******************/
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}
#define wtt   \
	int t;    \
	cin >> t; \
	while (t--)
/***************************Solve( ) func ***************************************/

vector<vector<string>> findLoginCount(vector<vector<string>> &logs)
{
	map<string, map<string, int>> mp; // user : {date : login_count}
	for (auto &log : logs)
	{
		string user = log[0], date = log[2]; // log[1] is time
		mp[user][date]++;
	}
	vector<vector<string>> ans;

	for (auto &x : mp)
	{
		string user = x.first;
		for (auto &y : x.second)
		{
			vector<string> temp;
			temp.push_back(user);
			temp.push_back(y.first);
			temp.push_back(to_string(y.second));
			ans.push_back(temp);
		}
	}

	return ans;
}

bool validTime(string time)
{
	// 00 <= hh<= 23
	// 00<= ss<= 60
	// 00 <= mm <= 60
}

bool validDate(string date)
{
	// 01 <= mm <= 12
	// 01 <= dd <= 31 : check month wise : create a map for month : day_count
	// check for leap year  :  yyyy%4==0 :- leap year
}

void solvecase()
{
	vector<vector<string>> logs = {{"user1", "09:00:00", "2021-01-01"}, {"user1", "13:00:00", "2021-01-01"}, {"user2", "14:00:00", "2021-01-01"}, {"user1", "09:00:00", "2021-01-02"}, {"user2", "21:00:00", "2021-01-01"}};
	vector<vector<string>> ans = findLoginCount(logs);
	for (auto &v : ans)
	{
		for (auto &y : v)
		{
			cout << y << " ";
		}
		cout << endl;
	}
}
int32_t main()
{
	fastIO;
	wtt
	solvecase();
}