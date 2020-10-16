// QUE26.cpp

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
float solve(int row, int col, float k)
{

	if (col > row)
		return 0.0;

	float capacity[row * (row + 1) / 2 + 1]; // no of glasses upto row'th row;

	memset(capacity, 0, sizeof capacity);

	int idx = 0;
	capacity[idx] = k;

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= i ; j++, idx++)
		{
			k = capacity[idx];

			if (k >= 1.0f)
			{
				capacity[idx] = 1.0f;
			} else capacity[idx] = k;

			k = (k >= 1.0f) ? (k - 1) : 0.0f;

			capacity[idx + i ] += k / 2;
			capacity[idx + i + 1] += k / 2;


		}
	}
	return capacity[row * (row - 1) / 2 + col - 1];

}
int main() {
	fastIO


	int t;
	cin >> t;
	while (t--)
	{
		float k;
		int row, col;
		cin >> k >> row >> col;
		cout << solve(row, col, k) << endl;;
	}

	return 0;
}