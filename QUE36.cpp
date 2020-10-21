// QUE36.cpp

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
class Solution {
public:
	int offerings(int n, int arr[]) {

		int dp[n + 1];

		for (int i = 0 ; i <= n ; i++)
		{
			dp[i] = 1;
		}


		for (int i = 1; i < n; i++)
		{
			if (arr[i] > arr[i - 1] && dp[i] <= dp[i - 1])
			{
				dp[i] = dp[i - 1] + 1;
			}
		}
		for (int i = n - 2 ; i >= 0 ; i--)
		{
			if (arr[i] > arr[i + 1] && dp[i] <= dp[i + 1])
			{
				dp[i] = dp[i + 1] + 1;
			}
		}
		int ans = 0;
		for (int i = 0 ; i < n ; i ++)
			ans += dp[i];

		return ans;

	}
};
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	return 0;
}