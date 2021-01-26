#define REP(i,a,b) for(int i=a;i<=b;i++)
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int last = numbers[numbers.size()-1];
        REP(i, 0, numbers.size()-1) {
            if (numbers[i]<last) {
                return numbers[i];
            }
        }
        return last;
    }
};
