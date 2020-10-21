// QUE37.cpp

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
	string s;
	cin >> s;
	// cout << s << endl;
	int n = s.size();
	int lastidx[100000];

	for (int i = 0 ; i <= 10000  ; i++)
		lastidx[i] = -1;

	int dp[10000];
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 2 * dp[i - 1];

		if (lastidx[s[i - 1]] != -1)
		{
			dp[i] = dp[i] - dp[lastidx[s[i - 1]]];
		}

		lastidx[s[i - 1]] = (i - 1);
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