// QUE27.cpp

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
void noofsol(int arr[], int n, int rhs)
{

	int dp[10000] = {0};
	dp[0] = 1;
	for (int i = 0; i < n ; i++)
	{
		for (int j = arr[i] ; j <= rhs ; j++)
		{
			dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[rhs] << endl;
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
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0 ; i < n ; i ++)
			cin >> arr[i];

		int rhs;
		cin >> rhs;
		noofsol(arr, n, rhs);
	}

	return 0;
}
