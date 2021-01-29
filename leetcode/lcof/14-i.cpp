#define REP(i, a, b) for (int i=a; i<=b; i++)

// 剑指 Offer 14- I. 剪绳子
class Solution {
public:
    int max(int a, int b) {
        if (a>=b) return a;
        else return b;
    }
    // 找规律，猜对，就很离谱
    // 看了题解，拆出尽可能多3，乘积越大
    // 如果最后剩1，得拿一个3出来，分给1。因为2*2>1*3
    int cuttingRope(int n) {
        int ans = 0;
        REP(i,2,n) {
            int a = n/i;
            int b = n%i;
            if (b==0) {
                ans = max(ans, pow(a,i));
            } else {
                ans = max(ans, pow((a+1),b)*pow(a,(i-b)));
            }
            printf("%d,%d\n", i, ans);
        }
        return ans;
    }
};
