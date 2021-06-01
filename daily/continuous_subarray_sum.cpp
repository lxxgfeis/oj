/*
    https://leetcode-cn.com/problems/continuous-subarray-sum/
*/

#include <vector>
using namespace ::std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
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
    };
};

int main()
{
    vector<int> v = {23, 2, 5};
    bool ret = Solution().checkSubarraySum(v, 3);
    return 0;
}