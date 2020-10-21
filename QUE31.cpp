// QUE31.cpp

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
	string s;
	cin >> s;

	int dp[10000 + 1] = {0};

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (s[i - 1] > '0')
		{
			dp[i] = dp[i - 1];
		}
		if (s[i - 2] == '1' ||
		        (s[i - 2] == '2' && s[i - 1] < '7') )
			dp[i] += dp[i - 2];
	}
	cout << dp[n] << endl;

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