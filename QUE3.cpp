// QUE3.cpp

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
void solve()
{
	int n, m;
	cin >> n >> m;
	int arr[1000][1000];
	for (int i = 0 ; i < n ; i ++)
	{
		for (int j = 0 ; j < m ; j ++)
		{
			cin >> arr[i][j];
		}
	}

	int dp[1000][1000];

	for (int i = 0 ; i < n ; i ++)
	{
		dp[i][0] = arr[i][0];
	}
	for (int j = 0 ; j < m ; j ++)
	{
		dp[0][j] = arr[0][j];
	}


	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (arr[i][j] == 1)
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			} else
			{
				dp[i][j] = 0;
			}
		}
	}
	int maxin = INT_MIN;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			maxin = max(maxin, dp[i][j]);
		}
	}

	cout << maxin << endl;



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
		solve();

	return 0;
}