// QUE21.cpp

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
	int acount = 0;
	int bcount = 0;
	int ccount = 0;
	for (int i = 0 ; i < s.size(); i++)
	{
		if (s[i] == 'a')
		{
			acount = 1 + 2 * acount;
		} else if (s[i] == 'b')
		{
			bcount = acount + 2 * bcount;
		} else
		{
			ccount = bcount + 2 * ccount;
		}
	}
	cout << ccount << endl;

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