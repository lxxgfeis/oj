#define REP(i, a, b) for(int i=a; i<=b; i++)

class Solution {
private:
    int sum = 0;
    int f1 = 1;
    int f2 = 2;

public:
    // 剑指 Offer 10- II. 青蛙跳台阶问题
    // 本质就是斐波拉契数列
    //  第一次跳有两种可能：
    //  1. 跳一个台阶，剩下n-1个台阶。这样可能的跳法有f(n-1)种
    //  2. 跳2个台阶，剩下n-2个台阶。这样可能的跳法有f(n-2)种
    // f(n) = f(n-1) + f(n-2)
    int numWays(int n) {
        if (n==0) {
            return 1;
        } else if (n==1) {
            return f1;
        } else if (n==2) {
            return f2;
        }
        REP(i, 3, n) {
            sum = (f1%1000000007 + f2%1000000007)%1000000007;
            f1 = f2;
            f2 = sum;
        }
        return sum%1000000007;
    }
};
