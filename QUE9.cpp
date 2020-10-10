// QUE9.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long int
struct bridge {
	int north;
	int south;
};
bool comp(bridge a, bridge b)
{
	if (a.south == b.south)
	{
		return a.north < b.north;
	}

	return a.south < b.south;
}
void solve()
{
	int n;
	cin >> n;

	bridge arr[n];
	for (int i = 0 ; i < n ; i++)
	{
		cin >> arr[i].north;
	}
	for (int i = 0 ; i < n ; i++)
	{
		cin >> arr[i].south;
	}

	sort(arr, arr + n, comp);

	int dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i].north >= arr[j].north && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	int ans = INT_MIN;

	for (int i = 0 ; i < n ; i ++)
	{
		ans = max(ans, dp[i]);
	}

	cout << ans << endl << endl;;
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;

	while (t--)
	{
		solve();
	}

	return 0;
}