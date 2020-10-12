// QUE17.cpp

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
ll gcd( ll a, ll b )
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd( b, a % b );
	}
}

int transfer(int n, int m, int d)
{


	int from = n;
	int to = 0;
	int step = 1;

	while (from != d || to != d)
	{
		int temp = min(from, m - to);

		from -= temp;
		to += temp;

		step++;

		if (from == d || to == d)
			break;

		if (from == 0)
		{
			from = n;
			step++;
		}
		if (to == m)
		{
			to = 0;
			step++;
		}

	}
	return step;

}
int solve()
{
	int n, m, d;
	cin >> m >> n >> d;
	if (m > n)
		swap(n, m);

	if (d % gcd(n, m) != 0 )
		return -1;

	if (d > n)
		return -1;

	return min(transfer(n, m, d), transfer(m, n, d));



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
		cout << solve() << endl;
	}
	return 0;
}