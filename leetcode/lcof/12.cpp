#define PB push_back
#define REP(i, a, b) \
    for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local! 

class Solution {
private:
    int m, n;

private:
    // Notice: string传递引用！
    bool dfs(vector<vector<char>>& board, int x, int y, int level, string& word) {
        // printf("level %d, (%d, %d), (%d, %d)\n", level, x, y, m, n);
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != word[level]) {
            return false;
        }
        if (level == word.size()-1) {
            return true;
        }
        // 无需维护visited这样的额外状态信息
        board[x][y] = '\0';  // Important: 很巧妙
        // 依次对上下左右4个元素进行dfs
        level+=1;
        bool ans = (dfs(board, x-1, y, level, word) ||
        dfs(board, x+1, y, level, word) ||
        dfs(board, x, y-1, level, word) ||
        dfs(board, x, y+1, level, word));
        // 回溯时，重置访问标记
        board[x][y] = word[level-1];
        return ans;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        // 依次对每个元素做dfs
        m = board.size();
        if (m > 0) {
            n = board[0].size();
        }
        REP (i, 0, m-1) {
            REP (j, 0, n-1) {
               if (dfs(board, i, j, 0, word)) {
                   return true;
               }
            }
        }
        return false;
    }
};
