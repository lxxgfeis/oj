/*
    https://leetcode-cn.com/problems/continuous-subarray-sum/
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        /*
        // f1: O(n^2)
        // 93/94 the last case TLE
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum % k == 0)
                {
                    return true;
                }
            }
        }
        return false;
        */

        // f2
        map<int, int> s;
        if (k == 0)
        {
            return true;
        }

        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int a = sum % k;
            if (i != 0 && a == 0)
            {
                return true;
            }
            auto iter = s.find(a);
            if (iter != s.end())
            {
                if (i - iter->second > 1)
                {
                    return true;
                }
            }
            else
            {
                s.insert({a, i});
            }
        }
        return false;
    }
};

int main()
{
    vector<int> v = {23, 2, 5};
    bool ret = Solution().checkSubarraySum(v, 3);
    printf("ret is %d\n", ret);
    return 0;
}