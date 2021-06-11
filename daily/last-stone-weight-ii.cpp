/* 1049
    https://leetcode-cn.com/problems/last-stone-weight-ii/
*/
class Solution
{
public:
    // 0-1 pack
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int neg = sum / 2;
        int dp[neg + 1];
        for (int i = 0; i < neg + 1; i++)
        {
            dp[i] = 0;
        }
        for (auto weight : stones)
        {
            for (int i = neg; i > 0; i--)
            {
                if (weight <= i)
                {
                    dp[i] = max(dp[i], dp[i - weight] + weight);
                }
            }
        }
        return sum - 2 * dp[neg];
    }
};