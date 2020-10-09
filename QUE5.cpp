// QUE5.cpp

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
	int jump(vector<int>& arr) {
		int jump = 0;
		int maxReach = INT_MIN;
		int pos = 0;
		for (int i = 0 ; i < arr.size() - 1 ; i ++)
		{
			maxReach = max(maxReach, i + arr[i]);

			if (pos == i)
			{
				jump++;
				pos = maxReach;
			}
		}
		return jump;
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