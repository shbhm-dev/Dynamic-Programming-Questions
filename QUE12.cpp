// QUE12.cpp

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
int contains(string dictionary[], string word, int size)
{


	for (int i = 0; i < size; i++)
		if (dictionary[i].compare(word) == 0)
			return true;
	return false;
}
bool solve()
{
	int n;
	cin >> n;
	string dict[n];

	for (int i = 0 ; i < n ; i ++)
		cin >> dict[i];

	string str;
	cin >> str;

	int sz = str.size();
	if (sz == 0)   return true;

	bool dp[10000] = {false};

	for (int i = 1 ; i <= sz ; i ++)
	{
		if (dp[i] == false && contains(dict, str.substr(0, i), n))
			dp[i] = true;



		if (dp[i] == true)
		{
			if (i == sz)
				return true;

			for (int j = i + 1; j <= sz; j++)
			{

				if (dp[j] == false && contains(dict, str.substr(i, j - i), n))
					dp[j] = true;

				if (j == sz && dp[j] == true)
					return true;

			}
		}

	}
	return false;




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
		cout << solve() << endl;;

	return 0;
}