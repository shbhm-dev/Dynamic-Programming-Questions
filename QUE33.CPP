// QUE33.CPP

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
	int n, m;
	cin >> n;
	int arr[10000];
	for (int i = 0 ; i < n ; i ++)
		cin >> arr[i];

	cin >> m;
	int brr[10000];

	for (int i = 0 ; i < m ; i ++)
		cin >> brr[i];

	int dp[10000] = {0};

	for (int i = 0 ; i < n; i++)
	{
		int currlen = 0;
		for (int j = 0 ; j < m; j++)
		{
			if (arr[i] == brr[j])
			{
				if (dp[j] < currlen + 1)
				{
					dp[j] = currlen + 1;
				}
			}
			else if (arr[i] > brr[j])
			{
				if (dp[j] > currlen)
					currlen = dp[j];
			}

		}
	}

	int ans = 0 ;
	for (int i = 0 ; i < m ; i++)
		ans = max(ans, dp[i]);

	cout << ans << endl;

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