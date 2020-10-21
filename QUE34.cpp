// QUE34.cpp
// Count possible ways to construct buildings
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

	int countbuild = 1;
	int countspace = 1;
	int prevB;
	int prevS;
	for (int i = 2 ; i <= n ; i++)
	{
		prevB = countbuild;
		prevS = countspace;

		countbuild = prevS;
		countspace = prevS + prevB;
	}
	int ans = countbuild + countspace;

	cout << ans*ans << endl;

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