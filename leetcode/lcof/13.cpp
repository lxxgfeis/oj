#define REP(i, a, b) \
    for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local! 
int visited[100][100];

// 剑指 Offer 13. 机器人的运动范围
class Solution {
private:
    int m,n,k;
private:
    int calc(int m) {
        int ans = 0;
        while(m/10) {
            ans += (m%10);
            m /= 10;
        }
        ans += m%10;
        return ans;
    }
    void dfs(int i, int j) {
        if (i<0 || j<0 || i>=m || j>=n) {
            return;
        }
        if (calc(i)+calc(j)>k || visited[i][j]) {
            return;
        }
        visited[i][j] = 1;
        dfs(i-1, j);
        dfs(i+1, j);
        dfs(i, j-1);
        dfs(i, j+1);
    }
public:
    int movingCount(int m, int n, int k) {
        this->m = m, this->n = n, this->k = k;
        memset(visited, 0, sizeof(visited));
        dfs(0,0);
        int ans = 0;
        REP(i,0,99) {
            REP(j,0,99) {
                if (visited[i][j]) ans++;
            }
        }
        return ans;
    }
};
