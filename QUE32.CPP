// QUE32.CPP

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
	string s;
	cin >> s;
	int ans = 0;
	int n = s.size();
	for (int i = 0 ; i <= n - 2 ; i++)
	{
		int l = i ;
		int r = i + 1;

		int lsum = 0;
		int rsum = 0;

		while (l >= 0 && r < n)
		{
			lsum += s[l] - '0';
			rsum += s[r] - '0';
			if (lsum == rsum)
			{
				ans = max(ans, r - l + 1);
			}
			l--;
			r++;
		}
	}
	cout << ans << endl;

}
int main() {
	fastIO

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}