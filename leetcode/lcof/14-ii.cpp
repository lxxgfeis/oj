typedef long long ll;
#define BIG (1000000007)
class Solution {
private:
    ll myPow(int a, int m) {
        ll ans = 1;
        while(m--) {
            ans = (ans%BIG * a)%BIG;
        }
        return (int)ans;
    }
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        ll ans;
        int a = n / 3;
        int b = n % 3;
        if (b == 0) {
            ans = myPow(3,a);
        } else if (b == 1) {
            // 拿个3分给1，成为2*2
            ans = (myPow(3, a-1)*4)%BIG;
        } else {
            ans = (myPow(3,a)*2)%BIG;
        }
        return (int)ans;
    }
};
