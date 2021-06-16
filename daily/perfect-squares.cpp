/* 279
    279. Perfect Squares
*/

class Solution {
public:
    int numSquares(int n) {
        int dp[10001];
        memset(dp, 0x3f, sizeof(dp));
        dp[0]=0;
        for (int i=1; i*i<=n; i++) {
            for(int j=i*i; j<=n; j++) {
                dp[j] = min(dp[j], dp[j-i*i]+1);
            }
        }
        return dp[n];
    }
};