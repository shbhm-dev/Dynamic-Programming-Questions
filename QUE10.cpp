// QUE10.cpp

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
	int n;
	cin >> n;

	int dp[1000] = {0};

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n ; i++)
	{
		int place = INT_MIN;
		for (int j = i - 1 ; j > 0 ; j--)
		{
			place = max(place, max(j * (i - j), j * dp[i - j]));
		}
		dp[i] = place;
	}

	cout << dp[n] << endl;
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