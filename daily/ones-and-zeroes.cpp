/* 474
    https://leetcode-cn.com/problems/ones-and-zeroes/
*/

class Solution {
public:
    int count0(string& s) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i]=='0') {
                ans++;
            }
        }
        return ans;
    }

    int max(int i, int j) {
        return i>j?i:j;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101][601];
        int cnt0arr[601];        
        for(int i = 0; i<strs.size(); i++) {
            cnt0arr[i] = count0(strs[i]);
        }

        // try init dp
        if (1) {
            for(int i=0;i<101;i++) {
                for(int j=0;j<101;j++) {
                    for(int k=0;k<601;k++) {
                        dp[i][j][k] = 0;
                    }
                }
            }
        }

        for(int i=0;i<=m;i++) { // 0
            for(int j=0;j<=n;j++) { // 1
                for(int k=0;k<strs.size();k++) {
                    int c0 = cnt0arr[k];
                    int c1 = strs[k].length() - c0;
                    if(k==0) {
                        if(c0<=i && c1<=j) {
                            dp[i][j][k] = 1;
                        } 
                    }else if (i<c0 || j<c1) {
                        dp[i][j][k]=dp[i][j][k-1];
                    } else {
                        dp[i][j][k]= max(dp[i][j][k-1], dp[i-c0][j-c1][k-1]+1);
                    }
                }
            }
        }
        return dp[m][n][strs.size()-1];
    }
};