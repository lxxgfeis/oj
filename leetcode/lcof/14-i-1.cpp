class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int a = n / 3;
        int b = n % 3;
        if (b == 0) {
            return (int)pow(3,a);
        } else if (b == 1) {
            // 拿个3分给1，成为2*2
            return (int)pow(3, a- 1) * 4;
        } else {
            return (int)pow(3, a) * 2;
        }
    }
};
