// QUE14.cpp

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
bool isInterleave(string A, string B, string C)
{
	int m = A.size();
	int n = B.size();
	bool dp[m + 1][n + 1];
	if ( (m + n) != C.size() )
		return false;

	memset(dp, 0, sizeof dp);

	for (int i = 0 ; i <= m ; i++)
	{
		for (int j = 0 ; j <= n ; j++)
		{

			if (i == 0 && j == 0)
			{
				dp[i][j] = true;
			}
			else if (i == 0)
			{
				if (B[j - 1] == C[j - 1])
					dp[i][j] = dp[i][j - 1];
			} else if (j == 0)
			{
				if (A[i - 1] == C[i - 1])
				{
					dp[i][j] = dp[i - 1][j];
				}
			} else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1])
			{

				dp[i][j] = dp[i - 1][j];
			} else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1])
			{
				dp[i][j] = dp[i][j - 1];
			}
			else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
			{
				dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
			}

		}

	}

	return dp[m][n];

}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	return 0;
}