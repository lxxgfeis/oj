// 剑指 Offer 15. 二进制中1的个数
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0, ans = 0;
        for(;;) {
            if (count == 32) break;
            if (n&1) ans++;
            n = n>>1;
            count++;
        }
        return ans;
    }
};
