// QUE35.cpp
// unbounded knapsack
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


	int knapSack(int n, int w, int val[], int wt[])
	{

		int dp[w + 1] = {0};

		dp[0] = 0;
		for (int i = 1; i <= w ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				if (i - wt[j] >= 0)
					dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
			}
		}

		return dp[w];
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