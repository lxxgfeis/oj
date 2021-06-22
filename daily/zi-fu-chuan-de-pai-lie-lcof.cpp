/* lcof 38
 *  https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
 */
#include <cstring>
class Solution {
private:
    string remove(string s, int i) {
        string left = s.substr(0, i);
        string right = s.substr(i+1, s.size());
        return left+right;
    }
public:
    vector<string> permutation(string s) {
        set<string> ans;
        vector<string> uniq;
        if(s.size()==1) {
            uniq.push_back(s);
            return uniq;
        }
        for(int i = 0; i < s.size(); i++) {
            vector<string> tmp = permutation(remove(s, i));
            for(auto item : tmp) {
                ans.insert(s[i]+item);
            }
        }
        for(auto i : ans) {
            uniq.push_back(i);
        }
        return uniq;
    }
};
