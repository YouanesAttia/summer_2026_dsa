#include <iostream>
#include <vector>
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