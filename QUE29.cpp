// QUE29.cpp

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
	int n;
	cin >> n;
	int arr[10000];
	for (int i = 0 ; i < n ; i++)
		cin >> arr[i];

	int dec[10000] = {0};
	int inc[10000] = {0};

	dec[0] = arr[0];
	inc[0] = arr[0];
	int flag = 0;
	for (int i = 1; i < n ; i++)
	{
		for (int j = 0; j < i ; j++)
		{
			if (arr[j] > arr[i])
			{
				dec[i] = max(dec[i], inc[j] + arr[i]);
				flag = 1;
			} else if (arr[j] < arr[i] && flag == 1)
			{
				inc[i] = max(inc[i], dec[j] + arr[i]);
			}

		}
	}
	int ans = INT_MIN;
	for (int i = 0 ; i < n ; i ++)
	{
		ans = max(ans, max(inc[i], dec[i]));
	}
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