// QUE16.cpp

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
int wildCard(string pattern, string str)
{
	int m = pattern.size();
	int n = str.size();

	bool dp[n + 1][m + 1];
	memset(dp, false, sizeof dp);
	dp[0][0] = true;
	for (int i = 1 ; i <= m; i++)
	{
		if (pattern[i - 1] == '*')
			dp[0][i] = dp[0][i - 1];
	}
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1; j <= m ; j++)
		{
			if (pattern[j - 1] == '*')
			{
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			} else if (pattern[j - 1] == str[i - 1] || pattern[j - 1] == '?')
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}

	return dp[n][m];
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	return 0;
}