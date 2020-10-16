// QUE24.cpp

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
	int findMaxLen(string st) {
		stack<int> s;
		s.push(-1);
		int ans = 0;
		for (int i = 0 ; i < st.size() ; i ++)
		{
			if (st[i] == '(')
			{
				s.push(i);
			} else
			{
				s.pop();

				if (!s.empty())
				{
					ans = max(ans, i - s.top());
				} else
					s.push(i);

			}

		}


		return ans;
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