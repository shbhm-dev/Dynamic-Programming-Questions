// QUE11.cpp

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
int solve(int arr[], int n, int i, int j)
{
	if (i > j)
		return 0;

	if (i == j)
	{
		return arr[i];
	}
	if (dp[i][j] != -1)
		return dp[i][j];

	int x =  arr[i] + min(solve(arr, n, i + 2, j), solve(arr, n, i + 1, j - 1));
	int y = arr[j] + min(solve(arr, n, i + 1, j - 1), solve(arr, n, i, j - 2));

	return dp[i][j] = max(x, y);

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
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0 ; i < n ; i ++)
			cin >> arr[i];

		memset(dp, -1, sizeof dp);

		cout << solve(arr, n, 0, n - 1) << endl;
	}

	return 0;
}