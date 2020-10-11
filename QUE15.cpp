// QUE15.cpp

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
int maxSumWithK(int a[], int n, int k)
{


	int maxarr[n];

	int csum = a[0];
	maxarr[0] = a[0];
	for (int i = 1 ; i < n ; i ++)
	{
		csum = max(a[i], csum + a[i]);
		maxarr[i] = csum;

	}

	int sum = 0;
	for (int i = 0; i < k; i++)
		sum += a[i];


	int result = sum;
	for (int i = k; i < n; i++)
	{

		sum = sum + a[i] - a[i - k];


		result = max(result, sum);


		result = max(result, sum + maxarr[i - k]);
	}
	return result;

}
int main() {
	fastIO
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0 ; i < n ; i++)
		{
			cin >> arr[i];
		}
		int k;
		cin >> k;
		cout << maxSumWithK(arr, n, k) << endl;

	}


	return 0;
}