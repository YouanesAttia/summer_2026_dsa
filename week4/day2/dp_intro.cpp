#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int climbStairs(const int &n)
{
    int arr[n + 1];
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++)
        arr[i] = arr[i - 1] + arr[i - 2];
    arr[n];
}

int coinChange(const std::vector<int> &coins, const int amount)
{
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = amount + 1;
    }

    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0)
            {
                dp[i] = std::min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    if (dp[amount] == amount + 1)
        return -1;
    else
        return dp[amount];
}

int longestCommonSubsequence(const std::string &s1, const std::string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int arr[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        arr[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                arr[i][j] = 1 + arr[i - 1][j - 1];
            else
                arr[i][j] = std::max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    return arr[n][m];
}

int knapsack01(int weights[], int values[], int capacity)
{
}