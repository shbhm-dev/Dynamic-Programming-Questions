// QUE4.cpp
class Solution {
public:

	int equalPartition(int n, int arr[])
	{
		int sum = 0 ;
		for (int i = 0 ; i < n ; i ++)
		{
			sum += arr[i];
		}
		if (sum % 2 != 0)
			return 0;

		bool dp[n + 1][sum + 1];

		sum = sum / 2;

		for (int i = 0 ; i <= n ; i ++)
		{
			for (int j = 0 ; j <= sum ; j++)
			{
				if (i == 0)
					dp[i][j] = false;
				else if (j == 0)
					dp[i][j] = true;
				else if (j - arr[i - 1] >= 0)
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
				else
					dp[i][j] = dp[i - 1][j];

			}
		}
		return dp[n][sum];

	}
};