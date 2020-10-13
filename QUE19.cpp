// QUE19.cpp

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
const int mod = 1e9 + 7;
class Solution {
public:
	// #define ll long long
	ll countStrings(int n) {
		ll arr[n];
		ll brr[n];
		arr[0] = 1;
		brr[0] = 1;
		for (int i = 1; i < n ; i++)
		{
			arr[i] = (arr[i - 1] + brr[i - 1]) % mod;
			brr[i] = arr[i - 1] % mod;
		}
		return (arr[n - 1] + brr[n - 1]) % mod;
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