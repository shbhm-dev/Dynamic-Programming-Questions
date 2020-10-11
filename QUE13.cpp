// QUE13.cpp

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
int dp[1000][1000];
int solve(int n, int f)
{


	if (f == 1 || f == 0)
		return f;

	if (n == 1)
		return f;

	int minn = INT_MAX;
	int temp = INT_MIN;
	int i;

	if (dp[n][f] != -1)
		return dp[n][f];

	for (i = 1; i <= f; i++)
	{
		temp = max(solve(n - 1, i - 1), solve(n, f - i));

		if (temp < minn)
			minn = temp;
	}
	return dp[n][f] = (minn + 1);
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
		int n, f;
		cin >> n >> f;
		memset(dp, -1, sizeof dp);
		cout << solve(n, f) << endl;

	}


	return 0;
}