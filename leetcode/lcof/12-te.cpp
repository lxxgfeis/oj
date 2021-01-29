#define PB push_back
#define REP(i, a, b) \
    for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local! 

// 剑指 Offer 12. 矩阵中的路径, 最后一个case超时了
class Solution {
private:
    int m, n;
    vector<vector<bool>> visited;

private:
    bool dfs(vector<vector<char>>& board, int x, int y, int level, string word) {
        // printf("level: %d, (%d, %d)\n", level, x, y);
        if (board[x][y] != word[level]) {
            return false;
        }
        if (level == word.size()-1) {
            return true;
        }
        visited[x][y] = true;
        // 依次对上下左右4个元素进行dfs
        level+=1;
        if (shouldVisit(x, y, 1)) {
            // printf("dfs up\n");
            if (dfs(board, x-1, y, level, word)) return true;
        } 
        if (shouldVisit(x, y, 2)) {
            // printf("dfs down\n");
            if (dfs(board, x+1, y, level, word)) return true;
        }
        if (shouldVisit(x, y, 3)) {
            // printf("dfs left\n");
            if (dfs(board, x, y-1, level, word)) return true;
        }
        if (shouldVisit(x, y, 4)) {
            // printf("dfs right\n");
            if (dfs(board, x, y+1, level, word)) return true;
        }
        // 清除错误路径上的标记
        visited[x][y] = false;
        // cout<<"no left/right/up/down"<<endl;
        return false;
    }

    // pos为1，2，3，4，分别代表上下左右
    bool shouldVisit(int x, int y, int pos) {
        // printf("check(%d,%d), %d\n", x, y, pos);
        switch (pos) {
            case 1:
                // (x-1, y) 
                if (x>=1 && !visited[x-1][y]) return true;
                break;
            case 2:
                // (x+1, y)
                // if (x ==2 && y == 2 && pos == 2) {
                //     show();
                //     cout<<m<<n<<endl;
                // }
                // 错将m写成n了，导致调试了不少时间，wtf
                if (x<m-1 && !visited[x+1][y]) return true;
                break;
            case 3:
                // (x, y-1)
                if (y>=1 && !visited[x][y-1]) return true;
                break;
            case 4:
                // (x, y+1)
                if (y<n-1 && !visited[x][y+1]) return true;
                break;
        }
        return false;
    }
     
    void init(int x, int y) {
        this->m=x;
        this->n=y;
        // 查了一下二维vector对初始化
        visited.resize(x);
        REP(i, 0, x-1){
            visited[i].resize(y);
        }
        reset();
        // show();
    }

    void show() {
        REP(i, 0, m-1) {
            REP(j, 0, n-1) {
                cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void reset() {
        REP(i, 0, m-1) {
            vector<bool> v;
            REP(j, 0, n-1) {
                visited[i][j] = false;
            }
        }
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        init(board.size(), board[0].size());
        // 依次对每个元素做dfs，完成以后调用reset，再对下一个元素做dfs
        REP (i, 0, board.size()-1) {
            REP (j, 0, board[0].size()-1) {
               if (dfs(board, i, j, 0, word)) {
                   return true;
               }
               reset();
            }
        }
        return false;
    }
};
