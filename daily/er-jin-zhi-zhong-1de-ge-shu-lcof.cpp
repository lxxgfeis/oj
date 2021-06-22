/* lcof 15
 * https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/submissions/
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n) {
            if(n&0x1) {
                ans++;
            }
            n>>=1;
        }
        return ans;
    }
};
