// QUE8.cpp

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
int lcs(string s, string rev)
{	int n = s.size();

	int dp[1000][1000] = {0};

	for (int i = 0 ; i <= n ; i++)
	{
		for (int j = 0; j <= n ; j++)
		{

			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			} else if (s[i - 1] == rev[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}

		}
	}
	return dp[n][n];


}
void solve()
{
	string s;
	cin >> s;

	string rev = s;
	reverse(rev.begin(), rev.end());

	cout << lcs(s, rev);


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