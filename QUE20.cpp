// QUE20.cpp

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
	bool isValid(int x, int y, int n)
	{
		return (x >= 0 and x < n and y >= 0 and y < n);
	}
	double findProb(int n, int start_x, int start_y, int steps)
	{
		int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
		int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

		double dp[n + 1][n + 1][steps + 1];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				dp[i][j][0] = 1;

		for (int s = 1 ; s <= steps; s++)
		{
			for (int i = 0 ; i < n ; i ++)
			{
				for (int j = 0 ; j < n ; j ++)
				{
					double prob = 0.0;

					for (int p = 0; p < 8 ; p++)
					{
						int newX = i + dx[p];
						int newY = j + dy[p];

						if (isValid(newX, newY, n))
						{
							prob += dp[newX][newY][s - 1] / 8.0;
						}
					}
					dp[i][j][s] = prob;
				}
			}
		}

		return dp[start_x][start_y][steps];

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