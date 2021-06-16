/* 877
 * https://leetcode-cn.com/problems/stone-game/
 */

class Solution {
public:
    int mymax(vector<int>& piles, int& left, int& right) {
        int ret = 0;
        if (piles[left] > piles[right]) {
            ret = piles[left];
            left++;
        } else {
            ret = piles[right];
            right--;
        }
        return ret;
    }

    bool stoneGame(vector<int>& piles) {
        int alex = 0;
        int lee = 0;
        int lower=0, higher=piles.size()-1;
        int i=0;
        while(lower != higher) {
            // printf("left is %d, right is %d\n", lower, higher);
            int v = mymax(piles, lower, higher);
            if(i%2==0) {
                alex += v;
            } else {
                lee += v;
            }
        }
        return alex>lee;
    }
};
