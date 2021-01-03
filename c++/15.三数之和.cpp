/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/112135087
 */

// @lc code=start

#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());    // 排序，控制结果集三个数从小到大排列
        vector<vector<int>> res;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {  // 控制第一个数不重复
                continue;
            }
            int j = i + 1, k = len - 1;
            while (j < k) {
                int calc = nums[i] + nums[j] + nums[k];
                if (j > i + 1 && nums[j] == nums[j - 1]) {  // 控制第二个数不重复
                    ++j;
                } else if (k < len - 1 && nums[k] == nums[k + 1]) {  // 控制第三个数不重复
                    --k;
                } else if (calc > 0) {  // 求和大于0，在第一个数不变的情况下，意味着第三个数偏大
                    --k;
                } else if (calc < 0) {  // 求和小于0，在第一个数不变的情况下，意味着第二个数偏小
                    ++j;
                } else {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    res.push_back(tmp);
                    ++j;
                    --k;
                }
            }
        }

        return res;
    }
};
// @lc code=end
