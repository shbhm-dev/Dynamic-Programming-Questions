// QUE39.cpp
// Highway Billboard Problem

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
	int m;
	cin >> m;
	int n;
	cin >> n;
	int x[n + 1];
	int revenue[n + 1];
	for (int i = 0 ; i < n ; i++)
		cin >> x[i];

	for (int i = 0 ; i < n ; i++)
		cin >> revenue[i];

	int t;
	cin >> t;

	int dp[10000] = {0};

	dp[0] = revenue[0];
	for (int i = 1; i < n ; i++)
	{
		int maxx = max(dp[i], dp[i - 1]);
		for (int j = 0 ; j < i; j++)
		{
			if (x[j] < x[i] - t)
			{
				maxx = max(maxx, dp[j] + revenue[i]);
			}
		}
		dp[i] = maxx;
	}

	cout << dp[n - 1];



}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}