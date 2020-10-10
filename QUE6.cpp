// QUE6.cpp

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

// int lcsOf3(string X, string Y, string Z, int i, int j, int k)
// {

//  if (i == -1 || j == -1 || k == -1)
//      return 0;
//  if (dp[i][j][k] != -1)
//      return dp[i][j][k];

//  if (X[i] == Y[j] && Y[j] == Z[k])
//      return dp[i][j][k] = 1 + lcsOf3(X, Y, Z, i - 1, j - 1, k - 1);
//  else
//      return dp[i][j][k] = max(max(lcsOf3(X, Y, Z, i - 1, j, k),
//                                   lcsOf3(X, Y, Z, i, j - 1, k)), lcsOf3(X, Y, Z, i, j, k - 1));


// }

void solve(string x, string y, string z, int m, int n, int o)
{
    int dp[101][101][101];

    for (int i = 0 ; i <= m ; i ++)
    {
        for (int j = 0 ; j <= n ; j ++)
        {
            for (int k = 0 ; k <= o ; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                {
                    dp[i][j][k] = 0;
                } else if (x[i - 1] == y[j - 1] && y[j - 1] == z[k - 1])
                {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else
                {
                    dp[i][j][k] = max(max(dp[i - 1][j][k],
                                          dp[i][j - 1][k]),
                                      dp[i][j][k - 1]);
                }
            }
        }
    }

    cout << dp[m][n][o] << endl;
}


int main() {
    fastIO

    int t;
    cin >> t;

    while (t--)
    {


        int n, m, l;
        cin >> n >> m >> l;
        string a, b, c;
        cin >> a >> b >> c;
        solve(a, b, c, n, m, l);

    }

    return 0;
}
