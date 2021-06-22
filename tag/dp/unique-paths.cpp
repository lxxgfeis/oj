/*
 * https://leetcode-cn.com/problems/unique-paths/
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101];
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        for(int i=1; i<=m; i++) {
            for(int j=2;j<=n;j++) {
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n];
    }
};
