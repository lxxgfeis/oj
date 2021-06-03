/* 525
    https://leetcode-cn.com/problems/contiguous-array/
*/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        /*
        // f1: TLE
        // O(n^2)
        // sum of subarray * 2 = length of subarray
        vector<int> sumVec;
        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if ((sum * 2 == i + 1) && (ans < i + 1))
            {
                ans = i + 1;
            }

            sumVec.push_back(sum);
        }
        int ans = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if ((sumVec[i] - sumVec[j]) * 2 == (i - j))
                {
                    if (ans < i - j)
                    {
                        ans = i - j;
                    }
                }
            }
        }
        return ans;
        */

        // f2: 把0当作-1
        // 求子数组和为0的最大长度
        // 前缀和+hash表

        unordered_map<int, int> m;
        int sum = 0;
        int ans = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int tmp = (nums[i] == 0) ? -1 : 1;
            sum += tmp;
            if ((sum == 0) && (ans < i + 1))
            {
                ans = i + 1;
            }
            auto iter = m.find(sum);
            if (iter != m.end())
            {
                if (i - iter->second > ans)
                {
                    ans = i - iter->second;
                }
            }
            else
            {
                m.insert({sum, i});
            }
        }
        return ans;
    }
};