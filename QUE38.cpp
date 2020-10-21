// QUE38.cpp

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
bool getpainters(long long arr[], long long n, long long mid, int s)
{
	long long sum = 0;
	long long k = 1;
	for (long long i = 0 ; i < n; i++)
	{
		sum += arr[i];
		if (sum > mid)
		{
			sum = arr[i];
			k++;
		}
		if (k > s)
			return false;
	}
	return true;

}
void solve()
{
	long long n;
	cin >> n;
	long long arr[n + 1];
	long long sum = 0;
	long long maxele = -1e10;
	for (long long i = 0 ; i < n ; i ++)
		cin >> arr[i], sum += arr[i], maxele = max(maxele, arr[i]);

	long long k;
	cin >> k;
	if (k > n)
	{
		cout << "-1" << endl;
		return;

	}

	long long low = maxele;
	long long high = sum;
	long long ans = -1;
	while (low <= high)
	{
		long long mid = (low + high) >> 1;



		if (!getpainters(arr, n, mid, k))
		{
			low = mid + 1;

		} else
		{
			ans = mid;
			high = mid - 1;
		}


	}

	cout << ans << endl;

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
		solve();

	return 0;
}