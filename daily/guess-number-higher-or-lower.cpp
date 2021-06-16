/* 374
 *  https://leetcode-cn.com/problems/guess-number-higher-or-lower/
 */

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lower = 1, higher = n;
        while(lower<=higher) {
            int64_t pivot = ((int64_t)higher+lower)/2;
            int g = guess(pivot);
            if (g == 0) {
                return pivot;
            } else if (g == 1) {
                lower = pivot + 1;
            } else {
                higher = pivot - 1;
            }
        }
        return -1;
    }
};
