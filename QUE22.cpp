// QUE22.cpp

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



	int minRemoval(int arr[], int n)
	{
		sort(arr, arr + n);
		long  int ans = INT_MAX;
		for (int i = 0 ; i < n; i ++)
		{
			ans = min( ans , i + ( n - (upper_bound(arr + i + 1 , arr + n , arr[i] * 2) - arr) ) );

		}
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