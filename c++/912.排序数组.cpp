/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105235443
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 计数排序，统计每个数出现几次
        // 最后依次压入vector
        // 时间复杂度O(n)
        const int offset = 50000;
        const int maxnum = offset * 2;
        int tmp[100000 + 5];
        memset(tmp, 0, sizeof(tmp));
        for (auto& num : nums) {
            ++tmp[num + offset];
        }

        vector<int> ans;
        ans.reserve(nums.size());   // 提前分配内存
        for (int i = 0; i <= maxnum; ++i) {
            while (tmp[i] > 0) {
                --tmp[i];
                ans.push_back(i - offset);
            }
        }

        return ans;
    }
};
// @lc code=end
