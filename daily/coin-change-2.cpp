/* 518
    https://leetcode-cn.com/problems/coin-change-2/
*/

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int dp[5001];
        dp[0] = 1;
        for (int i = 1; i < 5001; i++)
        {
            dp[i] = 0;
        }
        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = coins[i - 1]; j <= amount; j++)
            {
                dp[j] = (dp[j] + dp[j - coins[i - 1]]);
            }
        }
        return dp[amount];
    }
};