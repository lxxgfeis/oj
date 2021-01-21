class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    // 长度为n，且所有数字都小于n。那么可以将数字i放到位置i上
    // 如果位置i上已经是i了，那么i就是重复数字
    for (int i = 0; i < nums.size();) {
      if (nums[i] != i) {
        if (nums[nums[i]] == nums[i]) {
          return nums[i];
        } else {
          swap(nums[i], nums[nums[i]]);
        }
      }
      // 当位置i上是i，才能跳到下一个
      if (nums[i] == i) {
        i++;
      }
    }
    return -1;
  }
};
