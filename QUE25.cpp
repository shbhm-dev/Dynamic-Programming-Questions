// QUE25.cpp

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
	int n, k;
	cin >> n >> k;

	int dp[n + 1][k + 1];


	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int i = 0; i <= k; i++)
		dp[0][k] = 0;

	for (int i = 1; i <= n ; i++)
	{
		for (int j = 1; j <= k ; j++)
		{
			if (j == 1 || i == j)
				dp[i][j] = 1;
			else
				dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	cout << dp[n][k] << endl;
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