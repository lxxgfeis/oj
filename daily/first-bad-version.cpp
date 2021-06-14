/* 278
 *  https://leetcode-cn.com/problems/first-bad-version/
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lower = 1, higher = n;
        int pivot;
        while(lower<=higher) {
            pivot = lower + (higher-lower)/2;
            int g = isBadVersion(pivot);
            if(g) {
                if(pivot > 1) {
                    if(!isBadVersion(pivot-1)) {
                        return pivot;
                    }
                } else {
                    return pivot;
                }
                higher = pivot -1;
            } else {
                lower = pivot +1;
            }
        }
        return pivot;
    }
};
