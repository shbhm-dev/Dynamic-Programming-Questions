// QUE6.cpp

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
int dp[100][100][100];
int lcsOf3(string X, string Y, string Z, int i, int j, int k)
{

	if (i == -1 || j == -1 || k == -1)
		return 0;
	if (dp[i][j][k] != -1)
		return dp[i][j][k];

	if (X[i] == Y[j] && Y[j] == Z[k])
		return dp[i][j][k] = 1 + lcsOf3(X, Y, Z, i - 1, j - 1, k - 1);
	else
		return dp[i][j][k] = max(max(lcsOf3(X, Y, Z, i - 1, j, k),
		                             lcsOf3(X, Y, Z, i, j - 1, k)), lcsOf3(X, Y, Z, i, j, k - 1));


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

		memset(dp, -1, sizeof dp);
		int n, m, l;
		cin >> n >> m >> l;
		string a, b, c;
		cin >> a >> b >> c;
		cout << lcsOf3(a, b, c, n, m, l);

	}

	return 0;
}
