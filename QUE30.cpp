// QUE30.cpp

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
const int mod = 1e9 + 7;
void solve()
{
	int n, m;
	cin >> n >> m;

	int dp[10000] = {0};

	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		if (i > m)
			dp[i] = dp[i - 1] % mod + dp[i - m] % mod;

		else if (i < m || i == 1)
			dp[i] = 1;

		else
			dp[i] = 2;
	}
	cout << dp[n] % mod << endl;

}
int main() {
	fastIO

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}