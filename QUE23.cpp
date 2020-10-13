// QUE23.cpp

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
	char keypad[4][3] = {{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'},
		{'*', '0', '#'}
	};

public:
	long long getCount(int n)
	{
		long long int dp[10][n + 1];


		int dx[] = {0, 0, -1, 0, 1};
		int dy[] = {0, -1, 0, 1, 0};

		for (int i = 0; i <= 9 ; i++)
		{
			dp[i][0] = 0 ;
			dp[i][1] = 1 ;
		}
		for (int k = 2; k <= n ; k++)
		{
			for (int i = 0 ; i < 4; i++)
			{
				for (int j = 0 ; j < 3; j++)
				{
					if (keypad[i][j] != '*' && keypad[i][j] != '#')
					{
						int num = keypad[i][j] - '0';

						dp[num][k] = 0;

						for (int x = 0 ; x < 5 ; x++)
						{
							int newx = i + dx[x];
							int newy = j + dy[x];

							if (newx >= 0 && newx <= 3 && newy >= 0 && newy <= 2 && keypad[newx][newy] != '*' && keypad[newx][newy] != '#' )
							{
								int newnum = keypad[newx][newy] - '0';
								dp[num][k] += dp[newnum][k - 1];
							}

						}

					}


				}
			}
		}
		long long  tc = 0;
		for (int i = 0; i <= 9; i++)
			tc += dp[i][n];

		return tc;

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