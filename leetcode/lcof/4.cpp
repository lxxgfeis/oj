class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 本题关键是从左上角或者右下角开始找，因为每次比较可以排除一行或者一列
        // 时间复杂度将为O(m+n)

        int n = matrix.size();
        if (n <= 0) {
            return false;
        }
        int m = matrix[0].size();
        int i = 0;
        int j = m-1;
        for (;;) {
            if (i>=n || j<0) {
                break;
            }
            if (matrix[i][j]==target) {
                return true;
            } else if (matrix[i][j]<target) {
                // 15 小于 target，比较19
                i++;
            } else {
                // 15 大于 target，比较11
                j--;
            }
        }
        return false;
    }
};
