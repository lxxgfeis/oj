#define MP make_pair
#define REP(i, a, b) for(int i=a; i<=b; i++)
// 剑指 Offer 10- I. 斐波那契数列
class Solution {
private:
    unordered_map<int, int> myMap;

public:
    int fib(int n) {
        if (n==0) {
            myMap.insert(MP(0,0));
        } else if (n == 1) {
            myMap.insert(MP(1,1));
        }
        auto got = myMap.find(n);
        if (got != myMap.end()) {
            return got->second;
        } 
        REP(i, 2, n) {
            myMap.insert(MP(i, (fib(n-1)+fib(n-2))%1000000007));
        }
        return myMap[n];
    }
};
