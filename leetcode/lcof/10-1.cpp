#define REP(i, a, b) for(int i=a; i<=b; i++)
// 剑指 Offer 10- I. 斐波那契数列
class Solution {
private:
    // 为啥相对于unordered_map，性能差距这么大？
    int sum = 0;
    int f1 = 0;
    int f2 = 1;

public:
    int fib(int n) {
        if (n==0) {
            return f1;
        } else if (n==1) {
            return f2;
        }
        REP(i, 2, n) {
            sum = (f1%1000000007 + f2%1000000007)%1000000007;
            f1 = f2;
            f2 = sum;
        }
        return sum%1000000007;
    }
};
